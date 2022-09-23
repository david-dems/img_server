#include "server.h"
#include "request_handler_factory.h"

#include <iostream>
#include <string>
#include <vector>
#include <signal.h>

bool ImgApplication::runtime = true;

#include <Poco/ScopedLock.h>

void sigintHandler(int param){
    ImgApplication::turnOff();
}

void ImgApplication::turnOff(){
    runtime = false;
}


int ImgApplication::main(const std::vector<std::string>&){

    signal(SIGINT, sigintHandler);
   
    Poco::Net::HTTPServer server(new RequestHandlerFactory, Poco::Net::ServerSocket(Poco::Net::SocketAddress(5875)), new Poco::Net::HTTPServerParams);
    
    server.start();
    std::cout << "Server has been started working" << std::endl;

    while(runtime)
        pause();

    server.stop();

    std::cout << std::endl;
    std::cout << "Server is shuted down" << std::endl;

    return Application::EXIT_OK;

}
