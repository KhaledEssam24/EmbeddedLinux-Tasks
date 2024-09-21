#include "sys/socket.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

#define BUFFER_SIZE 1024
class Client
{
private:
    int sock = 0;
    sockaddr_in addr;
    const char *message = "Hello from client";
    char buffer[BUFFER_SIZE] = {0};

public:
    Client(/* args */);
    int Client_Create_Socket(int IP_protocol = AF_INET,int network = SOCK_STREAM ,int port = 8080);
    int Client_Connect();
    int Client_Recv();
    std::string Client_Get_Msg();
    ~Client();
};
