package serpent

// #cgo CXXFLAGS: -I. -Ilangs/ -std=c++0x -Wall -fno-strict-aliasing
// #cgo LDFLAGS: -lstdc++
//
// #include "cpp/api.h"
//
import "C"

import (
	"encoding/hex"
	"errors"
	"unsafe"
)

func Compile(code string) ([]byte, error) {
	var err C.int
	var cCode = C.CString(code)
	var cCompiled = C.compileGo(cCode, (*C.int)(unsafe.Pointer(&err)))
	var out = C.GoString(cCompiled)
	C.free(unsafe.Pointer(cCode))
	C.free(unsafe.Pointer(cCompiled))

	if err == C.int(1) {
		return nil, errors.New(out)
	}

	bytes, _ := hex.DecodeString(out)
	return bytes, nil
}
