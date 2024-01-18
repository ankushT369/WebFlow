/*
 *
 *
 */

#ifndef WEBFLOW_SERVER_H
#define WEBFLOW_SERVER_H

using namespace webflow {

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
	explicit WebFlowServer(const std::string& host, std::port);	
	~WebFlowServer() = default;

	void Start();				//This function starts the server upto bind
	void Stop();				//This function stops the server when its done

private:
	int sock_fd_;
	std::string host_;
	std::uint16_t port_;
	void SetServerSocket();
};

} // namespace webflow_server.h ends here
#endif \\ WEBFLOW_SERVER_H
