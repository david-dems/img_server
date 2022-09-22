#include "recieve_image.h"
#include <istream>
#include <fstream>
#include <iostream>

#include <cstdio>
#include <jpeglib.h>
#include <jerror.h>

#define cimg_plugin "plugins/jpeg_buffer.h"
#include <CImg.h>
using namespace cimg_library;


void imgRequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response){
    response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
	response.setContentType("img/jpg");

	std::ostream& response_img_stream = response.send();

    std::istream &request_img_stream = request.stream();
    unsigned size = request.getContentLength();
    
    unsigned char* buffer = new unsigned char[size];
    JOCTET *buffer_input = new JOCTET[size];

    //std::FILE *desc = std::fmemopen(buffer, size, "rb+");
    
    //if (!std::fread(buffer_input, sizeof(JOCTET), size, desc)) 
    //    std::cout << "Cannot read an image" << std::endl;

    request_img_stream.read(reinterpret_cast<char*>(buffer_input), size);
    CImg<unsigned char> img;
    img.load_jpeg_buffer(buffer_input, size);
    img.mirror("x");
    JOCTET *buffer_output = new JOCTET[size];
    img.save_jpeg_buffer(buffer_output,size,60); 
    response_img_stream.write(reinterpret_cast<char*>(buffer_output), size);
}