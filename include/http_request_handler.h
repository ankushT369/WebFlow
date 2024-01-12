/*
 *
 *
 *
 *
 *
 *
 */


#ifndef HTTP_REQUEST_HANDLER_H
#define HTTP_REQUEST_HANDLER_H

#include "socket_handler.h"
#include "webflow.h"

class HttpRequestHandler : public SocketHandler {
private:

        void getLocalAddrInfo() {
                //Fetching the Local Adderss of the Running Server

                struct sockaddr_in localAddr;
                socklen_t addrLen = sizeof(localAddr);

                if( getsockname(sockfd, (struct sockaddr*)&localAddr, &addrLen) == 0 ) {

                        std::cout << "Server is listening on: " << inet_ntoa(localAddr.sin_addr) << ":" << ntohs(localAddr.sin_port) << '\n';

                } else {

                        std::cerr << "Error: Unable to fetch local address information.\n\n";

                }
        }

public:

        char buffer[1024];
	void init();
	HttpRequestHandler() {

	}
	
};


#endif // HTTP_REQUEST_HANDLER_H
