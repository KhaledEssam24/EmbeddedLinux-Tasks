#include "App.hpp"
#include <string>
#include <algorithm>
#include <iostream>
#include <chrono>

int delay(int milliseconds) {
    auto start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start).count() < milliseconds) {
        // do nothing (or perform some lightweight operation)
    }
    return 1; // return value is arbitrary
}

Application::Application(/* args */)
{
    client.Client_Create_Socket();
    client.Client_Connect();
}

Application::~Application(/* args */)
{
    
}

void Application::Run()
{
    while (1)
    {
        if(client.Client_Recv() == 0)
            break;

        std::string msg = client.Client_Get_Msg();
        std::transform(msg.begin(),msg.end(),msg.begin(), ::tolower);
        std::cout << msg << std::endl;

        if(msg.find("youtube") != std::string::npos){
            //command to open Youtube 
            std::cout << "Opening Youtube" << std::endl;
            system("xdg-open https://www.youtube.com");
        }

        else if(msg.find("facebook") != std::string::npos){
            //command to open FaceBook 
            std::cout << "Opening FaceBook" << std::endl;
            system("xdg-open https://www.facebook.com");
        }

        else if(msg.find("linkedin") != std::string::npos){
            //command to open linkedin 
            std::cout << "Opening linkedin" << std::endl;
            system("xdg-open https://www.linkedin.com");
        }

        else if(msg.find("chatgpt") != std::string::npos){
            //command to open chatgpt 
            std::cout << "Opening chatgpt" << std::endl;
            system("xdg-open https://www.chatgpt.com");
        }
        delay(500);
    }
}

int main(){
    Application app;
    app.Run();
}