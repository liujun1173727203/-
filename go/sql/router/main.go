package main

import (
	"fmt"
	"log"
	"net/http"
	"net/url"
	"regexp"
	"strings"
	"sync"
)

//simMux 路由器
type simMux struct {
	mu     sync.RWMutex
	m      map[string][]HandlerStruc
	static map[string]string
}

//HandlerStruc 路由结构
type HandlerStruc struct {
	regex   *regexp.Regexp
	params  map[int]string
	handler Handler
}

//Handler 响应函数
type Handler func(http.ResponseWriter, *http.Request)

//New 创建路由器
func New() *simMux {
	return &simMux{
		sync.RWMutex{},
		make(map[string][]HandlerStruc),
		make(map[string]string),
	}
}

//AddStatic 静态路由
func (sMux *simMux) AddStatic(prefix, path string) bool {
	if len(prefix) == 0 || len(path) == 0 {
		return false
	}
	_, exist := sMux.static[prefix]
	if exist {
		panic("simMux:duplicate static prefix \"" + prefix + "\"")
	}
	sMux.static[prefix] = path
	return true
}

//add 动态路由
func (sMux *simMux) add(method string, pattern string, handler Handler) bool {
	if len(pattern) == 0 || handler == nil {
		return false
	}
	sMux.mu.Lock()
	defer sMux.mu.Unlock()
	params := make(map[int]string)
	var patterns []string
	pos := 0
	arr := strings.Split(pattern, "/")
	for _, v := range arr {
		if strings.HasPrefix(v, ":") {
			index := strings.Index(v, "(")
			if index != -1 {
				patterns = append(patterns, v[index:])
				params[pos] = v[1:index]
				pos++
				continue
			}
		}
		patterns = append(patterns, v)
	}
	regex, err := regexp.Compile(strings.Join(patterns, "/"))
	if err != nil {
		panic("simMux:wrong pattern \"" + pattern + "\"")
	}
	sMux.m[method] = append(sMux.m[method], HandlerStruc{regex, params, handler})
	return true
}

//AddGet 注册get方法
func (sMux *simMux) AddGet(pattern string, handle Handler) bool {
	return sMux.add(http.MethodGet, pattern, handle)
}

//AddPost 注册Post方法
func (sMux *simMux) AddPost(pattern string, handle Handler) bool {
	return sMux.add(http.MethodPost, pattern, handle)
}

//AddPut 注册Put方法
func (sMux *simMux) AddPut(pattern string, handle Handler) bool {
	return sMux.add(http.MethodPut, pattern, handle)
}

//AddDelete 注册Delete方法
func (sMux *simMux) AddDelete(pattern string, handle Handler) bool {
	return sMux.add(http.MethodDelete, pattern, handle)
}

//ServeHTTP 路由分发
func (sMux *simMux) ServeHTTP(w http.ResponseWriter, req *http.Request) {

	//静态路由解析
	for prefix, path := range sMux.static {
		if strings.HasPrefix(req.URL.Path, prefix) {
			file := path + req.URL.Path[len(prefix):]
			http.ServeFile(w, req, file)
			return
		}
	}
	//动态路由解析
	if sMux.m[req.Method] == nil || len(sMux.m[req.Method]) == 0 {
		http.NotFound(w, req)
		return
	}
	path := req.URL.Path
	for _, handlerStruc := range sMux.m[req.Method] {
		if !handlerStruc.regex.MatchString(path) {
			continue
		}
		matches := handlerStruc.regex.FindStringSubmatch(path)
		if len(matches[0]) != len(path) {
			continue
		}
		if len(handlerStruc.params) > 0 {
			//组装请求参数
			values := req.URL.Query()
			for i, val := range matches[1:] {
				values.Add(handlerStruc.params[i], val)
			}
			req.URL.RawQuery = url.Values(values).Encode()
		}
		handlerStruc.handler(w, req)
		return
	}
	http.NotFound(w, req)
}

func main() {
	sMux := New()
	sMux.AddGet("/user/:id([0-9]+)/:name([a-z]+)", user)
	log.Println("server running...")
	log.Fatal(http.ListenAndServe("localhost:4001", sMux))
}
func user(writer http.ResponseWriter, req *http.Request) {
	fmt.Fprintln(writer, req.URL.Query())
}
