#include "sys/socket.h"
#include <arpa/inet.h>
#include <unistd.h>
#include "iostream"
#include "string.h"

#define BUFFER_SIZE 1024

class Server
{
private:
    int server_fd ,new_sock;
    sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char *message = "Hello from server";

public:
    Server(/* args */);
    int Server_Create_Socket(int IP_protocol = AF_INET,int network = SOCK_STREAM ,int port = 8080);
    int Server_Bind_Socket();
    int Server_Listen(int queue = 3);
    int Server_Accept();
    int Server_recv();
    int Server_send();
    ~Server();
};