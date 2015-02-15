package main

import (
	"fmt"
	"os"

	"github.com/ethereum/serpent-go"
)

func main() {
	out, err := serpent.Compile(`
def register(key, value):
    # Key not yet claimed
    if not self.storage[key]:
        self.storage[key] = value
        return(1)
    else:
        return(0)  # Key already claimed
	`)
	if err != nil {
		fmt.Printf("%v\n", err)
	} else {
		fmt.Printf("%x\n", out)
	}
	os.Stdout.Sync()
}
