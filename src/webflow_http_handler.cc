#include "webflow.h"
#include "webflow_http_handler.h"
#include <iostream>
#include <sstream>

namespace webflow {

HttpMessage::HttpMessage(std::string msg, int socket): 
	http_message_(msg),
	sock_(socket) {
		ParseHttpRequest(http_message_);
	}

void HttpMessage::ParseHttpRequest(const std::string& request) {

	std::string line;
	std::string http_method;
	std::string http_uri;
	std::string http_version;

	std::istringstream iss(request);
	std::getline(iss, line, NL);
	std::istringstream requestLineStream(line);	
	
	std::getline(requestLineStream, http_method, SP);
	std::getline(requestLineStream, http_uri, SP);
	std::getline(requestLineStream, http_version, SP);

    HttpRequest httpRequest;

	httpRequest.method_ = GetHttpMethod(http_method, httpRequest);
	httpRequest.uri = http_uri;
	httpRequest.version_ = GetHttpVersion(http_version, httpRequest);
	
	while (std::getline(iss, line) && !line.empty()) { 
		size_t colonPos = line.find(':');

        if (colonPos != std::string::npos) {	
			std::string headerName = line.substr(0, colonPos);
            std::string headerValue = line.substr(colonPos + 2);  // Skip ': ' after the header name
            httpRequest.header_[headerName] = headerValue;
        }
    }

	return ;
}

HttpMethod HttpMessage::GetHttpMethod(const std::string& method, HttpRequest& httprequest) {
	//print method
	/*switch(method) {
		#define XX(num, name, string) case HttpMethod::HTTP_##name: std::cout << "HTTP " #name << std::endl; break;
			HTTP_METHOD_MAP(XX)
		#undef XX
		default:
			std::cout << "Invalid HTTP method" << std::endl;
        	break;
	}*/
	if (method == "DELETE") {
        return HttpMethod::HTTP_DELETE;
    } else if (method == "GET") {
        return HttpMethod::HTTP_GET;
    } else if (method == "POST") {
        return HttpMethod::HTTP_POST;
    } else if (method == "PUT") {
        return HttpMethod::HTTP_PUT;
    } else {
        return HttpMethod::HTTP_METHOD_ERROR;
    }
	//return ;

}

HttpVersion HttpMessage::GetHttpVersion(const std::string& version, HttpRequest& httprequest) {
	if(version == "HTTP/1.1") {
		return HttpVersion::HTTP_1_1;
	} else {
		return HttpVersion::HTTP_VERSION_NOT_FOUND;
	}
}

}//end of namespace
