#ifndef SERVER_H_
#define SERVER_H_
#include "webflow.h"

// Base Class
class Server {
 private:
	
 public:
	//
};

// Derived Class
class HTTPRequestHandler : public Server {
 private:
  std::string _method;
	
 public: 

};

#endif //SERVER_H_
