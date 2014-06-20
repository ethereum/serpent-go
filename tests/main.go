package main

import (
	"fmt"
	"github.com/obscuren/serpent-go"
)

func main() {
	out := serpent.Compile(`
x = 248
while x > 1:
	if (x % 2) == 0:
		x = x / 2
	else:
		x = 3 * x + 1
	`)

	fmt.Println(out)
}
