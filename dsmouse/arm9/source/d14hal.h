#ifndef _D14HAL_H_
#define _D14HAL_H_

/*
#define u16				unsigned short
#define u8				unsigned char
#define vu16			unsigned short
#define vu8				unsigned char
#define BIT(a)			(1<<(a))
*/
#include <nds.h>

#define D14_FULLSPEED	0
#define D14_HIGHSPEED	1
extern u8				D14_SPEED;

#define D14_BASE		0x08000000

#define D14PORT(addr)	(*(vu16*)(D14_BASE|((addr)*0x20000)))

#define EPADDR(addr)	(((addr&0x80)?((addr)<<1)|1:((addr)<<1))&0xFF)

#define D14_ADDR		D14PORT(0x00)
#define D14_MODE		D14PORT(0x0C)
#define D14_INTCNT		D14PORT(0x10)
#define D14_IE			D14PORT(0x14)
#define D14_IEH			D14PORT(0x16)
#define D14_EPSEL		D14PORT(0x2C)
#define D14_EPCNT		D14PORT(0x28)
#define D14_EPDAT		D14PORT(0x20)
#define D14_EPLEN		D14PORT(0x1C)
#define D14_EPMAX		D14PORT(0x04)
#define D14_EPTYPE		D14PORT(0x08)
#define D14_EPSHORT		D14PORT(0x24)
#define D14_IF			D14PORT(0x18)
#define D14_IFH			D14PORT(0x1A)
#define D14_ID			D14PORT(0x70)
#define D14_FRAME		D14PORT(0x74)
#define D14_REG			D14PORT(0X78)
#define D14_UNLOCK		D14PORT(0X7C)
#define D14_TEST		D14PORT(0X84)

/*D14_ADDR*/
#define D14_ADDR_EN				BIT(7)

/*D14_MODE*/
#define D14_MODE_CLKON			BIT(7)
#define D14_MODE_SNDRSU			BIT(6)
#define D14_MODE_GOSUSP			BIT(5)
#define D14_MODE_SRESET			BIT(4)
#define D14_MODE_IME			BIT(3)
#define D14_MODE_WKUPCS			BIT(2)
#define D14_MODE_SOFTCT			BIT(0)

/*D14_INTCNT*/
#define D14_INTCNT_DDBGMODOUT0	0
#define D14_INTCNT_DDBGMODOUT1	BIT(2)
#define D14_INTCNT_DDBGMODOUT2	BIT(3)|BIT(2)
#define D14_INTCNT_DDBGMODIN0	0
#define D14_INTCNT_DDBGMODIN1	BIT(4)
#define D14_INTCNT_DDBGMODIN2	BIT(5)|BIT(4)
#define D14_INTCNT_CDBGMOD0		0
#define D14_INTCNT_CDBGMOD1		BIT(6)
#define D14_INTCNT_CDBGMOD2		BIT(7)|BIT(6)
#define D14_INTCNT_INTLVL		BIT(1)
#define D14_INTCNT_INTPOL		BIT(0)	

/*D14_IE*/
#define D14_IE_BRST				BIT(0)
#define D14_IE_SOF				BIT(1)
#define D14_IE_PSOF				BIT(2)
#define D14_IE_SUSP				BIT(3)
#define D14_IE_RESM				BIT(4)
#define D14_IE_HSSTAT			BIT(5)
#define D14_IE_DMA				BIT(6)
#define D14_IE_EP0SETUP			BIT(8)
#define D14_IE_EP0OUT			BIT(10)
#define D14_IE_EP0IN			BIT(11)
#define D14_IE_EP1OUT			BIT(12)
#define D14_IE_EP1IN			BIT(13)
#define D14_IE_EP2OUT			BIT(14)
#define D14_IE_EP2IN			BIT(15)
#define D14_IE_EP3OUT			BIT(16)
#define D14_IE_EP3IN			BIT(17)
#define D14_IE_EP4OUT			BIT(18)
#define D14_IE_EP4IN			BIT(19)
#define D14_IE_EP5OUT			BIT(20)
#define D14_IE_EP5IN			BIT(21)
#define D14_IE_EP6OUT			BIT(22)
#define D14_IE_EP6IN			BIT(23)

/*D14_IF*/
#define D14_IF_BRST				BIT(0)
#define D14_IF_SOF				BIT(1)
#define D14_IF_PSOF				BIT(2)
#define D14_IF_SUSP				BIT(3)
#define D14_IF_RESM				BIT(4)
#define D14_IF_HSSTAT			BIT(5)
#define D14_IF_DMA				BIT(6)
#define D14_IF_EP0SETUP			BIT(8)
#define D14_IF_EP0OUT			BIT(10)
#define D14_IF_EP0IN			BIT(11)
#define D14_IF_EP1OUT			BIT(12)
#define D14_IF_EP1IN			BIT(13)
#define D14_IF_EP2OUT			BIT(14)
#define D14_IF_EP2IN			BIT(15)
#define D14_IF_EP3OUT			BIT(16)
#define D14_IF_EP3IN			BIT(17)
#define D14_IF_EP4OUT			BIT(18)
#define D14_IF_EP4IN			BIT(19)
#define D14_IF_EP5OUT			BIT(20)
#define D14_IF_EP5IN			BIT(21)
#define D14_IF_EP6OUT			BIT(22)
#define D14_IF_EP6IN			BIT(23)

/*D14_EPSEL*/
#define D14_EPSEL_DIR			BIT(0)
#define D14_EPSEL_SETUP			BIT(5)

/*D14_EPCNT*/
#define D14_EPCNT_CLBUF			BIT(4)
#define D14_EPCNT_VENDP			BIT(3)
#define D14_EPCNT_STATUS		BIT(1)
#define D14_EPCNT_STALL			BIT(0)

/*D14_EPTYPE*/
#define D14_EPTYPE_NONE			0
#define D14_EPTYPE_SYNC			BIT(0)
#define D14_EPTYPE_BULK			BIT(1)
#define D14_EPTYPE_INT			(BIT(1)|BIT(0))
#define D14_EPTYPE_DBLBUF		BIT(2)
#define D14_EPTYPE_ENABLE		BIT(3)
#define D14_EPTYPE_NOEMPKT		BIT(4)

/*D14_UNLOCK*/
#define D14_UNLOCK_KEY			0xAA37

/*D14_TEST*/
#define D14_TEST_SE0_NAK		BIT(0)
#define D14_TEST_JSTATE			BIT(1)
#define D14_TEST_KSTATE			BIT(2)
#define D14_TEST_PRBS			BIT(3)
#define D14_TEST_FORCEFS		BIT(4)
#define D14_TEST_FORCEHS		BIT(7)

void D14_SelectEndpoint(u8 EPNum);
void D14_Init (void);
void D14_Connect(u8 f);
void D14_Reset (void);
void D14_Suspend (void);
void D14_Resume (void);
void D14_WakeUp (void);
void D14_WakeUpCfg (u8 cfg);
void D14_SetAddress (u8 addr);
void D14_Configure (u8 cfg);
void D14_ConfigEP (void *pEPD);
void D14_DirCtrlEP (u32 dir);
void D14_EnableEP (u8 EPNum);
void D14_DisableEP (u8 EPNum);
void D14_ResetEP (u8 EPNum);
void D14_SetStallEP (u8 EPNum);
void D14_ClrStallEP (u8 EPNum);
u16	 D14_GetFrame (void);
void D14_AcknowledgeEndpoint(u8 EPNum);
void D14_AcknowledgeSETUP(void);
u16  D14_ReadEP (u8 EPNum, u8 *pData);
void D14_ClrBufEP (u8 EPNum);
u16  D14_WriteEP (u8 EPNum, u8 *pData, u16 cnt);

#endif//_D14HAL_H_
