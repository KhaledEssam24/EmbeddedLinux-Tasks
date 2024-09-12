#include "Server.hpp"

Server::Server(/* args */)
{
}

Server::~Server()
{
    // Close the socket
    close(new_sock);
    close(server_fd);
}

int Server::Server_Create_Socket(int IP_protocol,int network ,int port){
    server_fd = socket(IP_protocol, network, 0);
    if (server_fd < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return -1;
    }

    // Define the server address
    address.sin_family = IP_protocol;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    return 0;
}

int Server::Server_Bind_Socket(){
    if (bind(server_fd,reinterpret_cast<struct sockaddr*>(&address),addrlen) < 0) {
        std::cerr << "Binding failed!" << std::endl;
        return -1;
    }
    return 0;
}

int Server::Server_Listen(int queue){
    // Listening for incoming connections
    if (listen(server_fd, queue) < 0) {
        std::cerr << "Listen failed" << std::endl;
        return -1;
    }
    std::cout << "Waiting for a connection..." << std::endl;
    return 0;
}

int Server::Server_Accept(){
    // Accept the incoming connection
    new_sock = accept(server_fd,reinterpret_cast<struct sockaddr*>(&address) , reinterpret_cast<socklen_t*>(&addrlen));
    if (new_sock < 0) {
        std::cerr << "Accept failed" << std::endl;
        return -1;
    }
    return 0;
}

int Server::Server_recv(){
    // Read the message from the client
    int valread = read(new_sock, buffer, BUFFER_SIZE);
    if (valread < 0) {
        std::cerr << "Failed to receive message" << std::endl;
        return -1;
    }
    std::cout << "Message from client: " << buffer << std::endl;
    return 0;

}

int Server::Server_send(){
    // Send a message back to the client
    if(send(new_sock, message, strlen(message), 0) < 0)
    {
        return -1;
    }
    std::cout << "Hello message sent" << std::endl;
    return 0;
}
