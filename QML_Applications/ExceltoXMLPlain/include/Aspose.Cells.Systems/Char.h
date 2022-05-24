#ifndef _SYSTEM_CHAR_H_
#define _SYSTEM_CHAR_H_
#include <stdint.h>
namespace Aspose {
	namespace Cells {
		namespace Systems {
#ifdef WIN32
			typedef wchar_t Char;
#else
            typedef char16_t Char; //we must use wchar_t.since many functions such as wcslen,wcschr,wmemset... based on paremeter wchar_t
            //wchar_t to char16_t
            unsigned short* wcs2char16(wchar_t *wcs, unsigned short * utf16, int len);//no used
            //wchar_t length
            int wcharlen(wchar_t *wcs);//no used
            //char16_t to wchar_t
            wchar_t * char162wchar(unsigned short * utf16, wchar_t *wcs, int len);//no used


            //char16_t length
            int char16len(Char * utf16);
            Char* wcstrchr(Char* str, Char chr);
            Char* wcstrstr(const Char* src, const Char* sub);
#endif
		}
	}
}
#endif	// _SYSTEM_CHAR_H_
