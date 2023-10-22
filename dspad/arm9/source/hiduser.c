#include <nds.h>
#include "usb.h"
#include "hid.h"
#include "usbcfg.h"
#include "usbcore.h"
#include "hiduser.h"


BYTE InReport[3];
BYTE OutReport;


BYTE HID_Protocol;
BYTE HID_IdleTime[HID_REPORT_NUM];


void GetInReport()
{
	u32 keys;
	scanKeys();
	keys = keysHeld();

	InReport[0]=128;
	InReport[1]=128;
	InReport[2]=0;
	
	if( keys & KEY_LEFT )InReport[0]=0;
	if( keys & KEY_RIGHT )InReport[0]=255;
	if( keys & KEY_UP )InReport[1]=0;
	if( keys & KEY_DOWN )InReport[1]=255;
	if( keys & KEY_A )InReport[2]|=1<<0;
	if( keys & KEY_B )InReport[2]|=1<<1;
	if( keys & KEY_X )InReport[2]|=1<<2;
	if( keys & KEY_Y )InReport[2]|=1<<3;
	if( keys & KEY_START )InReport[2]|=1<<4;
	if( keys & KEY_SELECT )InReport[2]|=1<<5;
	if( keys & KEY_L )InReport[2]|=1<<6;
	if( keys & KEY_R )InReport[2]|=1<<7;
	
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
