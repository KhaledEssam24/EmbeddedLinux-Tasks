#include "Client.hpp"

// Client side C++ code
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

Client::Client(/* args */)
{
}

Client::~Client()
{
    close(sock);
}

int Client::Client_Create_Socket(int IP_protocol,int network ,int port){
    // Creating socket
    sock = socket(IP_protocol, network, 0);
    if (sock < 0) {
        std::cerr << "Socket creation error" << std::endl;
        return -1;
    }

    // Define the server address
    addr.sin_family = IP_protocol;
    addr.sin_port = htons(port);

    // Convert the server address to binary
    if (inet_pton(IP_protocol, "127.0.0.1", &addr.sin_addr) <= 0) {
        std::cerr << "Invalid address or address not supported" << std::endl;
        return -1;
    }
    return 0;
}

int Client::Client_Connect(){
    // Connect to the server
    if (connect(sock, reinterpret_cast<struct sockaddr *>(&addr), sizeof(addr)) < 0) {
        std::cerr << "Connection failed" << std::endl;
        return -1;
    }
    return 0;
}

int Client::Client_Send(){
    if(send(sock, message, sizeof(message), 0) < 0){
        return -1;
    }
    std::cout << "Message sent to server" << std::endl;
    return 0;
}

int Client::Client_Recv(){
    int recv_len = recv(sock , buffer ,BUFFER_SIZE , 0);
    if(recv_len > 0){
        return -1;
    }
    std::cout << "Message from server: " << buffer << std::endl;
    return 0;
}

int main(){
    Client client;
    client.Client_Create_Socket();
    client.Client_Connect();
    while (1)
    {
        client.Client_Send();
        client.Client_Recv();    
    }
    return 0;
}