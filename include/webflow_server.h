/*
 *
 *
 */

#ifndef WEBFLOW_SERVER_H
#define WEBFLOW_SERVER_H

#include "webflow.h"

#include <cstddef>
#include <cstdint>
#include <string>

namespace webflow {

constexpr size_t max_buffer_size = 4096;

//Data type to handle the event data or client's request data
struct EventData {
	EventData(): fd(0), len(0), buffer() {}
	int fd;
	size_t len;
	char buffer[max_buffer_size];
};

class WebFlowServer {
public:	
	explicit WebFlowServer(const std::string& host, uint16_t port);	
	~WebFlowServer() = default;

	void Start();				//This function starts the server upto bind
	void Stop();				//This function stops the server when its done
	void ClientConnection(int);	//This function is for handling each client which creates a seperate thread for each client

private:
	int sock_fd_;
	std::string host_;
	uint16_t port_;
	void SetServerSocket();
};

} // namespace webflow_server.h ends here

#endif // WEBFLOW_SERVER_H
