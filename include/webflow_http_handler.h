//webflow_http_handler.h

#ifndef WEBFLOW_HTTP_HANDLER_H
#define WEBFLOW_HTTP_HANDLER_H
#include <map>
#include <string>

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
	XX(-1, _VERSION_ERROR, VERSION_ERROR)								

enum class HttpVersion {
#define XX(num, version, string) HTTP##version = num,
	HTTP_VERSION(XX)
#undef XX
};



//http status code
#define HTTP_STATUS_CODE(XX)							\
	XX(200, OK, Ok)										\
	XX(404, NOT_FOUND, File_not_found)					\
	XX(403, FORBIDDEN, Forbidden)						

enum class HttpStatusCode {
#define XX(num, reason_phrase, string) HTTP##reason_phrase = num,
	HTTP_STATUS_CODE(XX)
#undef XX
};



#define CR '\r'
#define LF '\n'
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

struct HttpResponse : HttpRequest {
	HttpStatusCode status_;
	std::string response_content;
};

class HttpMessage {
public:
	HttpMessage() = default;
	
	explicit HttpMessage(std::string http_message, int sock);
	
	virtual ~HttpMessage() = default;
	
protected:
	std::string http_message_;
	int sock_;
	
	void ParseHttpRequest(const std::string&);
	
	std::string GetHttpUri(const std::string&);
	HttpMethod GetHttpMethod(const std::string&, HttpRequest&);
	HttpVersion GetHttpVersion(const std::string&, HttpRequest&);
};

}
#endif // WEBFLOW_HTTP_HANDLER_H
