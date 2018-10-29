/*---------------------------------------------------------------------------------*\
|						SDK��ǰ�汾�� version 1.0.2.11/May/2017
\*---------------------------------------------------------------------------------*/
#ifndef _DEVICEDEFINE_H_
#define _DEVICEDEFINE_H_

#define PUBLISH_VERSION 1.0.2.11

#include "DVP_DeviceParamDef.h"

/*---------------------------------------------------------------------------------*\
|                    ���״ֵ̬�Ƿ�ɹ����Ǹ�����ʾ�ɹ���
\*---------------------------------------------------------------------------------*/

#ifndef SUCCEEDED
#define SUCCEEDED(Status)     ((HRESULT)(Status) >= 0)
#endif

/*---------------------------------------------------------------------------------*\
|                    ���״ֵ̬�Ƿ�ʧ�ܣ�������ʾʧ�ܣ�
\*---------------------------------------------------------------------------------*/

#ifndef FAILED
#define FAILED(Status)		  ((HRESULT)(Status) < 0)
#endif

/*---------------------------------------------------------------------------------*\
|                                    �����붨��
\*---------------------------------------------------------------------------------*/

typedef enum{
    STATUS_OK                     = 0,       // �����ɹ�
	STATUS_FAILED				  = -1,		 // ����ʧ��	
    STATUS_INTERNAL_ERROR         = -2,      // �ڲ�����
    STATUS_NOT_SUPPORTED          = -3,      // �豸��֧��
    STATUS_NOT_INITIALIZED        = -4,      // ��ʼ������
    STATUS_PARAMETER_INVALID      = -5,      // ��Ч�Ĳ���
	STATUS_THREAD_WORKING		  = -6,		 // �߳���������
	STATUS_CHECK_ENCRYPT_ERROR	  = -7,	     // �����ܴ���
	STATUS_CHECK_ENCRYPT_LOST	  = -8,		 // ������Ϣ��ʧ
	STATUS_INVALIDATE_HANDLE	  = -9,		 // ��Ч���豸���
	STATUS_CAPMODE_NOT_SUPPORTED  = -10,	 // ��ǰ����ģʽ��֧��
	STATUS_BAD_FRAME			  = -11,	 // �ɼ�ͼ����ֻ�֡
	STATUS_RECEIVING_STOP		  = -12,	 // ֹͣ�ɼ�ͼ��
	STATUS_RECEIVING_SWITCH		  = -13,     // �ɼ��л������Ժ�����
    STATUS_TIME_OUT               = -1000,   // �豸��ʱ
    STATUS_IO_ERROR               = -1001,   // �豸IO����
    STATUS_DEVICE_NOT_DETECTED    = -1100,   // ��ⲻ���豸
	STATUS_NOTCONNECT_ENCRYPTION  = -1101,	 // ���Ӽ����豸����
    STATUS_DEVICE_IS_OPENED       = -1102,   // �豸�Ѿ���
	STATUS_DEVICE_IS_CLOSED		  = -1103,   // �豸�Ѿ��ر�
    STATUS_MEMORY_NOT_ENOUGH      = -1200,   // û���㹻���ڴ�
	STATUS_DLL_NOT_FIND			  = -1201,	 // û���ҵ���Ӧ��DLL
} DeviceStatus;

/*---------------------------------------------------------------------------------*\
|                                   ������ķ�ʽ
\*---------------------------------------------------------------------------------*/
typedef enum
{
	OF_BYPOSITION = 0x00,		// ͨ��λ�����д�
	OF_BYUSBADDRESS,			// ͨ��USB��ַ��
	OF_USERSERIALNUMBER,		// ͨ��ָ���û����кŴ򿪣���iLevel = 2��
	OF_DEVELOPERSERIALNUMBER,   // ͨ���ƶ����������кŴ򿪣���iLevel = 1��
	OF_FACTORYSERIALNUMBER,		// ͨ���ƶ�����Ψһ���кŴ򿪣���iLevel = 0��
}emOpenDeviceFlag;

/*---------------------------------------------------------------------------------*\
|                                  ���ͼ����������
\*---------------------------------------------------------------------------------*/
typedef enum
{
	// BAYER ��������
	DATA_TYPE_MONO8			  = 0,		//�ڰ�8λ
	DATA_TYPE_MONO10          = 1,		//�ڰ�10λ
	DATA_TYPE_MONO12          = 2,		//�ڰ�12λ
    DATA_TYPE_BAYGR8          = 10,		//��ɫRG8λ
	DATA_TYPE_BAYGR10         = 11,		//��ɫRG10λ
	DATA_TYPE_BAYGR12         = 12,		//��ɫRG12λ
	DATA_TYPE_UNKNOWN		  = -1,		//δ֪����
}emDeviceDataType;

/*---------------------------------------------------------------------------------*\
|                                 BAYERת��ģʽ
\*---------------------------------------------------------------------------------*/
typedef enum
{
	B2RGB_MODE_LINE			= 0,		// Line �������ڲ�ɫ���
	B2RGB_MODE_LAROCHE,					// Laroche �������ڲ�ɫ���
	B2MON_MODE_RAW,						// Raw �������ںڰ����
	B2MON_MODE_AVERAGE,					// Average �������ںڰ����
	B2MON_MODE_MEDIAN,					// Median �������ںڰ����
}emDeviceBayerConvertMode;

/*---------------------------------------------------------------------------------*\
|                                 ͼ�����ݴ����������
\*---------------------------------------------------------------------------------*/
typedef enum
{
	DATA_ISP_RGB24			= 0x00,
	DATA_ISP_RGB32,
	DATA_ISP_MON8,
}emDeviceISPDataType;

/*---------------------------------------------------------------------------------*\
|                                   �������ģʽ
\*---------------------------------------------------------------------------------*/
typedef enum
{
	CONTINUE_CAPTURE_MODE = 0x00,	// ����ģʽ
	SOFT_TRIGGER_MODE,				// ����ģʽ
	HARD_TRIGGER_MODE,				// Ӳ������ģʽ
	SOFT_TRIGGER_RESERVERD_MODE,	// ������Ԥ����ģʽ
	HARD_TRIGGER_RESERVERD_MODE,	// Ӳ��������Ԥ����ģʽ
	UNDEFINED_MODE,					// δ֪ģʽ
}emDeviceCaptureMode;


/*---------------------------------------------------------------------------------*\
|                               ͼ�񴫸�������ģʽ
\*---------------------------------------------------------------------------------*/
typedef enum
{
	SUBSAMPLE_MODE_ROI = 0x00,		//ROI����ģʽ
    SUBSAMPLE_MODE_BIN,				//BIN����ģʽ
    SUBSAMPLE_MODE_SKIP,			//SKIP����ģʽ
	SUBSAMPLE_MODE_SUM				//SUM����ģʽ
}emDeviceSubSampleMode;

/*---------------------------------------------------------------------------------*\
|                                   ���֡�ٶ���
\*---------------------------------------------------------------------------------*/
typedef enum
{
	HIGHEST_SPEED = 0x00,		// ������
	HIGH_SPEED,					// ����
	LOW_SPEED,					// ����
	LOWEST_SPEED,				// ������
}emDeviceFrameSpeed;

/*---------------------------------------------------------------------------------*\
|                                   GPIO���ģʽ����
\*---------------------------------------------------------------------------------*/
typedef enum
{
	GPIO_OUTPUTMODE_HIGHLEVEL = 0x00,	// �ߵ�ƽģʽ
	GPIO_OUTPUTMODE_LOWLEVEL,			// �͵�ƽģʽ
	GPIO_OUTPUTMODE_HIGHPULSE,			// ������ģʽ
	GPIO_OUTPUTMODE_LOWPULSE,			// ������ģʽ
	GPIO_OUTPUTMODE_UNKNOWN,			// δ֪ģʽ
}emGPIOOutputMode;

/*---------------------------------------------------------------------------------*\
|                                   ͼ���ļ��ĸ�ʽ
\*---------------------------------------------------------------------------------*/
typedef enum
{
    FILE_JPG  = 0,					//JPG�ļ���ʽ
    FILE_PNG  = 1,					//PNG�ļ���ʽ
	FILE_BMP  = 2,					//BMP�ļ���ʽ
	FILE_TIFF = 3,					//TIFF�ļ���ʽ
	FILE_GIF  = 4,					//GIF�ļ���ʽ
	FILE_RAW  = 5,					//RAW�ļ���ʽ
}emDSFileType;

/*---------------------------------------------------------------------------------*\
|                                   ͼ��������
\*---------------------------------------------------------------------------------*/
typedef enum
{
	MD_HORIZONTAL	= 0x00,			 //ˮƽ����
	MD_VERTICAL		= 0x01,			 //��ֱ��ת
}emMirrorDirection;

/*---------------------------------------------------------------------------------*\
|                                �ڲ���ʾ�ӿڵ���ʾ��ʽ����
\*---------------------------------------------------------------------------------*/
typedef enum
{
	DISPLAYMODE_SCALE = 0x00,		//������ʾģʽ
	DISPLAYMODE_REAL,				//1��1��ʾģʽ��ʵ�ʴ�С��
}emDisplayMode;

/*---------------------------------------------------------------------------------*\
|                                �ֱ������Ͷ���
\*---------------------------------------------------------------------------------*/
typedef enum
{
	RT_PRESET	= 0x00,				//Ԥ��ֱ��ʷ�ʽ
	RT_ROI,							//ROI��ʽ
}emResolutionType;

/*---------------------------------------------------------------------------------*\
|                               ����������ñ������
\*---------------------------------------------------------------------------------*/
typedef enum
{
	PARAMETER_TEAM_DEFAULT  = 255,			//Ĭ��ȱʡ����
    PARAMETER_TEAM_A        = 0,			//������A
    PARAMETER_TEAM_B        = 1,			//������B
    PARAMETER_TEAM_C        = 2,			//������C
    PARAMETER_TEAM_D        = 3,			//������D
	PARAMETER_TEAM_NUM		= 5,			//���������
}emParameterTeam;

/*---------------------------------------------------------------------------------*\
|                                 ������ݻص�����
\*---------------------------------------------------------------------------------*/
typedef void CALLBACK  ReceiveFrameProc( LPVOID pDevice, BYTE *pImageBuffer, DeviceFrameInfo *pFrInfo, LPVOID lParam);

#endif