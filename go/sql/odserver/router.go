package odserver

import "net/http"

//OdServer --
type OdServer struct {
	router MethodMaps
}

//IOdServer --
type IOdServer interface {
	GET(url string, f HandlerFunc)
	POST(url string, f HandlerFunc)
	PUT(url string, f HandlerFunc)
	DELETE(url string, f HandlerFunc)
}

//HandlerMapped --
type HandlerMapped struct {
	f HandlerFunc
}

//HandlerFunc --
type HandlerFunc func(w http.ResponseWriter, req *http.Request)

//Default --
func Default() *OdServer {
	return &OdServer{
		router: NewRouter(),
	}
}

//GetMapping --
func (m MethodMaps) GetMapping(url string) {
	o.router = url
}

//ServeHTTP --
func (o *OdServer) ServeHTTP(w http.ResponseWriter, req *http.Request) {
	o.doHandler(w, req)
}

//doHandler --
func (o *OdServer) doHandler(w http.ResponseWriter, req *http.Request) {
	switch req.Method {
	case http.MethodGet:
		{
			if hm, ok := o.router.GetMapping(req.URL.RequestURI()); ok {
				hm.f(w, req)
			}
		}
	case http.MethodPost:

		{
			if hm, ok := o.router.GetMapping(req.URL.RequestURI()); ok {
				hm.f(w, req)
			}
		}
	case http.MethodPut:
		{
			if hm, ok := o.router.GetMapping(req.URL.RequestURI()); ok {
				hm.f(w, req)
			}
		}
	case http.MethodDelete:
		{
			if hm, ok := o.router.GetMapping(req.URL.RequestURI()); ok {
				hm.f(w, req)
			}
		}
	default:
		{

		}
	}
}

//GET --
func (o *OdServer) GET(url string, f HandlerFunc) {
	o.router.GetAdd(url, HandlerMapped{f: f})
}

//POST --
func (o *OdServer) POST(url string, f HandlerFunc) {
	o.router.PostAdd(url, HandlerMapped{f: f})
}

//DELETE --
func (o *OdServer) DELETE(url string, f HandlerFunc) {
	o.router.DeleteAdd(url, HandlerMapped{f: f})
}

//PUT --
func (o *OdServer) PUT(url string, f HandlerFunc) {
	o.router.PutAdd(url, HandlerMapped{f: f})
}

const (
	GET = iota
	POST
	PUT
	DELETE
	CONNECTIBNG
	HEAD
	OPTIONS
	PATCH
	TRACE
)

//NewRouter --
func NewRouter() MethodMaps {
	return []handler{
		GET:    make(handler),
		POST:   make(handler),
		PUT:    make(handler),
		DELETE: make(handler),
	}
}

//MethodMaps --
type MethodMaps []handler

//handler --
type handler map[string]HandlerMapped

//GetAdd --
func (m MethodMaps) GetAdd(url string, mapped HandlerMapped) {
	if _, ok := m.GetMapping(url); ok {
		panic("dulicate url with get method")
	}
	m[GET].SetUrl(url, mapped)
}

//PostAdd --
func (m MethodMaps) PostAdd(url string, mapped HandlerMapped) {
	if _, ok := m.GetMapping(url); ok {
		panic("dulicate url with get method")
	}
	m[POST].SetUrl(url, mapped)
}

//DeleteAdd --
func (m MethodMaps) DeleteAdd(url string, mapped HandlerMapped) {
	if _, ok := m.GetMapping(url); ok {
		panic("dulicate url with get method")
	}
	m[DELETE].SetUrl(url, mapped)
}

//PutAdd --
func (m MethodMaps) PutAdd(url string, mapped HandlerMapped) {
	if _, ok := m.GetMapping(url); ok {
		panic("dulicate url with get method")
	}
	m[PUT].SetUrl(url, mapped)
}

//SetUrl --
func (h handler) SetUrl(url string, mapped HandlerMapped) {
	h[url] = mapped
}
