#include "D14HAL.H"

u8	D14_SPEED=D14_FULLSPEED;

void D14_SelectEndpoint(u8 EPNum)
{
	D14_EPSEL=EPADDR(EPNum);
}

void D14_Init (void)
{;}

void D14_Connect(u8 f) 
{
	u32 i;
	D14_MODE	=	D14_MODE_SRESET;
	for(i=0;i<0x1000000;i++);
	D14_MODE	=	0;
	for(i=0;i<0x1000000;i++);
	D14_INTCNT	=	D14_INTCNT_DDBGMODOUT1|D14_INTCNT_DDBGMODIN1|D14_INTCNT_CDBGMOD1|D14_INTCNT_INTLVL|D14_INTCNT_INTPOL;
	D14_IE		=	D14_IE_BRST|D14_IE_SUSP|D14_IE_RESM|D14_IE_HSSTAT|D14_IE_EP0SETUP|D14_IE_EP0OUT|D14_IE_EP0IN|D14_IE_EP1IN;
	D14_IEH		=	0x0000;
	D14_ADDR	=	0x80;
	if(f)
		D14_MODE	=	D14_MODE_SOFTCT|D14_MODE_IME|D14_MODE_CLKON;

	D14_SPEED=D14_FULLSPEED;
	D14_Configure(1);
}

void D14_Reset (void)
{
	D14_MODE	=	D14_MODE_SRESET;
	D14_MODE	=	0;
	D14_INTCNT	=	D14_INTCNT_DDBGMODOUT1|D14_INTCNT_DDBGMODIN1|D14_INTCNT_CDBGMOD1|D14_INTCNT_INTLVL|D14_INTCNT_INTPOL;
	D14_IE		=	D14_IE_BRST|D14_IE_SUSP|D14_IE_RESM|D14_IE_HSSTAT|D14_IE_EP0SETUP|D14_IE_EP0OUT|D14_IE_EP0IN|D14_IE_EP1IN;
	D14_IEH		=	0x0000;
	D14_ADDR	=	0x80;
	D14_MODE	=	D14_MODE_SOFTCT|D14_MODE_IME|D14_MODE_CLKON;
	D14_SPEED=D14_FULLSPEED;
	D14_Configure(1);
}


void D14_Suspend (void) 
{;}
void D14_Resume (void) 
{;}
void D14_WakeUp (void) 
{;}
void D14_WakeUpCfg (u8 cfg) 
{;}
void D14_SetAddress (u8 addr) 
{
	D14PORT(0x00)=0x0080|addr;
}
void D14_Configure (u8 cfg)
{
	//必须先配置好 功能，再配置内存 最后打开 否则无法收到中断
	if(D14_SPEED==D14_FULLSPEED)
	{
		D14_SelectEndpoint(0x81);
		D14_EPTYPE	=	D14_EPTYPE_INT|D14_EPTYPE_DBLBUF;
		D14_EPMAX	=	0x4;

		D14_SelectEndpoint(0x81);
		D14_EPTYPE	|=	D14_EPTYPE_ENABLE;
	}
	else
	{
		D14_SelectEndpoint(0x81);
		D14_EPTYPE	=	D14_EPTYPE_INT|D14_EPTYPE_DBLBUF;
		D14_EPMAX	=	0x4;

		D14_SelectEndpoint(0x81);
		D14_EPTYPE	|=	D14_EPTYPE_ENABLE;
	}
}

void D14_ConfigEP (void *pEPD)
{;}
void D14_DirCtrlEP (u32 dir) 
{;}
void D14_EnableEP (u8 EPNum)
{
	D14_SelectEndpoint(EPNum);
	D14_EPCNT	=	0;
	D14_EPTYPE	&=	~D14_EPTYPE_ENABLE;
	D14_EPTYPE	|=	D14_EPTYPE_ENABLE;
}
void D14_DisableEP (u8 EPNum)
{
	D14_SelectEndpoint(EPNum);
	D14_EPCNT	=	D14_EPCNT_STALL;
	D14_EPTYPE	&=	~D14_EPTYPE_ENABLE;
}
void D14_ResetEP (u8 EPNum)
{
	D14_SelectEndpoint(EPNum);
	D14_EPCNT	=	0;
	D14_EPTYPE	&=	~D14_EPTYPE_ENABLE;
	D14_EPTYPE	|=	D14_EPTYPE_ENABLE;
}
void D14_SetStallEP (u8 EPNum)
{
	D14_SelectEndpoint(EPNum);
	D14_EPCNT	=	D14_EPCNT_STALL;
}
void D14_ClrStallEP (u8 EPNum)
{
	D14_SelectEndpoint(EPNum);
	D14_EPCNT	=	0;
	D14_EPTYPE	&=	~D14_EPTYPE_ENABLE;
	D14_EPTYPE	|=	D14_EPTYPE_ENABLE;
}
u16 D14_GetFrame (void)
{
	return D14_FRAME;
}
void D14_AcknowledgeEndpoint(u8 EPNum)	//应答SETUP
{
	D14_SelectEndpoint(EPNum);
	D14_EPCNT	=	D14_EPCNT_STATUS;
}
void D14_AcknowledgeSETUP(void)
{
	D14_AcknowledgeEndpoint(0);
}

#pragma pack(1)
u16 D14_ReadEP (u8 EPNum, u8 *pData) 
{
	register u16 len,i,data;
	u8 half;
	D14_SelectEndpoint(EPNum);
	len=D14_EPLEN;
	if(!len)return 0;
	half=len%2;

	for(i=0;i<len/2;i++)
	{
		data=D14_EPDAT;
		*pData++=(u8)data;
		*pData++=(u8)(data>>8);
	}
	if(half)
	{
		data=D14_EPDAT;
		*pData=(u8)data;
	}
	return len;
}

void D14_ClrBufEP (u8 EPNum) 
{
	D14_SelectEndpoint(EPNum);
	D14_EPCNT	=	D14_EPCNT_CLBUF;
}

u16 D14_WriteEP (u8 EPNum, u8 *pData, u16 cnt)
{
	register u16 i,data;
	u8 half;
	D14_SelectEndpoint(EPNum);
	D14_EPLEN=cnt;
	half=cnt%2;
	for(i=0;i<cnt/2;i++)
	{
		data=*pData++;
		data|=(*pData++)<<8;
		D14_EPDAT=data;
	}
	if(half)
	{
		data=*pData;
		D14_EPDAT=data;
	}
	return cnt;
}
#pragma pack()

//end of file
