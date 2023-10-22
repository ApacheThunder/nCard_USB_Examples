#include "usbhw.h"
#include "usbcfg.h"


TUSB_Init  						USB_Init                      =0;
TUSB_Connect                    USB_Connect                   =0;
TUSB_Reset                      USB_Reset                     =0;
TUSB_Suspend                    USB_Suspend                   =0;
TUSB_Resume                     USB_Resume                    =0;
TUSB_WakeUp                     USB_WakeUp                    =0;
TUSB_WakeUpCfg                  USB_WakeUpCfg                 =0;
TUSB_SetAddress                 USB_SetAddress                =0;
TUSB_Configure                  USB_Configure                 =0;
TUSB_ConfigEP                   USB_ConfigEP                  =0;
TUSB_DirCtrlEP                  USB_DirCtrlEP                 =0;
TUSB_EnableEP                   USB_EnableEP                  =0;
TUSB_DisableEP                  USB_DisableEP                 =0;
TUSB_ResetEP                    USB_ResetEP                   =0;
TUSB_SetStallEP                 USB_SetStallEP                =0;
TUSB_ClrStallEP                 USB_ClrStallEP                =0;
TUSB_ReadEP                     USB_ReadEP                    =0;
TUSB_WriteEP                    USB_WriteEP                   =0;
TUSB_GetFrame                   USB_GetFrame                  =0;
TUSB_ReadInterruptRegister      USB_ReadInterruptRegister     =0;
TUSB_ReadLastTransactionStatus  USB_ReadLastTransactionStatus =0;
TUSB_ReadEndpointStatus         USB_ReadEndpointStatus        =0;
TUSB__SelectEndpoint            USB__SelectEndpoint           =0;
TUSB_AcknowledgeEndpoint        USB_AcknowledgeEndpoint       =0;
TUSB_AcknowledgeSETUP           USB_AcknowledgeSETUP          =0;
TUSB_ClrBufEP                   USB_ClrBufEP                  =0;


u32 USB_MAX_PACKET0=64;

void D14USBInit()
{
	USB_MAX_PACKET0=64;
	USB_Init                      =D14_Init                     ;
	USB_Connect                   =D14_Connect                  ;
	USB_Reset                     =D14_Reset                    ;
	USB_Suspend                   =D14_Suspend                  ;
	USB_Resume                    =D14_Resume                   ;
	USB_WakeUp                    =D14_WakeUp                   ;
	USB_WakeUpCfg                 =D14_WakeUpCfg                ;
	USB_SetAddress                =D14_SetAddress               ;
	USB_Configure                 =D14_Configure                ;
	USB_ConfigEP                  =D14_ConfigEP                 ;
	USB_DirCtrlEP                 =D14_DirCtrlEP                ;
	USB_EnableEP                  =D14_EnableEP                 ;
	USB_DisableEP                 =D14_DisableEP                ;
	USB_ResetEP                   =D14_ResetEP                  ;
	USB_SetStallEP                =D14_SetStallEP               ;
	USB_ClrStallEP                =D14_ClrStallEP               ;
	USB_ReadEP                    =D14_ReadEP                   ;
	USB_WriteEP                   =D14_WriteEP                  ;
	USB_GetFrame                  =D14_GetFrame                 ;
	USB_AcknowledgeEndpoint       =D14_AcknowledgeEndpoint      ;
	USB_AcknowledgeSETUP          =D14_AcknowledgeSETUP         ;
	USB_ClrBufEP                  =D14_ClrBufEP                 ;
}   

