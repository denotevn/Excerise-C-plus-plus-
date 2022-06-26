package main

import (
	"fmt"
)

func main() {
	var number float32
	fmt.Print("Enter a floating point number:\n")
	fmt.Scanln(&number)
	fmt.Print("\nConverted integer:\n", number)
}
