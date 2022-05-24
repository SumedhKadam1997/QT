#ifndef _SYSTEM_H_
#define _SYSTEM_H_

//#define DEBUG_NEW_NO_NEW_REDEFINITION
//#include "debug_new.h"
//#define NEW new

#ifdef _DEBUG_NEW_
#define DEBUG_NEW_NO_NEW_REDEFINITION
#include "debug_new.h"
#else
#define NEW new
#endif

#ifdef _MSC_VER

#pragma warning (disable: 4250)
#pragma warning (disable: 4251)
#pragma warning (disable: 4819) // 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
#else
typedef unsigned char byte;
#ifdef  __GNUC___

#endif // __GNUC___
#endif // _MSC_VER
#ifdef WIN32
#ifdef ASPOSE_CELLS_LIBRARY
#define ASPOSE_CELLS_API __declspec(dllexport)
#else
#define ASPOSE_CELLS_API __declspec(dllimport)
#endif
#else
#define ASPOSE_CELLS_API
#endif

#include <inttypes.h>
#include <stdio.h>
#ifdef WIN32
#include <String.h>
#endif

#include <typeinfo>

#ifdef __linux__
enum E : unsigned int ;
#endif
#endif	// _SYSTEM_H_
