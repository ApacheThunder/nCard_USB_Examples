#ifndef _USBDESC_H_
#define _USBDESC_H_

#include "usbhal.h"

#define WBVAL(x) (x & 0xFF),((x >> 8) & 0xFF)

#define USB_DEVICE_DESC_SIZE        (sizeof(USB_DEVICE_DESCRIPTOR))
#define USB_CONFIGUARTION_DESC_SIZE (sizeof(USB_CONFIGURATION_DESCRIPTOR))
#define USB_INTERFACE_DESC_SIZE     (sizeof(USB_INTERFACE_DESCRIPTOR))
#define USB_ENDPOINT_DESC_SIZE      (sizeof(USB_ENDPOINT_DESCRIPTOR))


#define HID_DESC_OFFSET              0x0012
#define HID_DESC_SIZE               (sizeof(HID_DESCRIPTOR))
#define HID_REPORT_DESC_SIZE        (sizeof(HID_ReportDescriptor))

extern BYTE USB_ConfigDescriptor[];
extern BYTE USB_StringDescriptor[];
extern BYTE USB_DeviceDescriptor[];

extern BYTE HID_ReportDescriptor[];
extern WORD HID_ReportDescSize;

#endif //_USBDESC_H_
