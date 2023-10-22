/*---------------------------------------------------------------------------------
---------------------------------------------------------------------------------*/

#include "nds.h"
#include <nds/arm9/console.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usbhal.h"
#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"
#include "usbcore.h"
#include "debug.h"






//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------
	
	sysSetBusOwners(1,1);
	
	videoSetMode(0);	//not using the main screen
	// Enable console
	videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE);
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	REG_BG0CNT_SUB = BG_MAP_BASE(4) | BG_COLOR_16 | BG_TILE_BASE(6) | BG_PRIORITY(0);
	consoleInit(NULL, 0, BgType_Text4bpp, BgSize_T_256x256, 4, 6, false, true);
		
	printf("NDS Mouse V1.2\n");

	u16 tmp=*(vu16*)0x04000204;
	tmp&=~0x1F;
	tmp|=0x1A;
	*(vu16*)0x04000204=tmp;
	D14_ID;
	D14_ID;
	D14_ID;
	D14_ID;

	if(D14_ID!=0x8151) {
		printf("USBCard init failed!\n");
		while(1);
	}

	printf("USBCard init ok!\n");

	D14USBInit();

	USB_Connect(1);

	while(1) { USB_ISR(); }

	return 0;
}

