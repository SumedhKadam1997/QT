/* lsl_stdhdr.h standard header */

#pragma once

#ifndef __LSL_STDHDR_H__
#define __LSL_STDHDR_H__


#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#ifdef _WIN32
	#include <windows.h>
	#include <winioctl.h>
	#include <malloc.h>

	// +MF added
	#ifdef UNDER_CE
		#include <winsock2.h>
	#endif
	// -MF added
#else
	#define __STDC_LIMIT_MACROS
	// COMPILE_LINUX
	#include "../Linux/Linux.h"
	#include <sys/socket.h>
	#include <memory.h>
	#include <string.h>
#endif


// MSVC++ 11.0 _MSC_VER = 1700 (Visual Studio 2012)
// MSVC++ 10.0 _MSC_VER = 1600 (Visual Studio 2010)
// MSVC++ 9.0  _MSC_VER = 1500 (Visual Studio 2008)
// MSVC++ 8.0  _MSC_VER = 1400 (Visual Studio 2005)
// MSVC++ 7.1  _MSC_VER = 1310 (Visual Studio 2003)
// MSVC++ 7.0  _MSC_VER = 1300
// MSVC++ 6.0  _MSC_VER = 1200
// MSVC++ 5.0  _MSC_VER = 1100

#ifdef _WIN32
	#if _MSC_VER  >= 1600	// >= VS 2010
		#include <stdint.h>
	#else
		#include "lsl_stdint.h"
	#endif
#else
	#include <stdint.h>
#endif


#ifdef _PRDEBUG
	#include <CRTDBG.H>
#endif

#endif /* __LSL_STDHDR_H__ */
