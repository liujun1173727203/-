package main

import (
	"Dsession/session"
	"fmt"
	"log"
	"net/http"
)

var globalSessions *session.Manager

func init() {
	var err error
	globalSessions, err = session.NewSessionManager("memory", "goSessionid", 3600)
	if err != nil {
		fmt.Println(err)
		return
	}
	go globalSessions.GC()
	fmt.Println("fd")
}

func sayHelloHandler(w http.ResponseWriter, r *http.Request) {

	cookie, err := r.Cookie("name")
	if err == nil {
		fmt.Println(cookie.Value)
		fmt.Println(cookie.Domain)
		fmt.Println(cookie.Expires)
	}
	fmt.Fprintf(w, "Hello world!\n") //这个写入到w的是输出到客户端的
}
func login(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintln(w, "Aa")
	sess := globalSessions.SessionStart(w, r)
	val := sess.Get("username")
	if val != nil {
		fmt.Println(val)
	} else {
		sess.Set("username", "jerry")
		fmt.Println("set session")
	}
}
func loginOut(w http.ResponseWriter, r *http.Request) {
	//销毁
	globalSessions.SessionDestroy(w, r)
	fmt.Println("session destroy")
}

func main() {
	http.HandleFunc("/", sayHelloHandler) //	设置访问路由
	http.HandleFunc("/login", login)
	http.HandleFunc("/loginout", loginOut) //销毁
	log.Fatal(http.ListenAndServe(":8080", nil))
}

// func main() {
// 	b := make([]byte, 32)
// 	s := "s%23%40%24%40%40%24s"
// 	if _, err := io.ReadFull(rand.Reader, b); err != nil {
// 		fmt.Printf("")
// 	}
// 	fmt.Println(b)
// 	fmt.Println(base64.URLEncoding.EncodeToString(b))
// 	fmt.Println(url.QueryUnescape(s))
// }
