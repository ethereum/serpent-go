package serpent

// #cgo CXXFLAGS: -std=c++0x -Wall -fno-strict-aliasing
// #cgo LDFLAGS: -lstdc++ -L/usr/local/lib -lserpent
//
// #include "cpp/api.h"
//
import "C"

func Compile(str string) string {
	out := C.compileGo(C.CString(str))

	return C.GoString(out)
}
