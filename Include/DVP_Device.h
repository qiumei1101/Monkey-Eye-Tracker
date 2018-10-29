#ifndef _CGIMAGETECH_CAMAPI_H_
#define _CGIMAGETECH_CAMAPI_H_

#include <DVP_DeviceDefine.h>

#ifdef CGUSBDEVICE_EXPORTS 
	#define CG_API extern "C" __declspec(dllexport)
#else 
	#define CG_API extern "C" __declspec(dllimport)
#endif

typedef void		*HDEVICE;				//相机设备句柄
typedef HDEVICE		*PHDEVICE;				//指向相机设备句柄的指针

/*---------------------------------------------------------------------------------------*\
| 函数序号：1
| 功  能：获取SDK版本号
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：
|         1  DWORD  adwVersion			SDK版本号			输出参数
\*--------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceGetSDKVersion(DWORD adwVersion[4]);

/*--------------------------------------------------------------------------------------*\
| 函数序号：2
| 功  能：初始化SDK
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：                                                            
|         1  HANDLE		handle		事件通知窗口句柄	 输入参数
|		  2  BOOL		bUsedStatus 启用设备使用标记	 输入参数
|         3  BOOL       bPNP		启用即插即用         输入参数
| 注意： 当设备需要使用即插即用功能时，事件通知窗口必须设置为NULL，否则不会启用该功能
\*--------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceInitialSDK(HANDLE hHandle, BOOL bUsedStatus, BOOL bPNP = FALSE);

/*--------------------------------------------------------------------------------------*\
| 函数序号：3
| 功  能：反初始化SDK
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：无                                                            
\*--------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceUnInitialSDK();

/*--------------------------------------------------------------------------------------*\
| 函数序号：4
| 功  能：枚举相机设备                                                     
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|         1  LPEnumDeviceParam	pDeviceList		相机列表的信息结构数组指针					输入参数
|         2  INT				*piNums			输入和返回相机列表数组的个数指标			输入参数
\*--------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall EnumDevice(LPEnumDeviceParam pDeviceList, INT *piNums);

/*--------------------------------------------------------------------------------------*\
| 函数序号：5
| 功  能：打开相机设备                                                     
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数： 
|         1  PHDEVICE			pDevice			设备句柄指针		输出参数
\*--------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SmartOpenDevice(PHDEVICE pDevice);

/*--------------------------------------------------------------------------------------*\
| 函数序号：6
| 功  能：打开指定相机设备                                                     
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码	
|
| 参  数： 
|         1  UionOpenDeviceParam	param			打开相机的参数结构	 输入参数
|         2  PHDEVICE				pDevice			设备句柄指针		 输出参数
|		  3  OpenDeviceFlag			flag			打开设备的方式		 输入参数
\*--------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall OpenDevice(UionOpenDeviceParam param, PHDEVICE pDevice, emOpenDeviceFlag flag = OF_BYPOSITION);

/*-------------------------------------------------------------------------------------*\
| 函数序号：7
| 功  能：打开指定相机设备（相机序列方式）                                                     
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码	
|
| 参  数： 
|         1  UCHAR					devIndex		相机设备对应序列	 输入参数
|         2  PHDEVICE				pDevice			设备句柄指针		 输出参数
\*-------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall OpenDeviceByIndex(UCHAR devIndex, PHDEVICE pDevice);

/*-------------------------------------------------------------------------------------*\
| 函数序号：8
| 功  能：打开指定相机设备(相机USB地址方式）                                                     
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码	
|
| 参  数： 
|         1  UCHAR					devUSBAddr		相机设备的USB地址	 输入参数
|         2  PHDEVICE				pDevice			设备句柄指针		 输出参数
\*------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall OpenDeviceByUSBAddress(UCHAR devUSBAddr, PHDEVICE pDevice);

/*------------------------------------------------------------------------------------*\
| 函数序号：9
| 功  能：打开指定相机设备(用户设置的序列号方式）                                              
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数： 
|         1  BYTE					devUserSN[32]		用户设置的序列号	 输入参数
|         2  PHDEVICE				pDevice				设备句柄指针		 输出参数
\*------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall OpenDeviceByUserSN(BYTE devUserSN[32], PHDEVICE pDevice);

/*------------------------------------------------------------------------------------*\
| 函数序号：10
| 功  能：打开指定相机设备(开发者设置的序列号方式）                                              
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数： 
|         1  BYTE					devDeveloperSN[32]	开发者设置的序列号	 输入参数
|         2  PHDEVICE				pDevice				设备句柄指针		 输出参数
\*------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall OpenDeviceByDeveloperSN(BYTE devDeveloperSN[32], PHDEVICE pDevice);

/*------------------------------------------------------------------------------------*\
| 函数序号：11
| 功  能：打开指定相机设备(出厂唯一序列号方式）                                              
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数： 
|         1  BYTE					devFactorySN[32]	出厂唯一序列号		 输入参数
|         2  PHDEVICE				pDevice				设备句柄指针		 输出参数
\*------------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall OpenDeviceByFactorySN(BYTE devFactorySN[32], PHDEVICE pDevice);

/*------------------------------------------------------------------------------------*\
| 函数序号：12
| 功  能：增加相机的引用                                                     
|                                                                          
| 返回值：返回上一次的引用数，句柄无效时返回-1
|
| 参  数：                                                             
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
\*-----------------------------------------------------------------------------------*/
CG_API ULONG __stdcall DeviceAddReference(HDEVICE hDevice);

/*----------------------------------------------------------------------------------*\
| 函数序号：13
| 功  能：减少相机的引用                                                     
|                                                                          
| 返回值：返回上一次的引用数，句柄无效时返回-1	
| 注意： 当设备的引用数为0时，设备会自动删除
|
| 参  数：                                                             
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
\*------------------------------------------------------------------------*/
CG_API ULONG __stdcall DeviceRelease(HDEVICE hDevice);

/*------------------------------------------------------------------------*\
| 函数序号：14
| 功  能：关闭相机设备  
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：                                                             
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
\*------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall CloseDevice(HDEVICE hDevice);

/*------------------------------------------------------------------------*\
| 函数序号：15
| 功  能：同步关闭相机设备                                                     
|                                                                          
| 返回值：调用成功返回STATUS_OK，否则返回错误代码	
| 参  数：                                                             
|         1  HDEVICE		hDevice		设备接口			 输入参数
| 注意： 该函数主要用于即插即用功能时，防止多个进程之间枚举设备时的冲突。
| 如不使用即插即用功能时，则不需要调用此函数，可以直接调用CloseDevice()接口来释放设备。
\*------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SyncCloseDevice(HDEVICE hDevice);

/*------------------------------------------------------------------------*\
| 函数序号：16
| 功  能：得到设备地址 
|                                                                          
| 返回值：调用成功返回设备的地址，否则返回 0
|
| 参  数：                                                             
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
\*------------------------------------------------------------------------*/
CG_API UCHAR __stdcall GetDeviceAddress(HDEVICE hDevice);

/*------------------------------------------------------------------------*\
| 函数序号：17
| 功  能：得到设备句柄 
|                                                                          
| 返回值：调用成功返回设备的句柄，否则返回NULL
|
| 参  数：                                                             
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
\*------------------------------------------------------------------------*/
CG_API HANDLE __stdcall GetDeviceHandle(HDEVICE hDevice);

/*-----------------------------------------------------------------------*\
| 函数序号：18
| 功  能：写入相机序列号
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：
|         1  HDEVICE hDevice	 相机设备句柄							输入参数
|         2  BYTE    *pbySN      序列号数据								输入参数
|         3  INT     iSize       序列号字节数							输入参数
|         4  INT     *piWritten  实际写入的字节数						输出参数
|		  5  INT     iLevel      需要设定的序列号级别，只能是1或者2		输入参数
|
| 注  意：
|	      1、相机序列号分为3级。0级是相机唯一序列号，出厂时已经设定好，1级和2级留给二次开发使用。
|            每级序列号最大长度都是32个字节。
\*-------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall WriteSerialNumber(HDEVICE hDevice, BYTE *pbySN, INT iSize, INT *piWritten, INT iLevel = 2);

/*-------------------------------------------------------------------------*\
| 函数序号：19
| 功  能：获取相机序列号
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：
|         1  HDEVICE	hDevice	   相机设备句柄						  输入参数
|         2  BYTE		*pbySN     序列号数据                         输出参数
|         3  INT		iSize      序列号字节数                       输入参数
|         4  INT		*piReaded  实际获取的字节数                   输出参数
|		  5  INT        iLevel     需要设定的序列号级别				  输入参数
|
| 注  意：
|         1、相机序列号分为3级。0级是相机唯一序列号，出厂时已经设定好，1级和2级留给二次开发使用。
|            每级序列号最大长度都是32个字节。
\*--------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall ReadSerialNumber(HDEVICE hDevice, BYTE *pbySN, INT iSize, INT *piReaded, INT iLevel = 2);

/*-------------------------------------------------------------------------*\
| 函数序号：20
| 功  能：创建相机的属性配置窗口
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：
|		  1  HDEVICE	hDevice		相机设备句柄						输入参数
|		  2  HWND		hParent		配置窗口的父窗口句柄				输入参数
|         3  TCHAR		*pWinText	配置窗口的标题栏字符串指针          输入参数
|
\*--------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceCreateSettingPage(HDEVICE hDevice, HWND hParent, LPCTSTR pText);

/*-------------------------------------------------------------------------*\
| 函数序号：21
| 功  能：显示相机配置窗口
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：
|		  1  HDEVICE	hDevice		相机设备句柄						输入参数
|         2  BOOL		bShow		是否显示配置窗口					输入参数
|
\*--------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceShowSettingPage(HDEVICE hDevice, BOOL bShow);

/*------------------------------------------------------------------------*\
| 函数序号：22
| 功  能：是否为单色相机
|                                                                          
| 返回值：设备是单色相机返回TRUE，否则返回FALSE
|
| 参  数：                                                             
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
\*------------------------------------------------------------------------*/
CG_API BOOL __stdcall IsMonochromeDevice(HDEVICE hDevice);

/*--------------------------------------------------------------------*\
| 函数序号：23
| 功  能：初始化相机                                   
|                                                                      
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                      
|                                                                      
| 参  数：         
|         1  HDEVICE			hDevice		相机设备句柄								输入参数
|         2  HWND				hWndDisplay	显示窗口句柄								输入参数
|		  3  BOOL				bGetMode	是否使用DeviceGetImageBuffer函数调用方式	输入参数	
|		  4  BOOL				bAutoParam	是否启用参数自动读写功能					输入参数	
\*--------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceInit(HDEVICE hDevice, HWND hWndDisplay, BOOL bGetMode, BOOL bAutoParam);

/*--------------------------------------------------------------------*\
| 函数序号：24
| 功  能：初始化相机                                   
|                                                                      
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                      
|                                                                      
| 参  数：         
|         1  HDEVICE			hDevice		相机设备句柄							  输入参数
|         2  ReceiveFrameProc	pFun		回调函数指针							  输入参数
|         3  LPVOID				lParam		指向一个值的指针，该值传递给回调函数	  输入参数
|         4  HWND				hWndDisplay	显示窗口句柄							  输入参数
|		  5  BOOL				bAutoParam	是否启用参数自动读写功能				  输入参数	
\*--------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceInitEx(HDEVICE hDevice, ReceiveFrameProc *pFun, LPVOID lParam, HWND hWndDisplay, BOOL bAutoParam);


/*--------------------------------------------------------------------*\
| 函数序号：25
| 功  能：初始化相机（通过外部文件存储方式加载参数） 
| 
| 返回值：调用成功返回STATUS_OK，否则返回错误代码 
|             
| 参  数：
|		  1  HDEVICE			hDevice		相机设备句柄							  输入参数
|         2  ReceiveFrameProc	pFun		回调函数指针							  输入参数
|         3  LPVOID				lParam		指向一个值的指针，该值传递给回调函数	  输入参数
|		  4  HWND				hWndDisplay 显示窗口句柄							  输入参数
|		  5  LPCTSTR			strFileName	读写参数保存的参数保存文件				  输入参数
\*--------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceInitExFromFile(HDEVICE hDevice, ReceiveFrameProc *pFun, LPVOID lParam, HWND hWndDisplay, LPCTSTR strFileName);

/*----------------------------------------------------------------------*\
| 函数序号：26
| 功  能：反初始化相机                                                 
|                                                                     
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|                                                             
| 参  数：
|        1  HDEVICE			hDevice		相机设备句柄							  输入参数
|                                                                     
| 注  意：                  
|         用于释放内存分配空间，必须在程序退出前调用
\*----------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceUnInit(HDEVICE hDevice);

/*--------------------------------------------------------------------*\
| 函数序号：27
| 功  能：打开视频流                                     
|                                                                      
| 返回值：调用成功返回STATUS_OK，否则返回错误代码     
|
| 参  数：                                                             
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
\*--------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceStart(HDEVICE hDevice);

/*--------------------------------------------------------------------*\
| 函数序号：28
| 功  能：停止视频流                                     
|                                                                      
| 返回值：调用成功返回STATUS_OK，否则返回错误代码     
|
| 参  数：                                                             
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
\*--------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceStop(HDEVICE hDevice);

/*--------------------------------------------------------------------*\
| 函数序号：29
| 功  能：视频流是否打开                                     
|                                                                      
| 返回值：视频流已经打开返回TRUE，否则返回FALSE     
|
| 参  数：                                                             
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
\*--------------------------------------------------------------------*/
CG_API BOOL __stdcall IsReceivingData(HDEVICE hDevice);

/*--------------------------------------------------------------------*\
| 函数序号：30
| 功  能：设置相机是否启用Get模式                                     
|                                                                      
| 返回值：调用成功返回STATUS_OK，否则返回错误代码         
|                                                                      
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄								输入参数
|		  2  BOOL		bGetMode	是否调用DeviceGetImageBuffer函数的方式		输入参数	
\*--------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceSetUsedGetMode(HDEVICE hDevice, BOOL bGetMode);

/*--------------------------------------------------------------------*\
| 函数序号：31
| 功  能：获取相机是否启用Get模式                                     
|                                                                      
| 返回值：调用成功返回STATUS_OK，否则返回错误代码         
|                                                                      
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄								输入参数
|		  2  BOOL		*pGetMode	是否调用DeviceGetImageBuffer函数的方式		输出参数	
\*--------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceGetUsedGetMode(HDEVICE hDevice, BOOL *pGetMode);

/*---------------------------------------------------------------------------------*\
| 函数序号：32
| 功  能：设置BAYER数据的转换模式                                                            
|                                                                                
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                            
|                                                                                
| 参  数： 
|		  1  HDEVICE					hDevice		相机设备句柄				输入参数
|         2  emDeviceBayerConvertMode	Mode		BAYER数据的转换模式			输入参数  
\*---------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceSetBayerConvertMode(HDEVICE hDevice, emDeviceBayerConvertMode Mode);

/*---------------------------------------------------------------------------------*\
| 函数序号：33
| 功  能：获取BAYER数据的转换模式                                                            
|                                                                                
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                            
|                                                                                
| 参  数： 
|		  1  HDEVICE					hDevice			相机设备句柄			输入参数
|         2  emDeviceBayerConvertMode	*pConvMode		BAYER数据的转换模式 	输出参数  
\*---------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceGetBayerConvertMode(HDEVICE hDevice, emDeviceBayerConvertMode *pConvMode);

/*---------------------------------------------------------------------------------*\
| 函数序号：34
| 功  能：设置图像数据处理输出类型                                                            
|                                                                                
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                            
|                                                                                
| 参  数： 
|         1  HDEVICE				hDevice		相机设备句柄			输入参数
|         2  emDeviceISPDataType	nType		图像数据处理输出类型	输入参数                                                                
\*---------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceSetISPDataType(HDEVICE hDevice, emDeviceISPDataType nType);

/*---------------------------------------------------------------------------------*\
| 函数序号：35
| 功  能：获取图像数据处理输出类型                                                            
|                                                                                
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                            
|                                                                                
| 参  数： 
|         1  HDEVICE				hDevice		相机设备句柄			输入参数
|         2  emDeviceISPDataType	*pType		图像数据处理输出类型	输出参数                                                                
\*---------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceGetISPDataType(HDEVICE hDevice, emDeviceISPDataType *pType);

/*---------------------------------------------------------------------------------*\
| 函数序号：36
| 功  能：图像数据处理                                                            
|                                                                                
| 返回值：调用成功返回RGB24图像数据首地址，否则返回NULL                             
|                                                                                
| 参  数： 
|         1  HDEVICE			hDevice		相机设备句柄							输入参数
|         2  BYTE				*pbyRAW		图像数据首地址，回调函数参数			输入参数
|         3  DeviceFrameInfo	*psFrInfo	图像帧数据信息，参见DeviceFrameInfo定义	输入参数                                                                   
\*---------------------------------------------------------------------------------*/
CG_API BYTE* __stdcall DeviceISP(HDEVICE hDevice, BYTE *pbyRAW, DeviceFrameInfo *psFrInfo);

/*---------------------------------------------------------------------------------*\
| 函数序号：37
| 功  能：图像数据处理                                                            
|                                                                                
| 返回值：调用成功返回BITMAP图像文件首地址，否则返回NULL                             
|                                                                                
| 参  数： 
|         1  HDEVICE			hDevice		相机设备句柄							输入参数
|         2  BYTE				*pbyRAW		图像数据首地址，回调函数参数			输入参数
|         3  DeviceFrameInfo	*psFrInfo	图像帧数据信息，参见DeviceFrameInfo定义	输入参数                                                                   
\*---------------------------------------------------------------------------------*/
CG_API BYTE* __stdcall DeviceISP2(HDEVICE hDevice, BYTE *pbyRAW, DeviceFrameInfo *psFrInfo);


/*-----------------------------------------------------------------------------------*\
| 函数序号：38
| 功  能：显示RGB24位图像数据                                                        
|                                                                                   
| 返回值：调用成功返回TRUE，否则返回FALSE                                     
|                                                                                   
| 参  数：
|         1  HDEVICE			hDevice		相机设备句柄							输入参数
|         2  BYTE				*pbRGB		RGB24图像数据首地址 					输入参数 
|         3  DeviceFrameInfo    *psFrInfo   图像帧数据信息，参见DeviceFrameInfo定义	输入参数
\*-----------------------------------------------------------------------------------*/
CG_API BOOL __stdcall DeviceDisplayRGB24(HDEVICE hDevice, BYTE *pbRGB, DeviceFrameInfo *psFrInfo);

/*-------------------------------------------------------------------------*\
| 函数序号：39
| 功  能：设置显示模式
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：
|		  1  HDEVICE			hDevice			相机设备句柄				输入参数
|         2  emDisplayMode		displayMode		显示模式					输入参数
|
\*--------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceSetDisplayMode(HDEVICE hDevice, emDisplayMode displayMode);

/*-------------------------------------------------------------------------*\
| 函数序号：40
| 功  能：设置显示的起始偏移值
|
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|
| 参  数：
|		  1  HDEVICE	hDevice			相机设备句柄				输入参数
|         2  INT		iOffsetX		偏移的X坐标					输入参数
|         3  INT        iOffsetY		偏移的Y坐标					输入参数
|
\*--------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceSetDisplayOffset(HDEVICE hDevice, INT iOffsetX, INT iOffsetY);

/*---------------------------------------------------------------------------*\
| 函数序号：41
| 功  能：设置预览图像尺寸
|           
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|       
| 参  数：         
|		  1  HDEVICE	hDevice			相机设备句柄				输入参数
|         2  INT		iWidth			预览图像宽度                输入参数          
|         3  INT		iHeight			预览图像高度                输入参数                                              
\*---------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceSetDisplaySize(HDEVICE hDevice, INT iWidth, INT iHeight);

/*---------------------------------------------------------------------------*\
| 函数序号：42
| 功  能：获取一帧图像数据
|           
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|       
| 参  数：  
|		  1  HDEVICE			hDevice		相机设备句柄							输入参数
|         2  BYTE				**pbyBuffer	图像数据保存的首地址					输入参数
|         3  DWORD				wTimes		抓取图像的超时时间,单位毫秒。			输入参数
|         4  DeviceFrameInfo    *psFrInfo   图像帧数据信息，参见DeviceFrameInfo定义	输出参数
\*---------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceGetImageBuffer(HDEVICE hDevice, BYTE **pbyBuffer, DWORD wTimes, DeviceFrameInfo *psFrInfo);


/*---------------------------------------------------------------------------*\
| 函数序号：43
| 功  能：获取一帧图像数据(该接口获得的图像是经过处理后的ISP数据格式)
|           
| 返回值：成功时，返回数据缓冲区的首地址，否则返回NULL。
|       
| 参  数：       
|		  1  HDEVICE			hDevice		相机设备句柄							输入参数
|         2  DWORD				wTimes		抓取图像的超时时间,单位毫秒。			输入参数           
|         3  DeviceFrameInfo    *psFrInfo   图像帧数据信息，参见DeviceFrameInfo定义	输出参数
\*---------------------------------------------------------------------------*/
CG_API BYTE* __stdcall DeviceGetImageBufferEx(HDEVICE hDevice, DWORD wTimes, DeviceFrameInfo *psFrInfo);

/*---------------------------------------------------------------------------*\
| 函数序号：44
| 功  能：获得一帧图像数据(该接口获得的图像是经过处理后的ISP数据格式)
|           
| 返回值：调用成功返回STATUS_OK，否则返回错误代码
|       
| 参  数：         
|		  1  HDEVICE			hDevice				相机设备句柄							输入参数
|         2  BYTE				*pImageData			接收图像数据的缓冲区					输入参数
|		  3  UINT				wTimes				抓取图像的超时时间,单位毫秒。			输入参数 
|         4  DeviceFrameInfo    *psFrInfo			图像帧数据信息，参见DeviceFrameInfo定义	输出参数
\*---------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall DeviceGetImageBufferEx2(HDEVICE hDevice, BYTE* pImageData, UINT wTimes, DeviceFrameInfo *psFrInfo);

/*-----------------------------------------------------------------------------------*\
| 函数序号：45
| 功  能：采集单帧或多帧图像到内存                                                        
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                    
|                                                                                   
| 参  数：
|         1  HDEVICE			hDevice		相机设备句柄							输入参数
|         2  BYTE				*pbyRAW		图像数据保存的首地址					输入参数 
|         3  UINT				nFrames		采集图像的帧数							输入参数
|         4  DeviceFrameInfo    *psFrInfo   图像帧数据信息，参见DeviceFrameInfo定义	输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SnapShot(HDEVICE hDevice, BYTE *pbyRAW, UINT nFrames, DeviceFrameInfo *psFrInfo);

/*-----------------------------------------------------------------------------------*\
| 函数序号：46
| 功  能：获取相机设备参数范围                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                      
|                                                                                   
| 参  数：
|         1  HDEVICE			hDevice			相机设备句柄			输入参数
|         2  DeviceCapability	*pDeviceInfo	相机设备参数范围结构	输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetCapability(HDEVICE hDevice, DeviceCapability *pDeviceInfo);


/*-----------------------------------------------------------------------------------*\
| 函数序号：47
| 功  能：获取相机设备最大图像范围大小                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                      
|                                                                                   
| 参  数：                      
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  INT		*piWidth		最大宽度				输出参数
|         3  INT		*piHeight		最大高度				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetCapabilityImageSize(HDEVICE hDevice, INT *piWidth, INT *piHeight);

/*-----------------------------------------------------------------------------------*\
| 函数序号：48
| 功  能：获取相机设备当前图像大小                                                 
|                                                                                  
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                  
|                                                                                  
| 参  数：     
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  INT		*piWidth		宽度					输出参数
|         3  INT		*piHeight		高度					输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetImageSize(HDEVICE hDevice, INT *piWidth, INT *piHeight);

/*-----------------------------------------------------------------------------------*\
| 函数序号：49
| 功  能：获取相机预设分辨率数据                                                       
|                                                                                   
| 返回值：调用成功返回预设分辨率的数量，否则返回0                                      
|                                                                                   
| 参  数：
|         1  HDEVICE			hDevice			相机设备句柄					输入参数
|         2  LPDeviceResolutionItem	lpDevRes	指向相机分辨率描述结构的指针	输出参数
\*-----------------------------------------------------------------------------------*/
CG_API int __stdcall GetResolutions(HDEVICE hDevice, LPDeviceResolutionItem lpDevRes = NULL);

/*-----------------------------------------------------------------------------------*\
| 函数序号：50
| 功  能：设置相机当前分辨率                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE			hDevice	相机设备句柄		输入参数
|         2  ResolutionParam	param	相机分辨率模式参数	        输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetResolution(HDEVICE hDevice, ResolutionParam param);

/*-----------------------------------------------------------------------------------*\
| 函数序号：51
| 功  能：获取相机当前分辨率                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE			hDevice	相机设备句柄					输入参数
|         2  ResolutionParam	*pParam	指向相机分辨率模式结构的指针	输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetResolution(HDEVICE hDevice, ResolutionParam *pParam);

/*-----------------------------------------------------------------------------------*\
| 函数序号：52
| 功  能：设置输出图像数据的类型                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：    
|         1  HDEVICE		hDevice		相机设备句柄		输入参数
|         2  DeviceDataType	dataType	图像数据类型		输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetMediaType(HDEVICE hDevice, emDeviceDataType dataType);

/*-----------------------------------------------------------------------------------*\
| 函数序号：53
| 功  能：获取输出图像数据的类型                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE		hDevice		相机设备句柄		输入参数
|         2  DeviceDataType	*pDataType	图像数据类型		输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetMediaType(HDEVICE hDevice, emDeviceDataType *pDataType);

/*-----------------------------------------------------------------------------------*\
| 函数序号：54
| 功  能：设置帧率                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE		hDevice		相机设备句柄			输入参数
|         2  DeviceSpeed	dSpeed		帧率					输入参数
|		  3  BOOL			bAutoTune	自动调整速度微调到默认	输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetFrameSpeed(HDEVICE hDevice, emDeviceFrameSpeed dSpeed, BOOL bAutoTune = FALSE);

/*-----------------------------------------------------------------------------------*\
| 函数序号：55
| 功  能：获取帧率                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE			hDevice	相机设备句柄		输入参数
|         2  ResolutionParam	*pParam	帧率				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetFrameSpeed(HDEVICE hDevice, emDeviceFrameSpeed *pdSpeed);

/*-----------------------------------------------------------------------------------*\
| 函数序号：56
| 功  能：设置速度微调                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|		  1  HDEVICE		hDevice		相机设备句柄				输入参数 
|         2  FLOAT			fTune		微调系数（范围0.0 - 1.0）	输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetFrameSpeedTune(HDEVICE hDevice, FLOAT fTune);

/*-----------------------------------------------------------------------------------*\
| 函数序号：57
| 功  能：获取速度微调                                                      
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：         
|		  1  HDEVICE			hDevice		相机设备句柄				输入参数
|         2  FLOAT				*pfTune		微调系数（范围0.0 - 1.0）	输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetFrameSpeedTune(HDEVICE hDevice, FLOAT *pfTune);

/*-----------------------------------------------------------------------------------*\
| 函数序号：58
| 功  能：设置触发模式                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE			hDevice	相机设备句柄			输入参数
|         2  DeviceCaptureMode	mode	触发模式				输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetCaptureMode(HDEVICE hDevice, emDeviceCaptureMode mode);

/*-----------------------------------------------------------------------------------*\
| 函数序号：59
| 功  能：获取触发模式                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE			hDevice		相机设备句柄			输入参数
|         2  DeviceCaptureMode	*pCapMode	触发模式				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetCaptureMode(HDEVICE hDevice, emDeviceCaptureMode  *pCapMode);

/*-----------------------------------------------------------------------------------*\
| 函数序号：60
| 功  能：设置软触发一次帧数                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE	hDevice	相机设备句柄			输入参数
|         2  UINT		nFrame	软触发一次帧数			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetSoftTriggerFrameNumber(HDEVICE hDevice, UINT nFrame);

/*-----------------------------------------------------------------------------------*\
| 函数序号：61
| 功  能：获取软触发一次帧数                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  UINT		*pFrameNum		软触发一次帧数			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetSoftTriggerFrameNumber(HDEVICE hDevice, UINT *pFrameNum);

/*-----------------------------------------------------------------------------------*\
| 函数序号：62
| 功  能：软触发一次                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码       
|                                                                                   
| 参  数： 
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SoftTriggerOnce(HDEVICE hDevice);

/*-----------------------------------------------------------------------------------*\
| 函数序号：63
| 功  能：设置GPIO输出                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码   
|
| 参  数：
|         1  HDEVICE			hDevice		相机设备句柄					输入参数
|         2  emGPIOOutputMode	outputMode	GPIO输出模式					输入参数
|		  3  WORD				value		脉冲宽度（仅脉冲模式时有效）	输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetGPIOOutput(HDEVICE hDevice, emGPIOOutputMode outputMode, WORD value);


/*-----------------------------------------------------------------------------------*\
| 函数序号：64
| 功  能：获取GPIO输出                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码   
|
| 参  数：
|         1  HDEVICE			hDevice			相机设备句柄					输入参数
|         2  emGPIOOutputMode	*pOutputMode	GPIO输出模式					输出参数
|		  3  WORD				*pValue			脉冲宽度（仅脉冲模式时有效）	输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetGPIOOutput(HDEVICE hDevice, emGPIOOutputMode *pOutputMode, WORD *pValue);


/*-----------------------------------------------------------------------------------*\
| 函数序号：65
| 功  能：设置曝光时间                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  USHORT		usExposureTime	曝光时间				输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetExposureTime(HDEVICE hDevice, USHORT usExposureTime);

/*-----------------------------------------------------------------------------------*\
| 函数序号：66
| 功  能：获取曝光时间                                                        
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice				相机设备句柄		输入参数
|         2  USHORT		*pusExposureTime	曝光时间			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetExposureTime(HDEVICE hDevice, USHORT *pusExposureTime);

/*-----------------------------------------------------------------------------------*\
| 函数序号：67
| 功  能：设置自动曝光目标值                                                      
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  BYTE		byTarget		自动曝光目标值			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetAutoExposureTarget(HDEVICE hDevice, BYTE byTarget);

/*-----------------------------------------------------------------------------------*\
| 函数序号：68
| 功  能：获取自动曝光目标值                                                       
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄			输入参数
|         2  BYTE		*pbyTarget	自动曝光目标值			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetAutoExposureTarget(HDEVICE hDevice, BYTE *pbyTarget);

/*-----------------------------------------------------------------------------------*\
| 函数序号：69
| 功  能：设置各色彩通道的增益                                                      
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
|         2  USHORT		RGain			红通道增益			输入参数
|         3  USHORT		GGain			绿通道增益			输入参数
|         4  USHORT		BGain			蓝通道增益			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetGain(HDEVICE hDevice, USHORT RGain, USHORT GGain, USHORT BGain);

/*-----------------------------------------------------------------------------------*\
| 函数序号：70
| 功  能：获取各色彩通道的增益                                                      
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE		hDevice		相机设备句柄		输入参数
|         2  USHORT			*pRGain		红通道增益			输出参数
|         3  USHORT			*pGGain		绿通道增益			输出参数
|         4  USHORT			*pBGain		蓝通道增益			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetGain(HDEVICE hDevice, USHORT *pRGain, USHORT *pGGain, USHORT *pBGain);

/*-----------------------------------------------------------------------------------*\
| 函数序号：71
| 功  能：设置曝光增益                                                      
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
|         2  USHORT		uGain		曝光增益			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetAnalogGain(HDEVICE hDevice, USHORT uGain);

/*-----------------------------------------------------------------------------------*\
| 函数序号：72
| 功  能：获取曝光增益                                                      
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
|         2  USHORT		*pGain		曝光增益			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetAnalogGain(HDEVICE hDevice, USHORT *pGain);

/*-----------------------------------------------------------------------------------*\
| 函数序号：73
| 功  能：设置伽玛状态                                                      
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄	输入参数
|         2  BOOL		bEnable		状态			输入参数
| 注意： 当bEnable为FALSE时，SetGamma函数设置的值会被忽略
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetGammaState(HDEVICE hDevice, BOOL bEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：74
| 功  能：获取伽玛状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE		hDevice		相机设备句柄		输入参数
|         2  BOOL			*pEnable	状态				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetGammaState(HDEVICE hDevice, BOOL *pEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：75
| 功  能：设置伽玛值                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：  
|         1  HDEVICE	hDevice		相机设备句柄	输入参数
|         2  FLOAT		fGamma		伽玛值			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetGamma(HDEVICE hDevice, FLOAT fGamma);

/*-----------------------------------------------------------------------------------*\
| 函数序号：76
| 功  能：获取伽玛值                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
|         2  FLOAT		*pfGamma	伽玛值				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetGamma(HDEVICE hDevice, FLOAT *pfGamma);

/*-----------------------------------------------------------------------------------*\
| 函数序号：77
| 功  能：设置亮度状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
|         2  BOOL		bEnable			状态				输入参数
| 注意： 当bEnable为FALSE时，SetBright函数设置的值会被忽略
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetBrightState(HDEVICE hDevice, BOOL bEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：78
| 功  能：获取亮度状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE	hDevice			相机设备句柄	输入参数
|         2  BOOL 		*pEnable		状态			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetBrightState(HDEVICE hDevice, BOOL *pEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：79
| 功  能：设置亮度值                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE		hDevice		相机设备句柄			输入参数
|         2  SHORT			shBright	亮度值					输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetBright(HDEVICE hDevice, SHORT shBright);

/*-----------------------------------------------------------------------------------*\
| 函数序号：80
| 功  能：获取亮度值                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE		hDevice		相机设备句柄		输入参数
|         2  SHORT			*pshBright	亮度值				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetBright(HDEVICE hDevice, SHORT *pshBright);

/*-----------------------------------------------------------------------------------*\
| 函数序号：81
| 功  能：设置对比度状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE		hDevice			相机设备句柄		输入参数
|         2  BOOL			bEnable			状态				输入参数
| 注意： 当bEnable为FALSE时，SetContrast函数设置的值会被忽略
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetContrastState(HDEVICE hDevice, BOOL bEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：82
| 功  能：获取对比度状态                                                    
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE		hDevice		相机设备句柄	输入参数
|         2  BOOL			*pEnable	状态			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetContrastState(HDEVICE hDevice, BOOL *pEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：83
| 功  能：设置对比度值                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE		hDevice		相机设备句柄		输入参数
|         2  SHORT			shContrast	对比度值			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetContrast(HDEVICE hDevice, SHORT shContrast);

/*-----------------------------------------------------------------------------------*\
| 函数序号：84
| 功  能：获取对比度值                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE		hDevice			相机设备句柄			输入参数
|         2  SHORT			*pshContrast	对比度值				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetContrast(HDEVICE hDevice, SHORT *pshContrast);

/*-----------------------------------------------------------------------------------*\
| 函数序号：85
| 功  能：设置饱和度状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE		hDevice			相机设备句柄		输入参数
|         2  BOOL			bEnable			状态				输入参数
| 注意： 当bEnable为FALSE时，SetSaturation函数设置的值会被忽略
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetSaturationState(HDEVICE hDevice, BOOL bEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：86
| 功  能：获取饱和度状态                                                   
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
|         2  BOOL		*pEnable	状态				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetSaturationState(HDEVICE hDevice, BOOL *pEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：87
| 功  能：设置饱和度值                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  BYTE		bySaturation	饱和度值				输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetSaturation(HDEVICE hDevice, BYTE bySaturation);

/*-----------------------------------------------------------------------------------*\
| 函数序号：88
| 功  能：获取饱和度值                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
|         2  BYTE		*pbySaturation	饱和度值			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetSaturation(HDEVICE hDevice, BYTE *pbySaturation);

/*-----------------------------------------------------------------------------------*\
| 函数序号：89
| 功  能：设置图像翻转状态                                                    
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE			hDevice			相机设备句柄					输入参数
|         2  emMirrorDirection	mDir			图像翻转方向标识（水平或垂直）	输入参数
|         3  BOOL				bEnable			图像翻转状态					输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetMirror(HDEVICE hDevice, emMirrorDirection mDir, BOOL bEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：90
| 功  能：获取图像翻转状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE			hDevice		相机设备句柄					输入参数
|         2  MirrorDirection	mDir		图像翻转方向标识（水平或垂直）	输入参数
|         3  BOOL				*pEnable	图像翻转状态					输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetMirror(HDEVICE hDevice, emMirrorDirection mDir, BOOL *pEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：91
| 功  能：设置图像单色状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
|         2  BOOL		bEnable		图像单色状态		输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetMonochrome(HDEVICE hDevice, BOOL bEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：92
| 功  能：获取图像单色状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice		相机设备句柄		输入参数
|         2  BOOL		*pEnable	图像单色状态		输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetMonochrome(HDEVICE hDevice, BOOL *pEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：93
| 功  能：设置图像反色状态                                                    
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  BOOL		bEnable			图像反色状态			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetInverse(HDEVICE hDevice, BOOL bEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：94
| 功  能：获取图像反色状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
|         2  BOOL		*pEnable		伽玛值				输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetInverse(HDEVICE hDevice, BOOL *pEnable);

/*-----------------------------------------------------------------------------------*\
| 函数序号：95
| 功  能：一次白平衡功能                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码   
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetOnceWBalace(HDEVICE hDevice);

/*-----------------------------------------------------------------------------------*\
| 函数序号：96
| 功  能：设置自动曝光状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
|         2  BOOL		bAEState		自动曝光状态		输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetAutoExposureState(HDEVICE hDevice, BOOL bAEState);

/*-----------------------------------------------------------------------------------*\
| 函数序号：97
| 功  能：获取自动曝光状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
|         2  BOOL		*pAEState		自动曝光状态		输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetAutoExposureState(HDEVICE hDevice, BOOL *pAEState);

/*-----------------------------------------------------------------------------------*\
| 函数序号：98
| 功  能：设置自动白平衡状态                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  BOOL		bAWBState		自动白平衡状态			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SetAutoWBalaceState(HDEVICE hDevice, BOOL bAWBState);

/*-----------------------------------------------------------------------------------*\
| 函数序号：99
| 功  能：获取自动白平衡状态                                                      
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄		输入参数
|         2  BOOL		*pAWBState		伽玛值				输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetAutoWBalaceState(HDEVICE hDevice, BOOL *pAWBState);

/*-----------------------------------------------------------------------------------*\
| 函数序号：100
| 功  能：保存当前图像到文件                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数： 
|         1  HDEVICE		hDevice			相机设备句柄			输入参数
|         2  LPCTSTR		lpszFileName	图像文件路径和名称		输入参数
|         3  emDSFileType	type			图像文件类型            输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall CaptureFile(HDEVICE hDevice, LPCTSTR lpszFileName, emDSFileType type);

/*-----------------------------------------------------------------------------------*\
| 函数序号：101
| 功  能：开启录影功能                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：  
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  LPCTSTR	lpszFileName	视频文件的路径和名称	输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall StartRecordVideo(HDEVICE hDevice, LPCTSTR lpszFileName);

/*-----------------------------------------------------------------------------------*\
| 函数序号：102
| 功  能：停止录影功能                                                    
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码  
|                                                                                   
| 参  数：  
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall StopRecordVideo(HDEVICE hDevice);

/*-----------------------------------------------------------------------------------*\
| 函数序号：103
| 功  能：读出相机默认出厂参数设置                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码   
|                                                                                   
| 参  数：  
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall LoadDefaultParameter(HDEVICE hDevice);

/*-----------------------------------------------------------------------------------*\
| 函数序号：104
| 功  能：获取当前使用的保存参数组别                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：        
|         1  HDEVICE		hDevice			相机设备句柄			输入参数
|         2  ParameterTeam	*pTeam			保存参数的组别（共4组）	输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetCurrentParameterTeam(HDEVICE hDevice, emParameterTeam *pTeam);

/*-----------------------------------------------------------------------------------*\
| 函数序号：105
| 功  能：读取相机的参数设置，并使其生效                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：     
|         1  HDEVICE		hDevice			相机设备句柄			输入参数
|         2  ParameterTeam	eTeam			保存参数的组别（共4组）	输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall ReadParameter(HDEVICE hDevice, emParameterTeam eTeam);


/*-----------------------------------------------------------------------------------*\
| 函数序号：106
| 功  能：保存相机的参数设置                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：      
|         1  HDEVICE		hDevice			相机设备句柄			输入参数
|         2  ParameterTeam	eTeam			保存参数的组别（共4组）	输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SaveParameter(HDEVICE hDevice, emParameterTeam eTeam);

/*-----------------------------------------------------------------------------------*\
| 函数序号：107
| 功  能：从文件中读取相机的参数设置，并使其生效                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：  
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  LPCTSTR	strFileName		读取参数的文件			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall ReadParameterFromFile(HDEVICE hDevice, LPCTSTR strFileName);

/*-----------------------------------------------------------------------------------*\
| 函数序号：108
| 功  能：保存相机的参数设置到文件                                                     
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  LPCTSTR	strFileName		保存参数的文件			输入参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall SaveParameterToFile(HDEVICE hDevice, LPCTSTR strFileName);


/*-----------------------------------------------------------------------------------*\
| 函数序号：109
| 功  能：查询扩展接口句柄                                                    
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  IID		riid			接口标识IID				输入参数
|         2  void**		ppvObj			扩展接口句柄			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall QueryInterface(HDEVICE hDevice, const IID &riid, void **ppvObj);

/*-----------------------------------------------------------------------------------*\
| 函数序号：110
| 功  能：查询码识别接口句柄                                                    
|                                                                                   
| 返回值：调用成功返回STATUS_OK，否则返回错误代码                                       
|                                                                                   
| 参  数：
|         1  HDEVICE	hDevice			相机设备句柄			输入参数
|         2  void**		ppvObj			扩展接口句柄			输出参数
\*-----------------------------------------------------------------------------------*/
CG_API DeviceStatus __stdcall GetQRCodeInterface(HDEVICE hDevice, void **ppvObj);

#endif