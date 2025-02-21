//*****************************************************************************************
// Copyright (c) 2005 Sony DADC
// All rights reserved.
//
// $FileName    : securom_api.h
// $ProjectName : SDK
// $Created     : 02.03.2005  12:14
//
// Content:
//
//*****************************************************************************************

#ifndef SECUROM_SDK_H
#define SECUROM_SDK_H

#undef USE_SECUROM_MARKERS_API

#ifdef DEDICATED_SERVER
#undef USE_SECUROM_MARKERS_API
#endif // DEDICATED_SERVER

#ifdef _EDITOR
#undef USE_SECUROM_MARKERS_API
#endif // _EDITOR

#ifndef USE_SECUROM_MARKERS_API

#define SECUROM_MARKER_PERFORMANCE_ON(id)
#define SECUROM_MARKER_PERFORMANCE_OFF(id)

#define SECUROM_MARKER_SECURITY_ON(id)
#define SECUROM_MARKER_SECURITY_OFF(id)

#define SECUROM_MARKER_HIGH_SECURITY_ON(id)
#define SECUROM_MARKER_HIGH_SECURITY_OFF(id)

#else // USE_SECUROM_MARKERS_API

#include <windows.h>
#include <stdio.h>

#if 0
static BOOL SecuROM_Tripwire() 
{ 
	char	event_name[50];
		
	sprintf(event_name, "v7_%04d", (GetCurrentProcessId() ^ 0x19EA3FD3) );
	
	if(HANDLE S7hnd = OpenEventA(EVENT_MODIFY_STATE, FALSE, event_name))
	{
		CloseHandle(S7hnd);
		return TRUE;
	}

	return FALSE;
}
#endif // 0

#define SECUROM_MARKER_PERFORMANCE_ON(id)                                                                                                                                                                                                                                                                                         \
	{                                                                                                                                                                                                                                                                                                                             \
		{                                                                                                                                                                                                                                                                                                                         \
			__asm _emit 0xEB __asm _emit 0x0E __asm _emit 'M' __asm _emit 'a' __asm _emit '0' __asm _emit 'W' __asm _emit 'y' __asm _emit 'G' __asm _emit '1' __asm _emit 'k' __asm _emit 'm' __asm _emit 0x01 __asm _emit(id & 0xFF) __asm _emit((id >> 8) & 0xFF) __asm _emit((id >> 16) & 0xFF) __asm _emit((id >> 24) & 0xFF) \
		}
#define SECUROM_MARKER_PERFORMANCE_OFF(id)                                                                                                                                                                                                                                                                                    \
	{                                                                                                                                                                                                                                                                                                                         \
		__asm _emit 0xEB __asm _emit 0x0E __asm _emit 'M' __asm _emit 'a' __asm _emit '0' __asm _emit 'W' __asm _emit 'y' __asm _emit 'G' __asm _emit '1' __asm _emit 'k' __asm _emit 'm' __asm _emit 0x02 __asm _emit(id & 0xFF) __asm _emit((id >> 8) & 0xFF) __asm _emit((id >> 16) & 0xFF) __asm _emit((id >> 24) & 0xFF) \
	}                                                                                                                                                                                                                                                                                                                         \
	}

#define SECUROM_MARKER_SECURITY_ON(id)                                                                                                                                                                                                                                                                                            \
	{                                                                                                                                                                                                                                                                                                                             \
		{                                                                                                                                                                                                                                                                                                                         \
			__asm _emit 0xEB __asm _emit 0x0E __asm _emit 'M' __asm _emit 'a' __asm _emit '0' __asm _emit 'W' __asm _emit 'y' __asm _emit 'G' __asm _emit '1' __asm _emit 'k' __asm _emit 'm' __asm _emit 0x11 __asm _emit(id & 0xFF) __asm _emit((id >> 8) & 0xFF) __asm _emit((id >> 16) & 0xFF) __asm _emit((id >> 24) & 0xFF) \
		}
#define SECUROM_MARKER_SECURITY_OFF(id)                                                                                                                                                                                                                                                                                             \
	{                                                                                                                                                                                                                                                                                                                               \
		__asm _emit 0xEB __asm _emit 0x0E __asm __asm _emit 'M' __asm _emit 'a' __asm _emit '0' __asm _emit 'W' __asm _emit 'y' __asm _emit 'G' __asm _emit '1' __asm _emit 'k' __asm _emit 'm' __asm _emit 0x12 __asm _emit(id & 0xFF) __asm _emit((id >> 8) & 0xFF) __asm _emit((id >> 16) & 0xFF) __asm _emit((id >> 24) & 0xFF) \
	}                                                                                                                                                                                                                                                                                                                               \
	}

#define SECUROM_MARKER_HIGH_SECURITY_ON(id)                                                                                                                                                                                                                                                                                       \
	{                                                                                                                                                                                                                                                                                                                             \
		{                                                                                                                                                                                                                                                                                                                         \
			__asm _emit 0xEB __asm _emit 0x0E __asm _emit 'M' __asm _emit 'a' __asm _emit '0' __asm _emit 'W' __asm _emit 'y' __asm _emit 'G' __asm _emit '1' __asm _emit 'k' __asm _emit 'm' __asm _emit 0x21 __asm _emit(id & 0xFF) __asm _emit((id >> 8) & 0xFF) __asm _emit((id >> 16) & 0xFF) __asm _emit((id >> 24) & 0xFF) \
		}
#define SECUROM_MARKER_HIGH_SECURITY_OFF(id)                                                                                                                                                                                                                                                                                  \
	{                                                                                                                                                                                                                                                                                                                         \
		__asm _emit 0xEB __asm _emit 0x0E __asm _emit 'M' __asm _emit 'a' __asm _emit '0' __asm _emit 'W' __asm _emit 'y' __asm _emit 'G' __asm _emit '1' __asm _emit 'k' __asm _emit 'm' __asm _emit 0x22 __asm _emit(id & 0xFF) __asm _emit((id >> 8) & 0xFF) __asm _emit((id >> 16) & 0xFF) __asm _emit((id >> 24) & 0xFF) \
	}                                                                                                                                                                                                                                                                                                                         \
	}

#define SECUROM_MARKER_VM_CALL(id, code, data)                                                                                                                                                                                                                                                                                                                              \
	{                                                                                                                                                                                                                                                                                                                                                                       \
		__asm _emit 0xEB __asm _emit 0x18 __asm _emit 'M' __asm _emit 'a' __asm _emit '0' __asm _emit 'W' __asm _emit 'y' __asm _emit 'G' __asm _emit '1' __asm _emit 'k' __asm _emit 'm' __asm _emit 0x31 __asm _emit(id & 0xFF) __asm _emit((id >> 8) & 0xFF) __asm _emit((id >> 16) & 0xFF) __asm _emit((id >> 24) & 0xFF) __asm push offset code __asm push offset data \
	}

static unsigned char MACRO_ADD[] =
	{
		0xEC, 0xAF, 0xCA, 0x36, 0xB7, 0x0D, 0x59, 0xC1, 0xFA, 0xA7, 0x71, 0xB1, 0x23, 0xC5, 0x8E, 0x65, 0xD1, 0x36, 0x03, 0x12,
		0x7A, 0x2C, 0x31, 0x3A, 0x3E, 0x14, 0x5D, 0xD2, 0x0C, 0x51, 0x66, 0xC7, 0xE1, 0x60, 0x98, 0x6A, 0x16, 0x9D, 0xA8, 0x80,
		0xE4, 0x7A, 0x94, 0xB2, 0xA2, 0xF5, 0x6E, 0x27, 0xF5, 0x0A, 0x3F, 0xC5, 0xFF, 0x20, 0x4C, 0xB8, 0xC5, 0x72, 0x71, 0x9A,
		0xA9, 0xA0, 0xDD, 0x4F, 0x68, 0x53, 0xB1, 0xFA, 0x26, 0x14, 0x85, 0x94, 0x21, 0x14, 0x80, 0x5C, 0x70, 0xBA, 0xC5, 0xF6,
		0x58, 0xDB, 0xAE, 0xE5, 0x8D, 0xCD, 0xDC, 0x6A, 0x9C, 0x11, 0xFC, 0x6D, 0x33, 0x17, 0xFB, 0xF2, 0x30, 0xF2, 0xE0, 0xD3,
		0xE3, 0x92, 0xAC, 0x46, 0xC7, 0x86, 0x9B, 0x6E, 0x74, 0x5D, 0xB1, 0x05, 0xB9, 0xFA, 0x75, 0x9F, 0x84, 0x57, 0x2A, 0x40,
		0x72, 0xE7, 0xC9, 0xCB};

static unsigned char MACRO_SUB[] =
	{
		0xEC, 0xAF, 0xCA, 0x36, 0xB7, 0x0D, 0x59, 0xC1, 0xFA, 0xA7, 0x71, 0xB1, 0x23, 0xC5, 0x8E, 0x65, 0xD1, 0x36, 0x03, 0x12,
		0x7A, 0x2C, 0x31, 0x3A, 0x3E, 0x14, 0x5D, 0xD2, 0x0C, 0x51, 0x66, 0xC7, 0xE1, 0x60, 0x98, 0x6A, 0x16, 0x9D, 0xA8, 0x80,
		0xE4, 0x7A, 0x94, 0xB2, 0xA2, 0xF5, 0x6E, 0x27, 0xF5, 0x0A, 0x3F, 0xC5, 0xFF, 0x20, 0x4C, 0xB8, 0xC5, 0x72, 0x71, 0x9A,
		0xA9, 0xA0, 0xDD, 0x4F, 0x68, 0x53, 0xB1, 0xFA, 0x26, 0x14, 0x85, 0x94, 0x21, 0x14, 0x80, 0x5C, 0x70, 0xBA, 0xC5, 0xF6,
		0x58, 0xDB, 0xAE, 0xE5, 0x8D, 0xCD, 0xDC, 0x6A, 0x9C, 0x11, 0xFC, 0x6D, 0x33, 0x17, 0xFB, 0xF2, 0x22, 0xEC, 0xB5, 0xFD,
		0x75, 0xCA, 0x2B, 0x55, 0xCC, 0x2B, 0xBE, 0xFC, 0xC6, 0x73, 0x3C, 0xEF, 0xFD, 0xD7, 0x8B, 0x86, 0x69, 0x4A, 0x6A, 0x80,
		0xF0, 0x6E, 0xA7, 0x09};

static unsigned char MACRO_IF_EQL[] =
	{
		0xEC, 0xAF, 0xAA, 0x93, 0x2D, 0x04, 0xA3, 0x8F, 0x8A, 0x10, 0x67, 0x91, 0xC9, 0xE1, 0xDA, 0x2C, 0x31, 0x1D, 0x82, 0xE2,
		0x07, 0xF9, 0xE8, 0x24, 0x75, 0xE9, 0x9D, 0x54, 0x70, 0x36, 0x4F, 0xFF, 0xDD, 0x4A, 0x82, 0x14, 0x88, 0x48, 0x74, 0x51,
		0x3F, 0xBA, 0x51, 0x98, 0xE9, 0x1D, 0x27, 0xB1, 0x7B, 0x97, 0x27, 0x46, 0x9A, 0x46, 0x64, 0xD4, 0xEF, 0x92, 0xF0, 0x05,
		0x5E, 0x79, 0xED, 0x8D, 0x34, 0x52, 0x8A, 0x90, 0xE9, 0xBA, 0x3C, 0xBE, 0x8B, 0xE5, 0xCA, 0x28, 0xB0, 0x92, 0xDE, 0x4C,
		0xD8, 0x31, 0xCE, 0xCE, 0x8E, 0x22, 0x78, 0xF8, 0x7C, 0xCE, 0xF6, 0x4E, 0x84, 0xD0, 0xEE, 0xB5, 0x0B, 0x8E, 0x53, 0xD5,
		0xCE, 0x7C, 0x4F, 0x2F, 0xFA, 0xF6, 0xBF, 0xC8, 0x70, 0x5A, 0x0E, 0x00, 0xDB, 0x93, 0x44, 0x83, 0xF4, 0xFC, 0xEB, 0x2F,
		0x31, 0x1D, 0x02, 0x23, 0x9E, 0x8A, 0xB5, 0x13, 0x68, 0x48, 0x3D, 0x76, 0x01, 0xFE, 0x40, 0x78, 0x2C, 0xB7, 0x09, 0x39,
		0xCF, 0xA4, 0x58, 0x87, 0x72, 0xF8, 0xA0, 0xBC, 0xE9, 0xA3, 0xD0, 0xC0, 0x78, 0x80, 0xFA, 0xDC, 0x05, 0x9A, 0x0C, 0x40,
		0x9C, 0xB6, 0x62, 0xD4, 0x6E, 0xA0, 0x18, 0x9A, 0xEE, 0x85, 0x4A, 0xB0, 0x63, 0xD3, 0x2A, 0x84, 0xCA, 0x3C, 0x55, 0xA9,
		0xD2, 0x18, 0xAE, 0x4D, 0x40, 0x80, 0xE5, 0x7A, 0x95, 0x33, 0x90, 0xF2, 0xF6, 0x06, 0xD9, 0x65, 0x4D, 0x2B, 0x95, 0x29,
		0x02, 0xB9, 0xF9, 0xA6, 0x05, 0x56, 0x13, 0x2B, 0x9F, 0x69, 0xFA, 0xF1, 0xBB, 0x28, 0xA6, 0x71, 0x40, 0x11, 0xD7, 0x86,
		0x04, 0xEE, 0xB6, 0xEE, 0xBA, 0xC6, 0x45, 0x07, 0x75, 0xEC, 0xC5, 0xD0, 0x7D, 0x8C, 0xC5, 0x51, 0x63, 0xB4, 0xEA, 0x51,
		0x63, 0xB4, 0xEA, 0xD6, 0x61, 0xB1, 0xE1, 0xBF, 0xD4, 0x5E, 0xAD, 0x7D, 0xD5, 0x03, 0x53, 0x50, 0x9C, 0x68, 0x1B, 0xA5,
		0xB4, 0xF8, 0x66, 0x1E, 0xC6, 0x76, 0x19, 0xA9, 0x2F, 0x54, 0xE6, 0xC1, 0x41, 0x47, 0xF1, 0x1A, 0x37, 0x47, 0x78, 0xC5,
		0x40, 0x7A, 0x28, 0xA6, 0xF1, 0x44, 0x14, 0x8E, 0x88, 0x15, 0xAE, 0xF0, 0x91, 0x0F, 0x6A, 0xE3, 0x9D, 0x9B, 0x71, 0x99,
		0x02, 0x34, 0xE8, 0x5F, 0x02, 0xB5, 0x6F, 0x45, 0x2A, 0x5A, 0xEF, 0x4B, 0xD2, 0x7A, 0xEF, 0x4B, 0x53, 0x58, 0x73, 0xA4,
		0x1A, 0x1B, 0x15, 0xE8, 0x04, 0xC2, 0xC3, 0x65, 0xA5, 0x0B, 0x16, 0xCC, 0x26, 0xF0, 0x26, 0xDB, 0xCA, 0x4A, 0x37, 0x03,
		0x79, 0x64, 0x0D, 0x2A, 0xBA, 0x57, 0x61, 0xBD, 0xFC, 0xE7, 0x0D, 0xCD, 0x72, 0xF9, 0xDE, 0xAB, 0x87, 0x54, 0x8F, 0x0E,
		0x26, 0xD5, 0x8A, 0x78, 0x15, 0x6C, 0x4B, 0xDB, 0x15, 0x6C, 0x4B, 0xDB, 0x15, 0x6C, 0x4B, 0xDB, 0x95, 0x12, 0xF0, 0xF9,
		0x1D, 0x10, 0x9F, 0xC3, 0xA8, 0x84, 0xB0, 0x47, 0x58, 0x67, 0x94, 0x58, 0x6D, 0x8A, 0xFE, 0x64, 0xDA, 0x71, 0xCF, 0x2D,
		0xDA, 0xD3, 0x6D, 0x83, 0xE2, 0x07, 0x1F, 0x47, 0xB7, 0x1B, 0xAF, 0x88, 0x21, 0xDE, 0x8C, 0x98, 0x52, 0xA8, 0x70, 0x32,
		0x92, 0x80, 0x1B, 0x00, 0xFD, 0x49, 0x32, 0xF0, 0x1E, 0xB8, 0xDB, 0x65, 0x33, 0x93, 0x93, 0x8E, 0xA0, 0x97, 0xEF, 0xA7,
		0xE3, 0xD2, 0x84, 0x49, 0x2C, 0xE0, 0xD9, 0xC0, 0x59, 0xF8, 0xCD, 0x62, 0x83, 0xEF, 0x7B, 0x55, 0x5D, 0x6B, 0x7F};

#pragma pack(push, 1)
typedef struct
{
	void *code_ptr;

	union
	{
		struct
		{
			DWORD Param1;
			DWORD Param2;
			DWORD Param3;
			DWORD Param4;
			DWORD Param5;
			DWORD Param6;
		} std;
		struct
		{
			DWORD dest;
			DWORD src;
			DWORD Param3;
			DWORD Param4;
			DWORD Param5;
			DWORD Param6;
		} arithmetic;
		struct
		{
			DWORD compare_me;
			DWORD with_value;
			DWORD if_equal;
			DWORD if_not_equal;
			DWORD Param5;
			DWORD Param6;
		} cmp;
	};

} VirtualMachine_t;
#pragma pack(pop)

#define SET_LABEL_ADDR(param, label_addr)   \
	{                                       \
		DWORD addr;                         \
		__asm { mov addr, offset label_addr} \
		param = addr;                       \
	}

#endif // USE_SECUROM_MARKERS_API

#endif // SECUROM_SDK_H
