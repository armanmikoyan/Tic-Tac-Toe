#ifndef SOCKET_H
#define SOCKET_H

#endif //SOCKET_H
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <mutex>


class Socket {
public:


public:
    void wait();
    void act();

private:
    const int PORT = 8080;
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char* SERVER_ADDR = "127.0.0.1"; 
};




