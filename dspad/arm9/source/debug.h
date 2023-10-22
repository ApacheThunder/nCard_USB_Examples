#ifdef ARM9

#else
#include<gba.h>
#endif

#define consolecls()		iprintf ("%c[222J",0x1B)
#define consolesetxy(x,y)	iprintf ("%c[%d;%dH",0x1B,x,y)
#define testb(c,b)			(c&b)
#define REG_KEY				*(volatile u16*)0x4000130

void delay();
void showmem(u32 base);


