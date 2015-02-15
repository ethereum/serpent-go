package main

import (
	"fmt"

	"github.com/ethereum/serpent-go"
)

func main() {
	out, _ := serpent.Compile(`
def register(key, value):
    # Key not yet claimed
    if not self.storage[key]:
        self.storage[key] = value
        return(1)
    else:
        return(0)  # Key already claimed
	`)

	fmt.Printf("%x\n", out)
}
