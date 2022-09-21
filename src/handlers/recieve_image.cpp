#include "recieve_image.h"
#include <istream>
#include <fstream>
#include <iostream>

void imgRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response){
    response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
	response.setContentType("img/jpg");

	std::ostream& response_img_stream = response.send();

    std::istream &request_img_stream = request.stream();
    int size = request.getContentLength();
    char* buffer = new char[size];
    request_img_stream.read(buffer, size);
    response_img_stream.write(buffer, size);
}