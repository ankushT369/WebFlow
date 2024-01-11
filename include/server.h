#include "webflow.h"
#include <iostream>
#include <string>

class webFlow {
protected:
    	uint16_t sockfd, clientSock;
public:
	webFlow(): sockfd(socket(AF_INET, SOCK_STREAM, 0)), clientSock(0) {
		if (sockfd == -1) {
			std::cerr << "Socket Creation Failed\n";
		}
    	}

    	~webFlow() {
        	close(clientSock);
        	close(sockfd);
        	std::cout << "Socket closed\n";
    	}
};

class httpServer : public webFlow {
private:
    	const uint32_t port = 8080;
	void getLocalAddrInfo() {
				
	}
public:
    	char Buffer[1024];
    	void init();
};

void httpServer::init() {
	std::cout << "====================================\n";
    	std::cout << "          SERVER STARTED\n";
	std::cout << "====================================\n";
	std::cout << "Connected to the http://localhost:8080/\n";

	struct sockaddr_in serverInfo;
	serverInfo.sin_family = AF_INET;
    	serverInfo.sin_addr.s_addr = INADDR_ANY;
    	serverInfo.sin_port = htons(port);

    	if (bind(sockfd, (struct sockaddr*)&serverInfo, sizeof(serverInfo)) < 0) {
       		std::cerr << "Bind Failed: Error unable to bind the client\n";
    	}

    	if (listen(sockfd, 3) < 0) {
        	std::cerr << "Stopped listening\n";
    	}

    	socklen_t addrLen = sizeof(serverInfo);  // Need the address length for accept
    	if ((clientSock = accept(sockfd, (struct sockaddr*)&serverInfo, &addrLen)) < 0) {
        	std::cerr << "Not accepting\n";
    	}
	
	while(1) {
    		read(clientSock, Buffer, sizeof(Buffer) - 1);
    		Buffer[sizeof(Buffer) - 1] = '\0';  // Null-terminate the string
    		std::string str(Buffer);
    		std::cout << str;
		// HTTP response headers
        	std::string response = "HTTP/1.1 200 OK\r\n";
        	response += "Content-Type: text/html\r\n";
        	response += "Content-Length: " + std::to_string(strlen("<html><head>hiii</head></html>")) + "\r\n";
        	response += "\r\n";  // End of headers

        	// HTTP response body
        	response += "<html><head>hiii</head></html>";

        	// Send the HTTP response to the browser
        	send(clientSock, response.c_str(), response.length(), 0);
	}
    	return;
}

