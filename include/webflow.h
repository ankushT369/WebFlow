/*
 *
 *
 */
#pragma once
/*
 *
 *
 *
 */
#ifdef __GNUC__
#if (__GNUC__ > 6) || (__GNUC__ == 6 && __GNUC_MINOR__ >= 2)
#define GCC_ENV 1	
	//Other Headers
	#ifdef __has_include
    	#if __has_include(<fmt/core.h>)
        	#include <fmt/core.h>
    	#else
        	#error This code requires the fmt library (fmt/core.h)
    	#endif
    	#else
        	#error __has_include not supported. Please check if fmt library (fmt/core.h) is available.
    	#endif
#else	
#error This code requries GCC version 6.2.0 or newer
#endif
#else 
#error This code requires the GCC compiler
#endif


/* This project is intendent to make in GNU/Linux
 * later it will made for all available for other OS
 * possible, it uses the POSIX socket API or you can
 * say systemcalls.
 *
 *
 */
#if defined(__linux__)
// Headers of POSIX Socket API
#define LINUX_ENV 1
#include <cstdio>
#include <cstdlib>
#include <cerrno>

#else
#error This code intended for LINUX environment
#endif
