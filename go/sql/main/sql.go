package main

import (
	"fmt"
	"net/http"
	"sql/dd"

	"github.com/jinzhu/gorm"
)

//Db --
var Db *gorm.DB

//Add 添加测试
func Add(w http.ResponseWriter, r *http.Request) {
	name := r.PostFormValue("name")
	pass := r.PostFormValue("passwod")
	fmt.Println(name, pass)
	if err := Db.Create(&dd.Test{
		Name:     name,
		Password: pass,
	}).Error; err != nil {
		fmt.Println(err)
	}
}

func main() {
	db := dd.Init()
	Db = db
	http.HandleFunc("/login", Add)
	if err := http.ListenAndServe(":8008", nil); err != nil {
		fmt.Println(err)
	}
	defer db.Close()
}
