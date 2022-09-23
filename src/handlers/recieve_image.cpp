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
    unsigned size = request.getContentLength();


    std::istream &request_img_stream = request.stream();
    
    JOCTET *buffer_input = new JOCTET[size];

    request_img_stream.read(reinterpret_cast<char*>(buffer_input), size);
    CImg<unsigned char> img;
    
    JOCTET *buffer_output = new JOCTET[size];
    try{
        if (size > 4){
            //is current byte array valid jpeg?
            //let's check
            if (buffer_input[0] != 0xFF || buffer_input[1] != 0xD8 || buffer_input[size-2] != 0xFF || buffer_input[size-1] != 0xD9){
                throw std::runtime_error("File is not a valid JPEG");
            }else{
	            std::ostream &response_img_stream = response.send();
                img.load_jpeg_buffer(buffer_input, size);
                img.mirror("x");
                img.save_jpeg_buffer(buffer_output,size,60); 
                response_img_stream.write(reinterpret_cast<char*>(buffer_output), size);
	            response.setContentType("image/jpeg");
                response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
                response_img_stream.flush();
            }
        }else{
            throw std::runtime_error(std::string("Empty file"));
        }
    } catch (std::exception &excp){
        response.setStatusAndReason(Poco::Net::HTTPResponse::HTTP_BAD_REQUEST, excp.what());
	    response.setContentType("text/plain");
	    std::ostream &error_stream = response.send();
    }


    delete[] buffer_input;
    delete[] buffer_output;

}