package main

import (
    "flag"
    "fmt"
)

var port string

func init() {
    flag.StringVar(&port, "port", "", "Port to listen on")
    flag.Parse()
}

func main() {
    fmt.Println("Using port:", port)
}
