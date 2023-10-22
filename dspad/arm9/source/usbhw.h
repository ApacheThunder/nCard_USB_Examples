#ifndef _USBHW_H_
#define _USBHW_H_

#include "usbhal.h"
#include "usbuser.h"
#include "d14hal.h"

typedef void (*TUSB_Init) (void);
typedef void (*TUSB_Connect) (BOOL con);
typedef void (*TUSB_Reset) (void);
typedef void (*TUSB_Suspend) (void);
typedef void (*TUSB_Resume) (void);
typedef void (*TUSB_WakeUp) (void);
typedef void (*TUSB_WakeUpCfg) (BOOL cfg);
typedef void (*TUSB_SetAddress) (BYTE adr);
typedef void (*TUSB_Configure) (BOOL cfg);
typedef void (*TUSB_ConfigEP) (void *pEPD);
typedef void (*TUSB_DirCtrlEP) (DWORD dir);
typedef void (*TUSB_EnableEP) (BYTE EPNum);
typedef void (*TUSB_DisableEP) (BYTE EPNum);
typedef void (*TUSB_ResetEP) (BYTE EPNum);
typedef void (*TUSB_SetStallEP) (BYTE EPNum);
typedef void (*TUSB_ClrStallEP) (BYTE EPNum);
typedef WORD (*TUSB_ReadEP) (BYTE EPNum, BYTE *pData);
typedef WORD (*TUSB_WriteEP) (BYTE EPNum, BYTE *pData, WORD cnt);
typedef WORD (*TUSB_GetFrame) (void);
typedef WORD (*TUSB_ReadInterruptRegister)(void);
typedef BYTE (*TUSB_ReadLastTransactionStatus)(BYTE EPNum);
typedef BYTE (*TUSB_ReadEndpointStatus)(BYTE EPNum);
typedef BYTE (*TUSB__SelectEndpoint)(BYTE EPNum);
typedef void (*TUSB_AcknowledgeEndpoint)(BYTE EPNum);
typedef void (*TUSB_AcknowledgeSETUP)(void);
typedef void (*TUSB_ClrBufEP) (BYTE EPNum);

TUSB_Init  						USB_Init                     ;
TUSB_Connect                    USB_Connect                  ;
TUSB_Reset                      USB_Reset                    ;
TUSB_Suspend                    USB_Suspend                  ;
TUSB_Resume                     USB_Resume                   ;
TUSB_WakeUp                     USB_WakeUp                   ;
TUSB_WakeUpCfg                  USB_WakeUpCfg                ;
TUSB_SetAddress                 USB_SetAddress               ;
TUSB_Configure                  USB_Configure                ;
TUSB_ConfigEP                   USB_ConfigEP                 ;
TUSB_DirCtrlEP                  USB_DirCtrlEP                ;
TUSB_EnableEP                   USB_EnableEP                 ;
TUSB_DisableEP                  USB_DisableEP                ;
TUSB_ResetEP                    USB_ResetEP                  ;
TUSB_SetStallEP                 USB_SetStallEP               ;
TUSB_ClrStallEP                 USB_ClrStallEP               ;
TUSB_ReadEP                     USB_ReadEP                   ;
TUSB_WriteEP                    USB_WriteEP                  ;
TUSB_GetFrame                   USB_GetFrame                 ;
TUSB_ReadInterruptRegister      USB_ReadInterruptRegister    ;
TUSB_ReadLastTransactionStatus  USB_ReadLastTransactionStatus;
TUSB_ReadEndpointStatus         USB_ReadEndpointStatus       ;
TUSB__SelectEndpoint            USB__SelectEndpoint          ;
TUSB_AcknowledgeEndpoint        USB_AcknowledgeEndpoint      ;
TUSB_AcknowledgeSETUP           USB_AcknowledgeSETUP         ;
TUSB_ClrBufEP                   USB_ClrBufEP                 ;
                  
u32 USB_MAX_PACKET0;
void D14USBInit();
#endif //_USBHW_H_
