#include "mainwindow.h"

#include <QApplication>
#include <thread>

#include "Server.h"

void server_thread_func(Server& server){
    server.Server_Create_Socket();
    server.Server_Bind_Socket();
    server.Server_Listen();
    for (;;)
    {
        server.Server_Accept();
    }
}

Server server;
int main(int argc, char *argv[])
{
    std::thread server_thread(server_thread_func, std::ref(server));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    server_thread.detach();
    
    return a.exec();
}
