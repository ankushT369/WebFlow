#include "webflow_server.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace webflow {

WebFlowServer::WebFlowServer(const std::string& host, uint16_t port):
	host_(host),
	port(port_),
	sock_fd_(0) {
		SetServerSocket();
	}

// create the server socket
void WebFlowServer::SetServerSocket() {
	if(sock_fd_ = socket(AF_INET, SOCK_STREAM, 0) < 0) {
		//throw stuff...
	}
}

//this function starts upto bind
void Start() {
	int opt = 1;
	sockaddr_in server_address_;
	if(setsockopt(sock_fd_, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, &opt,
				sizeof(opt)) < 0) {
		//throw stuff...
	}

	address.sin_family = AF_INET;
    	address.sin_addr.s_addr = INADDR_ANY;
    	address.sin_port = htons(port_);

	if(bind(sock_fd_, (struct sockaddr*)&server_address_,
				sizeof(server_address_)) < 0) {
		//throw stuff...
	}


}






} // namespace webflow ends here;
