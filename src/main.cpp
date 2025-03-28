#include "webflow_server.h"
#include <iostream>

using webflow::WebFlowServer;

int main() {
	std::string host = "0.0.0.0";
	int port = 8080;
	WebFlowServer server(host, port);
        fmt::print(R"(
/$$      /$$           /$$        /$$$$$$  /$$                        
| $$  /$ | $$          | $$       /$$__  $$| $$                        
| $$ /$$$| $$  /$$$$$$ | $$$$$$$ | $$  \__/| $$  /$$$$$$  /$$  /$$  /$$
| $$/$$ $$ $$ /$$__  $$| $$__  $$| $$$$    | $$ /$$__  $$| $$ | $$ | $$
| $$$$_  $$$$| $$$$$$$$| $$  \ $$| $$_/    | $$| $$  \ $$| $$ | $$ | $$
| $$$/ \  $$$| $$_____/| $$  | $$| $$      | $$| $$  | $$| $$ | $$ | $$
| $$/   \  $$|  $$$$$$$| $$$$$$$/| $$      | $$|  $$$$$$/|  $$$$$/$$$$/
|__/     \__/ \_______/|_______/ |__/      |__/ \______/  \_____/\___/ 
                )");
	
        fmt::print("\n\n");
        fmt::print("Connected with port {}\n", port);
	server.Start();

	server.Stop();
	return 0;
}
