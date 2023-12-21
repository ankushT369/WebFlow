#pragma once

#ifdef __GNUC__
#if (__GNUC__ > 6) || (__GNUC__ == 6 && __GNUC_MINOR__ >= 2)
	#include <vector>	
	#include <cstring>
	//Other Headers
#else	
#error This code requries GCC version 6.2.0 or newer
#endif
#else 
#error This code requires the GCC compiler
#endif

#if defined(__linux__)
// Headers of POSIX Socket API

#include <cstdio>
#include <cstdlib>
#include <error.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <netdb.h>
#else
#error This code intended for LINUX environment
#endif



