#include "sys/socket.h"
#include <arpa/inet.h>
#include <unistd.h>
#include "iostream"
#include "string.h"

class Server
{

public:
    Server();
    ~Server();

    int Server_Create_Socket(int IP_protocol = AF_INET,int network = SOCK_STREAM ,int port = 8080);
    int Server_Bind_Socket();
    int Server_Listen(int queue = 3);
    int Server_Accept();
    int Server_is_accepted(){
        return new_sock;
    }
    int Server_send(const char *message);
    int Server_recv(char* buffer , int size = 2048);



private:
    int server_fd ,new_sock;
    bool is_accepted = false;
    sockaddr_in address;
    int addrlen = sizeof(address);

};
