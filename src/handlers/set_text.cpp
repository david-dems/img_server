#include "set_text.h"
#include "server.h"

void RequestHandler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response){
    response.setStatus(Poco::Net::HTTPResponse::HTTP_OK);
	response.setContentType("text/html");
	std::ostream& out = response.send();

	Poco::URI uri(request.getURI());
	if (uri.toString().find("/setText") == 0)
	{
		Poco::StringTokenizer str(uri.getQuery(), "=");
		if (str.count() == 2 && str[0] == "text")
		{
			ImgApplication::setText(str[1]);
			out << "ok" << std::endl;
			out.flush();
			out << ImgApplication::getText() << std::endl;
			out.flush();
			return;
		}
	}

	out << "error";
	out.flush();
}

