#include "webflow_server.h"
#include "webflow_http_handler.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fmt/core.h>

#include <memory>
#include <thread>

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

		if((client_sock = accept(sock_fd_, (struct sockaddr*)&server_address_, &addrlen)) < 0) {
			perror("Error: ");
		}
		
		std::thread client_thread(&WebFlowServer::ClientConnection, this, client_sock);	
		client_thread.detach();

	}
	
}

void WebFlowServer::ClientConnection(int _client_sock) {

	std::unique_ptr<EventData> client_data(new EventData());	
	client_data->fd = _client_sock;

	client_data->len = read(_client_sock, client_data->buffer, max_buffer_size - 1);

	client_data->buffer[max_buffer_size] = '\0';
	fmt::print("{}\n", client_data->buffer);
	
	HttpMessage http_msg(client_data->buffer, client_data->fd);

	 const char* html = "HTTP/1.1 200 OK\r\n"
					    "Content-Type: text/html\r\n"
                        "Content-Length: 21\r\n"
                        "\r\n"
                        "<h1>Puchku pagol</h1>";
	send(_client_sock, html, strlen(html), 0);
	
	close(_client_sock);
}

void WebFlowServer::Stop() {
	close(sock_fd_);
}


} // namespace webflow ends here;
