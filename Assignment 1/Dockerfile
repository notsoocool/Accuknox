FROM golang:latest

WORKDIR /app

COPY . .
COPY go.mod /app/go.mod

RUN go mod download
RUN go get github.com/cilium/ebpf


RUN go build -o xdp_prog main.go

CMD ["/app/xdp_prog", "<PORT_NUMBER>"]
