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
	std::istringstream iss(request);
    std::string line;

    // Parse the request line
    std::getline(iss, line);
    std::istringstream requestLineStream(line);
    HttpRequest httpRequest;
	
	fmt::print("{}\n", line);
    //requestLineStream >> httpRequest.method_ >> httpRequest.uri >> httpRequest.version_;

    // Parse headers
    while (std::getline(iss, line) && !line.empty()) {
        size_t colonPos = line.find(':');
        if (colonPos != std::string::npos) {
            std::string headerName = line.substr(0, colonPos);
            std::string headerValue = line.substr(colonPos + 2);  // Skip ': ' after the header name
            httpRequest.header_[headerName] = headerValue;
        }
    }
	for(const auto& elem : httpRequest.header_) {
		std::cout << elem.first << " " << elem.second << "\n";
	}
    // Display parsed information
   /* std::cout << "Method: " << httpRequest.method << std::endl;
    std::cout << "Path: " << httpRequest.path << std::endl;
    std::cout << "HTTP Version: " << httpRequest.version << std::endl;
	*/
	return ;
}




}//end of namespace
