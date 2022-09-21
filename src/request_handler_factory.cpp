#include "request_handler_factory.h"
#include "set_text.h"

Poco::Net::HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &){
    return new RequestHandler;
}
