#include <nds.h>
#include "usb.h"
#include "hid.h"
#include "usbcfg.h"
#include "usbcore.h"
#include "hiduser.h"
#include <nds/touch.h>


BYTE InReport[3];
BYTE OutReport;


BYTE HID_Protocol;
BYTE HID_IdleTime[HID_REPORT_NUM];

u32 lasttouchkey=0;
u32 lasttouchx=0;
u32 lasttouchy=0;
u32 touchcount=0;
u32 touchsumxy=0;
u32 touchmove=0;
void GetInReport()
{
	u32 keys;
	touchPosition touchXY;
	scanKeys();
	keys = keysHeld();
	touchRead(&touchXY);


	InReport[0]=0;
	InReport[1]=0;
	InReport[2]=0;


	if(keys & KEY_TOUCH) {
		if(lasttouchkey) {
			u32 sp=2;
			u32 ax,ay;
			if( keys & KEY_UP )sp=3;
			if( keys & KEY_DOWN )sp=1;

			ax=(touchXY.px*sp)-(lasttouchx*sp);
			ay=(touchXY.py*sp)-(lasttouchy*sp);
			InReport[1]=ax;
			InReport[2]=ay;


			sp=1;
			ax=(touchXY.px*sp)-(lasttouchx*sp);
			ay=(touchXY.py*sp)-(lasttouchy*sp);

			if(ax&0x80000000)ax=0-ax;
			if(ay&0x80000000)ay=0-ay;
			touchsumxy+=ax+ay;

			if((touchcount>150)&&(touchsumxy<60))touchmove=1;
		}
	} else {
		if(lasttouchkey) {
			if(touchsumxy<20) { if(touchcount<100)InReport[0]|=1<<0; }
		}
	}
	
	if( keys & KEY_LEFT )InReport[0]|=1<<0;
	if( keys & KEY_RIGHT )InReport[0]|=1<<1;

	if( keys & KEY_A )InReport[0]|=1<<1;
	if( keys & KEY_B )InReport[0]|=1<<0;
	if( keys & KEY_X )InReport[0]|=1<<1;
	if( keys & KEY_Y )InReport[0]|=1<<0;
	if( keys & KEY_R )InReport[0]|=1<<1;
	if( keys & KEY_L )InReport[0]|=1<<0;

	if(touchmove)InReport[0]|=1<<0;

	if(keys & KEY_TOUCH) {
		touchcount++;
		lasttouchkey=1;
		lasttouchx=touchXY.px;
		lasttouchy=touchXY.py;		
	} else {
		touchcount=0;
		lasttouchkey=0;
		lasttouchx=0;
		lasttouchy=0;
		touchsumxy=0;
		touchmove=0;
	}
	
}
void SetOutReport()
{
	;
}


/*
 *  HID Get Report Request Callback
 *   Called automatically on HID Get Report Request
 *    Parameters:      None (global SetupPacket and EP0Buf)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_GetReport (void) {

  /* ReportID = SetupPacket.wValue.WB.L; */
  switch (SetupPacket.wValue.WB.H) {
    case HID_REPORT_INPUT:
      GetInReport();
      EP0Buf[0] = InReport[0];
	  EP0Buf[1] = InReport[1];
	  EP0Buf[2] = InReport[2];
      break;
    case HID_REPORT_OUTPUT:
      return (FALSE);          /* Not Supported */
    case HID_REPORT_FEATURE:
      /* EP0Buf[] = ...; */
      /* break; */
      return (FALSE);          /* Not Supported */
  }
  return (TRUE);
}


/*
 *  HID Set Report Request Callback
 *   Called automatically on HID Set Report Request
 *    Parameters:      None (global SetupPacket and EP0Buf)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_SetReport (void) {

  /* ReportID = SetupPacket.wValue.WB.L; */
  switch (SetupPacket.wValue.WB.H) {
    case HID_REPORT_INPUT:
      return (FALSE);          /* Not Supported */
    case HID_REPORT_OUTPUT:
      OutReport = EP0Buf[0];
      SetOutReport();
      break;
    case HID_REPORT_FEATURE:
      return (FALSE);          /* Not Supported */
  }
  return (TRUE);
}


/*
 *  HID Get Idle Request Callback
 *   Called automatically on HID Get Idle Request
 *    Parameters:      None (global SetupPacket and EP0Buf)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_GetIdle (void) {

  EP0Buf[0] = HID_IdleTime[SetupPacket.wValue.WB.L];
  return (TRUE);
}


/*
 *  HID Set Idle Request Callback
 *   Called automatically on HID Set Idle Request
 *    Parameters:      None (global SetupPacket)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_SetIdle (void) {

  HID_IdleTime[SetupPacket.wValue.WB.L] = SetupPacket.wValue.WB.H;

  /* Idle Handling if needed */
  /* ... */

  return (TRUE);
}


/*
 *  HID Get Protocol Request Callback
 *   Called automatically on HID Get Protocol Request
 *    Parameters:      None (global SetupPacket)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_GetProtocol (void) {

  EP0Buf[0] = HID_Protocol;
  return (TRUE);
}


/*
 *  HID Set Protocol Request Callback
 *   Called automatically on HID Set Protocol Request
 *    Parameters:      None (global SetupPacket)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

BOOL HID_SetProtocol (void) {

  HID_Protocol = SetupPacket.wValue.WB.L;

  /* Protocol Handling if needed */
  /* ... */

  return (TRUE);
}
//end of file
