Build the Docker image using ```docker build -t ebpfdrop .```
Run the container with the desired port specified: ```docker run -p <host_port>:<container_port> ebpfdrop <port>```. Replace ```<host_port>``` with the port on your host machine you want to map to the container port and ```<container_port>``` with the port configured in your program.
