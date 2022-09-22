#pragma once
#include <iostream>
#include "Poco/Mutex.h"
#include "Poco/Util/ServerApplication.h"
#include <Poco/Net/HTTPServer.h>

class ImgApplication : public Poco::Util::ServerApplication{
public:
	static void turnOff();
protected:
	int main(const std::vector<std::string> &);
	static bool runtime;
};
