#ifndef __HIDUSER_H__
#define __HIDUSER_H__


/* HID Number of Reports */
#define HID_REPORT_NUM      1

/* HID Global Variables */
extern BYTE HID_Protocol;
extern BYTE HID_IdleTime[HID_REPORT_NUM];

/* HID Requests Callback Functions */
extern BOOL HID_GetReport   (void);
extern BOOL HID_SetReport   (void);
extern BOOL HID_GetIdle     (void);
extern BOOL HID_SetIdle     (void);
extern BOOL HID_GetProtocol (void);
extern BOOL HID_SetProtocol (void);

extern BYTE InReport[3];
extern BYTE OutReport;
void GetInReport();
void SetOutReport();

#endif  /* __HIDUSER_H__ */

