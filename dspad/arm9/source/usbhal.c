#include "usbhal.h"

#ifdef ARM9
__inline
void usbwrcmd(u8 val)				//D12Ð´ÃüÁî
{
	//*(vu8*)(0x0A000000+val) = 0xFF;
	*(vu16*)(0x09FFFFFE) = val;
}
__inline
void usbwrdat(u8 val)				//D12Ð´Êý¾Ý
{
	//*(vu8*)(0x0A000000+val) = 0xFE;
	*(vu16*)(0x09FDFFFE) = val;
}
__inline
u8 usbrddat()			//D12¶Á
{
	//*(vu8*)(0x0A00FFFF) = 0xFE;
	return *(vu16*)(0x09FDFFFE);
}

u16 usbreadid()
{
	u16 id=0;
	usbwrcmd(0xFD);
	id=usbrddat();
	id|=(u16)usbrddat()<<8;
	return id;
}
#else


void usbwrcmd(u8 val)				//D12Ð´ÃüÁî
{
	*(vu8*)(0x08020000) = val;
}

void usbwrdat(u8 val)				//D12Ð´Êý¾Ý
{
	*(vu8*)(0x08000000) = val;
}

u8 usbrddat()			//D12¶Á
{
	return *(vu8*)(0x08000000);
}

u16 usbreadid()
{
	u16 id=0;
	usbwrcmd(0xFD);
	id=usbrddat();
	id|=(u16)usbrddat()<<8;
	return id;
}

#endif



