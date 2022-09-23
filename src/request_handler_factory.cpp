#include "request_handler_factory.h"
#include "recieve_image.h"
#include "not_found_handler.h"
#include <iostream>

Poco::Net::HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request){
	Poco::URI uri(request.getURI());
    std::string uriString = uri.toString();
    if (uriString == "/")
        return new imgRequestHandler; 
    return new NotFoundHandler;
}
