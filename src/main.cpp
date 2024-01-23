#include "webflow_server.h"
#include <iostream>

using webflow::WebFlowServer;

int main() {
	std::string host = "0.0.0.0";
	int port = 8080;
	WebFlowServer server(host, port);
	server.Start();
	server.Stop();
	return 0;
}
