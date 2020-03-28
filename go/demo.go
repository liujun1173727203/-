package main

import (
	"crypto/md5"
	"crypto/rand"
	"encoding/base64"
	"fmt"
	"html/template"
	"io"
	"net/http"
	"net/url"
	"os"
	"runtime"
	"strconv"
	"strings"
	"sync"
	"time"
	// "github.com/jinzhu/gorm"
	// _ "github.com/jinzhu/gorm/dialects/sqlite"
)

//Product --
// type Product struct{
// 	gorm.Model
// 	Code string
// 	Price uint
// }
//Manager --
type Manager struct {
	cookieName  string
	lock        sync.Mutex
	provider    Provider
	maxlifetime int64
}

//Session --
type Session interface {
	Set(key, value interface{}) error //set session value
	Get(key interface{}) interface{}  //get session value
	Delete(key interface{}) error     //delete session value
	SessionID() string                //back current sessionID
}

//Provider --
type Provider interface {
	SessionInit(sid string) (Session, error)
	SessionRead(sid string) (Session, error)
	SessionDestroy(sid string) error
	SessionGC(maxLifeTime int64)
}

var provides = make(map[string]Provider)

// Register makes a session provide available by the provided name.
// If Register is called twice with the same name or if driver is nil,
// it panics.
func Register(name string, provider Provider) {
	if provider == nil {
		panic("session: Register provide is nil")
	}
	if _, dup := provides[name]; dup {
		panic("session: Register called twice for provide " + name)
	}
	provides[name] = provider
}

//NewManager --
func NewManager(provideName, cookieName string, maxlifetime int64) (*Manager, error) {
	provider, ok := provides[provideName]
	if !ok {
		return nil, fmt.Errorf("session: unknown provide %q (forgotten import?)", provideName)
	}
	return &Manager{provider: provider, cookieName: cookieName, maxlifetime: maxlifetime}, nil

}

//SessionID --
func (manager *Manager) SessionID() string {
	b := make([]byte, 32)
	if _, err := io.ReadFull(rand.Reader, b); err != nil {
		return ""
	}
	return base64.URLEncoding.EncodeToString(b)
}

// var globalSessions *session.Manager

//SessionStart --s
func (manager *Manager) SessionStart(w http.ResponseWriter, r *http.Request) (session Session) {
	manager.lock.Lock()
	defer manager.lock.Unlock()
	cookie, err := r.Cookie(manager.cookieName)
	if err != nil && cookie.Value == "" {
		sid := manager.SessionID()
		session, _ = manager.provider.SessionInit(sid)
		cookie := http.Cookie{Name: manager.cookieName, Value: url.QueryEscape(sid), Path: "/", HttpOnly: true, MaxAge: int(manager.maxlifetime)}
		http.SetCookie(w, &cookie)
	} else {
		sid, _ := url.QueryUnescape(cookie.Value)
		session, _ = manager.provider.SessionRead(sid)
	}
	return
}

//init --
// func init() {
// 	globalSessions, _ = NewManager("memory", "gosessionid", 3600)
// }
func main() {

	// mux := &MyMux{}
	// http.ListenAndServe(":9090", mux)

	// http.HandleFunc("/upload", upload)
	http.HandleFunc("/login", login)
	http.HandleFunc("/hello", WebDemo1)
	// err := http.ListenAndServe(":9090", nil)
	// if err != nil {
	// 	log.Fatal("ListenAndServe", err)
	// }
	//信仰
	// fmt.Printf("hello word")

	//切片与字符转化
	// s := "hello"
	// c := []byte(s)
	// c[0] = 'o'
	// s = s[:1] + "lj" + s[1:]
	// s2 := string(c)
	// fmt.Printf("\n%s\n%s", s, s2)

	//error创建
	// err := errors.New("find error")
	// if err != nil {
	// 	fmt.Print(err)
	// }

	//defer 延迟
	// for i := 0; i < 5; i++ {
	// 	defer fmt.Printf("\n%d", i)
	// }

	//重写
	// Bob := Human{"Bob", 39, "000-7777-XXX"}
	// fmt.Println("\nThis Human is : ", Bob)
	// 不生效
	// 	var a float64 =3.2
	// v:=reflect.ValueOf(&a)
	// p:=v.Elem()
	// p.SetFloat(1.1)
	// fmt.Println("\n", a)
	// go Say("world")
	// go Say("me")
	// Say("hello")

	//channel通信机制
	// channel类型。定义一个channel时，
	// 也需要定义发送到channel的值的类型。
	// 注意，必须使用make 创建channel：
	// a := []int{1, 2, 3, 4, 5, 5}
	// c := make(chan int)
	// go sum(a[:len(a)/2], c)
	// go sum(a[len(a)/2:], c)
	// x, y := <-c, <-c
	// fmt.Println(x, y, x+y)

	//阻塞
	// a1 := make(chan int, 2)
	// a1 <- 1
	// a1 <- 2
	// fmt.Println(<-a1)
	// fmt.Println(<-a1)

	c := make(chan int)
	quit := make(chan int)
	go func() {
		for i := 0; i < 10; i++ {
			fmt.Println(<-c)
		}
		quit <- 0
	}()
	fibonacci(c, quit)
	fmt.Println("start")
	go gorun()
	go gorun1()
	for {
	}
}

//fibonacci --
func fibonacci(c, quit chan int) {
	x, y := 1, 1
	for {
		select {
		case c <- x:
			x, y = y, x+y
		case <-quit:
			fmt.Println("quit")
			return
		}
	}
}

//f1 --
func gorun() {
	xd := 0
	for {
		xd++
		fmt.Println("执行第：", xd, "次")
		time.Sleep(1 * time.Second * 1)
	}

}

//f2 --
func gorun1() {
	xd := 0
	for {
		xd++
		fmt.Println("执行第：", xd, "次")
		time.Sleep(1 * time.Second * 1)
	}
}

//Say --
func Say(s string) {
	for i := 0; i < 5; i++ {
		runtime.Gosched()
		fmt.Println(s)
	}
}

//sum --
func sum(a []int, c chan int) {
	total := 0
	for _, v := range a {
		total += v
	}
	c <- total
}

//Human --
type Human struct {
	name  string
	age   int
	phone string
}

// 通过这个方法 Human 实现了 fmt.Stringer
func (h Human) String() string {
	return "❰" + h.name + " - " + strconv.Itoa(h.age) + " years -  ✆ " + h.phone + "❱"
}

//WebDemo --
func WebDemo(w http.ResponseWriter, r *http.Request) {
	r.ParseForm()
	fmt.Println(r.Form)
	fmt.Println("path", r.URL.Path)
	fmt.Println("scheme", r.URL.Scheme)
	fmt.Println(r.Form["url_long"])
	for k, v := range r.Form {
		fmt.Println("key:", k)
		fmt.Println("val:", strings.Join(v, ","))
	}
	fmt.Fprintf(w, "hello world")
}

//WebDemo1 --
func WebDemo1(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "xiaoer")
}

//login --
func login(w http.ResponseWriter, r *http.Request) {
	// sess := globalSessions.SessionStart(w, r)
	// r.ParseForm()
	// if r.Method == "GET" {
	// 	t, _ := template.ParseFiles("login.html")
	// 	w.Header().Set("Content-Type", "text/html")
	// 	t.Execute(w, sess.Get("username"))
	// } else {
	// 	sess.Set("username", r.Form["username"])
	// 	http.Redirect(w, r, "/", 302)
	// }
}

//MyMux --
type MyMux struct{}

//upload --
func upload(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		crutime := time.Now().Unix()
		h := md5.New()
		io.WriteString(h, strconv.FormatInt(crutime, 10))
		token := fmt.Sprintf("%x", h.Sum(nil))
		t, _ := template.ParseFiles("file.html")
		t.Execute(w, token)
	} else {
		r.ParseMultipartForm(32 << 20)
		file, handle, err := r.FormFile("file")
		if err != nil {
			fmt.Println(err)
			return
		}
		defer file.Close()
		fmt.Fprintf(w, "%v", handle.Header)
		os.Mkdir("./test/", 0777)
		f, err := os.OpenFile("./test/"+handle.Filename, os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			fmt.Println(err)
			return
		}
		defer f.Close()
		io.Copy(f, file)
	}
}
