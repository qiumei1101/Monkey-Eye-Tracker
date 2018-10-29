#ifndef _DEVICEPARAM_DEFINE_H_
#define _DEVICEPARAM_DEFINE_H_

#define DESCR_LEN_MAX   32

/*---------------------------------------------------------------------------------*\
|                          ����б����Ϣ�ṹ
\*---------------------------------------------------------------------------------*/
typedef struct tagEnumDeviceParam
{
	UCHAR	devIndex;			// �豸���кţ� ����OF_BYPOSITION��ʽ�����
	UCHAR	usbAddress;			// �豸USB��ַ������OF_BYUSBADDRESS��ʽ�����
	BYTE	devSN[32];			// ͨ��WriteSerialNumber����д���������кţ�����OF_USERSERIALNUMBER��ʽ�����
	INT		index;				// ö�ٵ����豸����(0 - n)
	TCHAR	lpDeviceDesc[256];	// �������
	INT     nDeviceDesc;		// ������Ƴ���
}EnumDeviceParam, *LPEnumDeviceParam;

/*---------------------------------------------------------------------------------*\
|                          ������Ĳ����ṹ
\*---------------------------------------------------------------------------------*/
typedef union tagUionOpenDeviceParam
{
	UCHAR	devIndex;			// �豸���кţ� ����OF_BYPOSITION��ʽ�����
	UCHAR	usbAddress;			// �豸USB��ַ������OF_BYUSBADDRESS��ʽ�����
	BYTE	devSN[32];			// ͨ��WriteSerialNumber����д���������кţ�����OF_USERSERIALNUMBER��ʽ�����
}UionOpenDeviceParam;

/*------------------------------------------------------------------------*\
|                               ͼ����������
\*------------------------------------------------------------------------*/
typedef struct tagDeviceMediaType
{
    INT   iIndex;                        // ͼ���������������ţ�ֵ��0��ʼ
	TCHAR strDescription[DESCR_LEN_MAX]; // ͼ���������͵���������
    INT   iDataType;                     // ͼ���������ͣ��ο���DVP_DeviceDefine.h��ͷ�ļ���ö�����͡�emDeviceDataType����ֵ
}DeviceMediaType;

/*------------------------------------------------------------------------*\
|                               ֡����Ϣ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceFrameSpeed
{
    INT		iIndex;							  // ֡�������ţ�ֵ��0��ʼ
    TCHAR	strDescription[DESCR_LEN_MAX];    // ֡����������
	INT		iFrameSpeed;					  // ���֡�ٶ��壬�ο���DVP_DeviceDefine.h��ͷ�ļ���ö�����͡�emDeviceFrameSpeed����ֵ
	FLOAT	fDefSpeedTune;					  // Ĭ���ٶ�΢��ֵ
} DeviceFrameSpeed;

/*------------------------------------------------------------------------*\
|                            ROI�����ṹ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceROISize
{
	INT  iHOffset;		// ROIˮƽƫ����
    INT  iVOffset;		// ROI��ֱƫ����
    INT  iWidth;		// ROI���
    INT  iHeight;		// ROI�߶�
}DeviceROISize;

/*------------------------------------------------------------------------*\
|                            �ֱ��������ṹ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceResolutionItem
{
	DeviceROISize		devSize;			// ROI�ṹ����
	INT					iSUBSampleMode;		// ͼ�񴫸�������ģʽ���ο���DVP_DeviceDefine.h��ͷ�ļ���ö�����͡�emDeviceSubSampleMode����ֵ
	WORD				wSUBSampleModeData;	// ͼ�񴫸�������ģʽ����ֵ�� Ŀǰ������SKIP����ģʽ
}DeviceResolutionItem, *LPDeviceResolutionItem;

/*------------------------------------------------------------------------*\
|                            �ֱ���ģʽ�����ṹ
\*------------------------------------------------------------------------*/
typedef struct tagResolutionParam
{
	struct{
		DeviceROISize	devROISize;		// ROI�ṹ����
		UCHAR			ucIndex;		// Ԥ��ֱ��ʵ�����ֵ
	}dri;
	INT	type;						    // �ֱ��ʵ����ͣ��ο���DVP_DeviceDefine.h��ͷ�ļ���ö�����͡�emResolutionType����ֵ
}ResolutionParam;

/*------------------------------------------------------------------------*\
|                             ֡������Ϣ
\*------------------------------------------------------------------------*/
typedef struct
{
    UINT    uiMediaType;	// ͼ���������ͣ��ο���DVP_DeviceDefine.h��ͷ�ļ���ö�����͡�emDeviceDataType����ֵ
	UINT	uiISPDataType;	// ͼ�����ݴ���������ͣ��ο���DVP_DeviceDefine.h��ͷ�ļ���ö�����͡�emDeviceISPDataType����ֵ
    UINT    uBytes;			// ͼ�������ֽ���
	UINT    uiWidth;		// ͼ����
    UINT    uiHeight;		// ͼ��߶�
	BOOL	bMonochrome;	// �����Ƿ�Ϊ��ɫͼ
    BOOL    bTriggered;		// �����Ƿ�Ϊ����֡
}DeviceFrameInfo;

/*------------------------------------------------------------------------*\
|                            ��Ƶ�ߴ緶Χ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceImageSizeRange
{
    INT   iHeightMax;		// ͼ��߶����ֵ
    INT   iHeightMin;		// ͼ��߶���Сֵ
    INT   iHeightDefault;	// ͼ��߶�Ĭ��ֵ
    INT   iWidthMax;		// ͼ�������ֵ
    INT   iWidthMin;		// ͼ������Сֵ
    INT   iWidthDefault;	// ͼ����Ĭ��ֵ
    BOOL  bROI;				// �Ƿ�֧��ROIģʽ��TRUE:֧�֣�FALSE:��֧��
} DeviceImageSizeRange;

/*------------------------------------------------------------------------*\
|                            �������һ�ε�֡����Χ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceSoftTriggerFrameRange
{
	UINT	nFrameMin;		// ֡����Сֵ
	UINT	nFrameMax;		// ֡�����ֵ
	UINT	nFrameDefault;	// ֡��Ĭ��ֵ
}DeviceSoftTriggerFrameRange;

/*------------------------------------------------------------------------*\
|                              RGBͨ�����淶Χ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceRGBGainRange
{
    USHORT  ucRGainMin;		// ��ͨ��������Сֵ
    USHORT  ucRGainMax;		// ��ͨ���������ֵ
    USHORT  ucRGainDefault;	// ��ͨ������Ĭ��ֵ 
    USHORT  ucGGainMin;		// ��ͨ��������Сֵ
    USHORT  ucGGainMax;		// ��ͨ���������ֵ
    USHORT  ucGGainDefault;	// ��ͨ������Ĭ��ֵ
    USHORT  ucBGainMin;		// ��ͨ��������Сֵ
    USHORT  ucBGainMax;		// ��ͨ���������ֵ
    USHORT  ucBGainDefault;	// ��ͨ������Ĭ��ֵ
}DeviceRGBGainRange;

/*------------------------------------------------------------------------*\
|                              ���淶Χ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceGainRange
{
	USHORT  ucGainMin;		// ������Сֵ
    USHORT  ucGainMax;		// �������ֵ
    USHORT  ucGainDefault;	// ����Ĭ��ֵ
	BOOL	bSupportMulti;	// ֧�ֶ౶����
}DeviceGainRange;

/*------------------------------------------------------------------------*\
|                            ɫ�ʱ��Ͷ���ֵ��Χ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceSaturationRange
{
    BYTE  iMin;				// ɫ�ʱ��Ͷ���Сֵ
    BYTE  iMax;				// ɫ�ʱ��Ͷ����ֵ
    BYTE  iDefault;			// ɫ�ʱ��Ͷ�Ĭ��ֵ
} DeviceSaturationRange;

/*------------------------------------------------------------------------*\
|                              ͼ��٤����ֵ��Χ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceGammaRange
{
	FLOAT  fMin;			// ͼ��٤����Сֵ
    FLOAT  fMax;			// ͼ��٤�����ֵ
    FLOAT  fDefault;		// ͼ��٤��Ĭ��ֵ
}DeviceGammaRange;

/*------------------------------------------------------------------------*\
|                             ͼ��Աȶ���ֵ��Χ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceContrastRange
{
	SHORT  shMin;			// ͼ��Աȶ���Сֵ
    SHORT  shMax;			// ͼ��Աȶ����ֵ
    SHORT  shDefault;		// ͼ��Աȶ�Ĭ��ֵ
}DeviceContrastRange;

/*------------------------------------------------------------------------*\
|                             �ع�ʱ����Ϣ
\*------------------------------------------------------------------------*/
typedef struct tagDeviceExposureRange
{
    BYTE	byTargetMin;			// ��С�Զ��ع�Ŀ��ֵ
    BYTE	byTargetMax;			// ����Զ��ع�Ŀ��ֵ
    BYTE	byTargetDefault;		// Ĭ���Զ��ع�Ŀ��ֵ
    USHORT  usExposureTimeMin;		// ��С�ع�ʱ��
    USHORT  usExposureTimeMax;		// ����ع�ʱ��
    USHORT  usExposureTimeDefault;	// Ĭ���ع�ʱ��
    USHORT  usExposureTimeStep;		// �ع�ʱ����ڵĲ���ֵ����С��λ��
}DeviceExposureRange;

/*------------------------------------------------------------------------*\
|                       ��������ĸ�����Ϣ�Ͳ������ԡ�
\*------------------------------------------------------------------------*/
typedef struct tagDeviceCapability{
	DeviceImageSizeRange		sImageSizeRange;			// ͼ��ߴ���޶���Χ��Ĭ��ֵ
	DeviceSoftTriggerFrameRange sSoftTriggerFrameRange;		// �������ܵ��޶���Χ��Ĭ��ֵ
	DeviceRGBGainRange			sRGBGainRange;				// RGB������޶���Χ��Ĭ��ֵ
	DeviceGainRange				sGainRange;					// ������޶���Χ��Ĭ��ֵ
	DeviceSaturationRange		sSaturationRange;			// ɫ�ʱ��Ͷȵ��޶���Χ��Ĭ��ֵ
	DeviceGammaRange			sGammaRange;				// ͼ��٤����޶���Χ��Ĭ��ֵ
	DeviceContrastRange			sContrastRange;				// ͼ��Աȶȵ��޶���Χ��Ĭ��ֵ
	DeviceExposureRange			sExposureRange;				// �ع⹦�ܵ��޶���Χ��Ĭ��ֵ

	DeviceMediaType				*pMediaType;				// ��������ͼ����������
	INT							iMediaType;					// ͼ���������͵���Ŀ
	INT							iMediaTypeDefault;			// ͼ���������͵�Ĭ�������ֵ��

	DeviceFrameSpeed			*pFrameSpeed;				// ֡��
    INT							iFrameSpeed;				// ֡�ٵ���Ŀ
    INT							iFrameSpeedDefault;			// ֡�ٵ�Ĭ��������ţ�
}DeviceCapability;

#endif