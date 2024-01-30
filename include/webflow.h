/*MIT License

Copyright (c) 2023 Ankush

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
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
