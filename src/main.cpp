#include "webflow.h"
#include "socket_handler.h"
#include "http_request_handler.h"

int main() {
	HttpRequestHandler server;
	server.init();
	return 0;
}
