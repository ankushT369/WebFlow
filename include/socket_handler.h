/*
 *
 *
 *
 *
 *
 *
 *
 *
 */


#ifndef SOCKET_HANDLER_H
#define SOCKET_HANDLER_H

#include "webflow.h"
#include <iostream>

/* SocketManager Class contains the constructor and ~destructor for
 *	
 * the start socket and the client socket. It has a compile time port identifier
 *
 * the constructor starts the server by assigning the configuration of the server
 *
 * by binding listening and accepting it.
 */

class SocketHandler {
private:
	void serverInit() {
		
		
		struct sockaddr_in serverInfo;
		serverInfo.sin_family = AF_INET;
    		serverInfo.sin_addr.s_addr = INADDR_ANY;
    		serverInfo.sin_port = htons(port);

		if (bind(sockfd, (struct sockaddr*)&serverInfo, sizeof(serverInfo)) < 0) {
       			std::cerr << "Bind Failed: Error unable to bind the client\n";
    		}

    		//throw std::runtime_error("Server Initialization Failed");
        	std::cout << "====================================\n";
        	std::cout << "          SERVER STARTED\n";
        	std::cout << "====================================\n";
        	std::cout << "Connected to the http://localhost:8080/\n";
		
		if (listen(sockfd, 3) < 0) {
        		std::cerr << "Stopped listening\n";
    		}

    	
		socklen_t addrLen = sizeof(serverInfo);  // Need the address length for accept
    		if ((clientSock = accept(sockfd, (struct sockaddr*)&serverInfo, &addrLen)) < 0) {
        		std::cerr << "Not accepting\n";
    		}	

	}

protected:
    	
	int sockfd, clientSock;
	uint16_t port = 8080;

public:
	
	SocketHandler(): sockfd(socket(AF_INET, SOCK_STREAM, 0)), clientSock(0) {
	
		if (sockfd == -1) {
			
			std::cerr << "Socket Creation Failed\n";
		
		}

		try {
			
			serverInit();
		
		} catch(const std::exception& e) {
			
			std::cerr << "Error during server initialization: " << e.what() << '\n';
			std::exit(EXIT_FAILURE);			
		}
    	
	}

	~SocketHandler() {
        	
		close(clientSock);
        	close(sockfd);
        	std::cout << "Socket closed\n";
    	
	}

};

#endif // SOCKET_HANDLER_H
