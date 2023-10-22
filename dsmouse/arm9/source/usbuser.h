#ifndef _USBUSER_H_
#define _USBUSER_H_

#include "usbhal.h"
#include "usbcfg.h"


/* USB Endpoint Callback Events */
#define USB_EVT_SETUP       1   /* Setup Packet */
#define USB_EVT_OUT         2   /* OUT Packet */
#define USB_EVT_IN          3   /*  IN Packet */
#define USB_EVT_OUT_NAK     4   /* OUT Packet - Not Acknowledged */
#define USB_EVT_IN_NAK      5   /*  IN Packet - Not Acknowledged */
#define USB_EVT_OUT_STALL   6   /* OUT Packet - Stalled */
#define USB_EVT_IN_STALL    7   /*  IN Packet - Stalled */
#define USB_EVT_OUT_DMA_EOT 8   /* DMA OUT EP - End of Transfer */
#define USB_EVT_IN_DMA_EOT  9   /* DMA  IN EP - End of Transfer */
#define USB_EVT_OUT_DMA_NDR 10  /* DMA OUT EP - New Descriptor Request */
#define USB_EVT_IN_DMA_NDR  11  /* DMA  IN EP - New Descriptor Request */
#define USB_EVT_OUT_DMA_ERR 12  /* DMA OUT EP - Error */
#define USB_EVT_IN_DMA_ERR  13  /* DMA  IN EP - Error */

extern void USB_Configure_Event (void);

extern void (* const USB_P_EP[USB_EP_NUM/2]) (BYTE event);
extern void USB_EndPoint0 (BYTE event);
extern void USB_EndPoint1 (BYTE event);
extern void USB_EndPoint2 (BYTE event);

extern void USB_ISR(void);
extern void USB_MAIN(void);

#endif //_USBUSER_H_
