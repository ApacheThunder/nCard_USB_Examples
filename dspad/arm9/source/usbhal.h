#ifndef _USBHAL_H_
#define _USBHAL_H_

#ifdef ARM9
	#include <nds.h>
#else
	#include <gba.h>
#endif

#include <stdio.h>
#define BOOL	u8
#define WORD	u16
#define DWORD	u32
#define BYTE	u8
#define TRUE	1
#define FALSE	0

void usbwrcmd(u8 val);
void usbwrdat(u8 val);
u8 usbrddat();

u16 usbreadid();

//#define disable()		;
//#define enable()		;

#define D12_ID		0x1012

#define	nop()	 __asm __volatile ("nop\n")

#endif //_USBHAL_H_
