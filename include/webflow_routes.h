/*
 *
 *
 */
#ifndef WEBFLOW_ROUTES_H
#define WEBFLOW_ROUTES_H
#include <unordered_map>
#include <string>

namespace webflow {

class WebFlowRoutes {
public:
	WebFlowRoutes(std::string key, std::string value), key_(key), value_(value) {}

private:
	std::unordered_map<std::string, std::string> routes_map_;
	std::string key_, value_;
};


}

#endif // WEBFLOW_ROUTES_H
