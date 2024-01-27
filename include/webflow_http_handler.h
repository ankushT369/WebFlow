//webflow_http_handler.h

#ifndef WEBFLOW_HTTP_HANDLER_H
#define WEBFLOW_HTTP_HANDLER_H
#include <map>
#include <string>
#include <functional>

namespace webflow {

//Http method map
#define HTTP_METHOD_MAP(XX)								\
	XX(1, DELETE, DELETE)								\
	XX(2, GET, GET)										\
	XX(3, POST, POST)									\
	XX(4, PUT, PUT)										\
	XX(0, METHOD_ERROR, METHOD_ERROR)									\

enum class HttpMethod {
#define XX(num, name, string) HTTP_##name = num,
	HTTP_METHOD_MAP(XX)
#undef XX
};

//http verison map
#define HTTP_VERSION(XX)								\
	XX(11, _1_1, HTTP/1.1)								\
	XX(-1, _VERSION_NOT_FOUND, NOT_FOUND)								

enum class HttpVersion {
#define XX(num, version, string) HTTP##version = num,
	HTTP_VERSION(XX)
#undef XX
};

#define CR '\r'
#define NL '\n'
#define SP ' '
/*
 *
 *
 */
struct HttpRequest {
	HttpMethod method_;
	std::string uri;
	HttpVersion version_;
	std::map<std::string, std::string> header_;
	std::string message_content;
};

class HttpMessage {
public:
	HttpMessage() = default;
	explicit HttpMessage(std::string http_message, int sock);
	virtual ~HttpMessage() = default;
	HttpMethod GetHttpMethod(const std::string&, HttpRequest&);

protected:
	std::string http_message_;
	int sock_;
	void ParseHttpRequest(const std::string&);
	std::string GetHttpUri(const std::string&);
	HttpVersion GetHttpVersion(const std::string&, HttpRequest&);
};

}
#endif // WEBFLOW_HTTP_HANDLER_H
