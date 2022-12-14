#pragma once
#include <stdexcept>

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/URI.h>
#include <Poco/StringTokenizer.h>

class imgRequestHandler : public Poco::Net::HTTPRequestHandler{
public:
    void handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response);
};