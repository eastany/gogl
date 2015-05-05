package clib

/*
#cgo LDFLAGS: -ldl
#include "test.h"
#include "dfont.h"
*/
import "C"

import (
	"unsafe"
	"fmt"
)

func Test(s string){
	p := C.CString(s)
	C.test(p)
}


func TestS() {
	var x = C.int(10)
	var y = C.CString("hello")
	var t C.struct_TestStruct
	t.x = x
	t.y = y
	defer C.free(unsafe.Pointer(y))
	result := C.test_struct(&t)
	fmt.Println(result)
}
