#include "webflow_server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <iostream>
#include <memory>
#include <utility>

namespace webflow {

WebFlowServer::WebFlowServer(const std::string& host, uint16_t port):
	host_(host),
	port_(port),
	sock_fd_(0) {
		SetServerSocket();
	}

// create the server socket
void WebFlowServer::SetServerSocket() {
	if((sock_fd_ = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		//throw stuff...
		perror("Error: ");
	}
}

//this function starts upto bind
void WebFlowServer::Start() {

	int opt = 1;
	struct sockaddr_in server_address_;

	if(setsockopt(sock_fd_, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, &opt,
				sizeof(opt)) < 0) {
		perror("Error: ");
		//throw stuff...
	}

	server_address_.sin_family = AF_INET;
    	server_address_.sin_addr.s_addr = INADDR_ANY;
    	server_address_.sin_port = htons(port_);

	if(bind(sock_fd_, (struct sockaddr*)&server_address_,
				sizeof(server_address_)) < 0) {
		perror("Error: ");
		//throw stuff...
	}
	
	if(listen(sock_fd_, 30) < 0) {
		perror("Error:");
		//throw stuff...
	}

	int client_sock = 0;
	socklen_t addrlen = sizeof(server_address_);

	
	while(1) {
		std::unique_ptr<EventData> client_data(new EventData());
		
		if((client_sock = accept(sock_fd_, (struct sockaddr*)&server_address_, &addrlen)) < 0) {
			perror("Error: ");
		}
		client_data->fd = client_sock;

		client_data->len = read(client_sock, client_data->buffer, max_buffer_size - 1);
		fmt::print("{}", client_data->buffer);
		
		close(client_sock);
	}
	

}

void WebFlowServer::Stop() {
	close(sock_fd_);
}


} // namespace webflow ends here;
