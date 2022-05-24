/* stdint.h standard header */

#pragma once

#ifndef _STDINT
#define _STDINT

/* TYPE DEFINITIONS */
typedef signed char			int8_t;
typedef short				int16_t;
typedef int					int32_t;
typedef __int64				int64_t;

typedef unsigned char		uint8_t;
typedef unsigned short		uint16_t;
typedef unsigned int		uint32_t;
typedef unsigned __int64	uint64_t;

/* LIMIT MACROS */
#define INT8_MIN			(-0x7f - _C2)
#define INT16_MIN			(-0x7fff - _C2)
#define INT32_MIN			(-0x7fffffff - _C2)

#define INT8_MAX			0x7f
#define INT16_MAX			0x7fff
#define INT32_MAX			0x7fffffff
#define INT64_MAX			0x7fffffffffffffff
#define UINT8_MAX			0xff
#define UINT16_MAX			0xffff
#define UINT32_MAX			0xffffffff
#define UINT64_MAX			0xffffffffffffffff

 
#endif /* _STDINT_H_ */
