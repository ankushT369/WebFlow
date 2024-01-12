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


#include "webflow.h"
#include "http_request_handler.h"
#include "socket_handler.h"


void HttpRequestHandler::init() {

        getLocalAddrInfo();

        while(1) {

                read(clientSock, buffer, sizeof(buffer) - 1);
                buffer[sizeof(buffer) - 1] = '\0';  // Null-terminate the string
                std::string str(buffer);
                std::cout << str;


                // HTTP response headers
                std::string response = "HTTP/1.1 200 OK\r\n";
                response += "Content-Type: text/html\r\n";
                response += "Content-Length: " + std::to_string(strlen("<html><head>hiii</head></html>")) + "\r\n";
                response += "\r\n";  // End of headers


                // HTTP response body
                response += "<html><h1>hiii</h1></html>";


                // Send the HTTP response to the browser
                send(clientSock, response.c_str(), response.length(), 0);

        }
        return;

}

