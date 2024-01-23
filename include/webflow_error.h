//webflow_error.h

#ifndef WEBFLOW_ERROR_H
#define WEBFLOW_ERROR_H

#include <stdexcept>

namespace webflow_error {

#define ERROR_CODE_MAP(XX)                                           	\
    XX(0, WEBFLOW_OK,                 noErrorFunction)               	\
    XX(1, WEBFLOW_GENERIC_ERROR,      genericErrorFunction)          	\
    XX(2, WEBFLOW_SOCKET_FAILED,      socket)           			 	\
    XX(3, WEBFLOW_SOCKET_OPTION_FAILED, setsockopt)   				 	\
    XX(4, WEBFLOW_BIND_FAILED,         bind)            			 	\
    XX(5, WEBFLOW_LISTEN_FAILED,       listen)          			 	\
    XX(6, WEBFLOW_ACCEPT_FAILED,       accept)          				\


enum class ErrorCode {

};

}

#endif // WEBFLOW_ERROR_H
