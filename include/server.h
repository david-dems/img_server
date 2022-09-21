#pragma once
#include <iostream>
#include "Poco/Mutex.h"
#include "Poco/Util/ServerApplication.h"
#include <Poco/Net/HTTPServer.h>

class ImgApplication : public Poco::Util::ServerApplication{
public:
	static std::string getText();
	static void setText(std::string text_upd);

protected:
	int main(const std::vector<std::string> &);
	static std::string text;
	static Poco::Mutex textLock;
};
