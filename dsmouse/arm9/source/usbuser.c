#include "usbhw.h"
#include "usbcore.h"
#include "usbuser.h"
#include "hiduser.h"
#include <stdio.h>

/* USB Endpoint Events Callback Pointers */
void (* const USB_P_EP[USB_EP_NUM/2]) (BYTE event) = {
  USB_EndPoint0,
  USB_EndPoint1,
  USB_EndPoint2,
};

void USB_Configure_Event (void) 
{
	if (USB_Configuration)
	{
		GetInReport();
		USB_WriteEP(0x81, InReport, 3);
	}
}

void USB_EndPoint1 (BYTE event) 
{
	switch (event) 
	{
		case USB_EVT_IN:
			GetInReport();
			USB_WriteEP(0x81, InReport, 3);
		break;
	}
}

void USB_EndPoint2 (BYTE event) 
{
}


u16 USB_IF=0;
void USB_ISR()
{
	USB_IF|=D14_IF;
	D14_IF=USB_IF;

	if(USB_IF&D14_IF_BRST)
	{
		USB_Reset();
		USB_IF&=~D14_IF_BRST;
	}

	if(USB_IF&D14_IF_SUSP)
	{
		USB_Suspend();
		USB_IF&=~D14_IF_SUSP;
	}

	if(USB_IF&D14_IF_EP0SETUP)
	{
		USB_P_EP[0](USB_EVT_SETUP);	
		USB_IF&=~D14_IE_EP0SETUP;
	}

	if(USB_IF&D14_IF_EP0OUT)
	{
		USB_P_EP[0](USB_EVT_OUT);	
		USB_IF&=~D14_IF_EP0OUT;
	}

	if(USB_IF&D14_IF_EP0IN)
	{
		USB_P_EP[0](USB_EVT_IN);	
		USB_IF&=~D14_IF_EP0IN;
	}

	if(USB_IF&D14_IF_EP1IN)
	{
		USB_P_EP[1](USB_EVT_IN);	
		USB_IF&=~D14_IF_EP1IN;
	}
}

//end of file
