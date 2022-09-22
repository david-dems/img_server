#include "not_found_handler.h"


void NotFoundHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response){
    response.setContentType("text/plain");
    response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_NOT_FOUND, "Invalid URI");
    response.send();
}