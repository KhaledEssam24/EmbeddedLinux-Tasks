#include "Client.hpp"
#include <iostream>
#include <string.h>

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
    if (inet_pton(IP_protocol, "192.168.1.2", &addr.sin_addr) <= 0) {
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

int Client::Client_Recv(){
    // Clear the buffer to remove old data
    memset(buffer, 0, BUFFER_SIZE);

    int recv_len = recv(sock , buffer ,BUFFER_SIZE , 0);
    if(recv_len < 0){
        std::cout << "Invalid Message from server: " << Client_Get_Msg() << std::endl;
        return -1;
    }
    else if (recv_len == 0) {
        std::cout << "Connection closed by server." << std::endl;
        return 0; 
    } 
    std::cout << "Message received from server: " << Client_Get_Msg() << std::endl;

    return recv_len;
}

std::string Client::Client_Get_Msg(){
    return std::string(buffer);
}
