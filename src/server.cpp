#include "server.h"
#include "request_handler_factory.h"

#include <iostream>
#include <string>
#include <vector>

std::string ImgApplication::text = "Hello world!";
Poco::Mutex ImgApplication::textLock;

#include <Poco/ScopedLock.h>

void ImgApplication::setText(std::string text_upd){
    //textLock.lock();
    text = text_upd;
    //textLock.unlock();
}

std::string ImgApplication::getText(){
    //textLock.lock();
    return text;
   //textLock.unlock();
}

int ImgApplication::main(const std::vector<std::string>&){

    Poco::Net::HTTPServer server(new RequestHandlerFactory, Poco::Net::ServerSocket(Poco::Net::SocketAddress(8000)), new Poco::Net::HTTPServerParams);
    server.start();

    for(;;){
    }    
    server.stop();
    return Application::EXIT_OK;

}
