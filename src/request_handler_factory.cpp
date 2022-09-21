#include "request_handler_factory.h"
#include "set_text.h"
#include "recieve_image.h"

Poco::Net::HTTPRequestHandler* RequestHandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest &request){
	Poco::URI uri(request.getURI());
	if (uri.toString().find("/setText") == 0)
        return new RequestHandler;
    return new imgRequestHandler; 

}
