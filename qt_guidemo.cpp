#include "qt_guidemo.h"
#include <opencv2/opencv.hpp>
#include <QMetaType> 
using namespace cv;
#include <windows.h>
#include "stdafx.h"

#include<time.h>
#include <sys/timeb.h>


#define  FS 100
FILE  *fp;
DWORD dwThreadID = 0;
HANDLE as = NULL;
taskthread *task;
Mat imageleftROI;
Mat imagerightROI;
Mat a = Mat::zeros(640, 480, CV_8UC3);//全局变量

float currT = 0.0;
int A1 = 100.0; int A2 = 200.0; int A3 = 300.0; int A4 = 100.0;
QImage cvMat2QImage(const cv::Mat& mat)
{
	// 8-bits unsigned, NO. OF CHANNELS = 1  
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)  
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat  
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3  
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{		
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		return QImage();
	}
}


QT_GUIDEMO::QT_GUIDEMO(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//ui.FilterLabel->show();
	//QPixmap pixmap("timg.jpg");
	/*pixmap.fill(Qt::black);
	QPainter painter(&pixmap);
	painter.setPen(Qt::white);
	painter.drawLine(10, 10, 100, 100);*/
	//ui.FilterLabel->setPixmap(pixmap);
	//ui.FilterLabel->setScaledContents(true);
	//ui.FilterLabel->show();

	timer1 = new QTimer(this);
	timer4 = new QTimer(this);
	timer5 = new QTimer(this);

	fp = fopen("C:\\QT_GUIDEMO\\file7.txt", "a");   //写的方式打开文件
	if (fp == NULL)
	{
		printf("can't open file.txt/n");  exit(1);
	}  //打开文件失败则退出
	//string detect_cascade_name = "cascade.xml";
	//detect_cascade.load(detect_cascade_name);
	//CascadeClassifier cascade;
	cascade.load("C:\opencv\sources\data\haarcascades\haarcascade_eye.xml");

	VectLength = 1024;
	currDataPt = 0;
	p1 = (float *)malloc(sizeof(float)*VectLength);
	p2 = (float *)malloc(sizeof(float)*VectLength);

	memset(p1, 0, 1024);
	memset(p2, 0, 1024);

	leftEyeX.reserve(10240);
	leftEyeY.reserve(10240);
	leftEyeRadius.reserve(10240);
	rightEyeX.reserve(10240);
	rightEyeY.reserve(10240);
	rightEyeRadius.reserve(10240);
	flag = 0;
	//connect(ui.pushButton_Calib, SIGNAL(clicked()), this, SLOT(showPlotImage()));
	connect(ui.pushButton_Detect, SIGNAL(clicked()), this, SLOT(detectPushBotton()));
	connect(ui.pushButton_setROI, SIGNAL(clicked()), this, SLOT(showROI()));
	connect(ui.pushButton_Stop, SIGNAL(clicked()), this, SLOT(stopPlotImage()));
	connect(ui.pushButton_Select, SIGNAL(clicked()), this, SLOT(selectPoint()));
	connect(ui.radioButton_LeftEye, SIGNAL(clicked()), this, SLOT(plotleftImage()));
	connect(ui.radioButton_RightEye, SIGNAL(clicked()), this, SLOT(plotrightImage()));
	connect(ui.radioButton_BothEye, SIGNAL(clicked()), this, SLOT(showPlotImage()));

	task = new taskthread();
	qRegisterMetaType<int>("int");
	qRegisterMetaType<vector<float>>("vector<float>");
	//connect(task, SIGNAL(send_export_signal()), this, SLOT(recvData2()), Qt::QueuedConnection);
	task->start();
	connect(task, SIGNAL(send_export_signal(int, vector<float>, vector<float>, vector<float>, vector<float>, vector<float>, vector<float>)), this, SLOT(recvData(int, vector<float>, vector<float>, vector<float>, vector<float>, vector<float>, vector<float>)), Qt::QueuedConnection);
}
int QT_GUIDEMO::recvData2()
{
//	index = index;
	return 0;
}

int QT_GUIDEMO:: recvData(int indexm, vector<float>leftEyeXm, vector<float>leftEyeYm, vector<float>leftEyeRadiusm, vector<float>rightEyeXm, vector<float>rightEyeYm, vector<float>rightEyeRadiusm)
{
	index = indexm;
	leftEyeX = leftEyeXm;
	leftEyeY = leftEyeYm;
	leftEyeRadius = leftEyeRadiusm;
	rightEyeX = rightEyeXm;
	rightEyeY = rightEyeYm;
	rightEyeRadius = rightEyeRadiusm; 
    return 0;
}

//Candy 10-1-2018
QT_GUIDEMO *getQT_GUIDEMO()
{
	static QT_GUIDEMO* form = NULL;
	if (form == NULL)
	{
		form = new QT_GUIDEMO();
	}
	return form;
}
QT_GUIDEMO::~QT_GUIDEMO()
{
	//Added by  Candy 5/7/2018

	fclose(fp);
	if (p1 != NULL)
	{
		free(p1);			
	}
	if (p2 != NULL)
	{
		free(p2);
	}
}

int QT_GUIDEMO::stopPlotImage()
{
	timer1->stop();
	ui.FilterLabel->m_pixmap.fill(Qt::black);
	return 0;
}
int QT_GUIDEMO::selectPoint()
{
	flag = 0;
	return 0;
}

void QT_GUIDEMO::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton&&flag == 0) {
		fClick = event->pos();
		flag = 1;
		cout << fClick.x() << "   fClick	" << fClick.y() << endl;
	}
	else if(event->button() == Qt::LeftButton&&flag == 1) {
		sClick = event->pos();
		flag = 0; 
		cout << sClick.x() << "	 sClick  " << sClick.y() << endl;
	}
	
	
}

int QT_GUIDEMO::showPlotImage()
{
	if (timer4->isActive())
	{
		timer4->stop();
	}
	if (timer5->isActive())
	{
		timer5->stop();
	}
	connect(timer1, SIGNAL(timeout()), this, SLOT(plotPoint()));
	timer1->start(0);
	return 0;
}

int QT_GUIDEMO::plotleftImage()
{

	if (timer1->isActive())
	{
		timer1->stop();
	}
	if (timer5->isActive())
	{
		timer5->stop();
	}
	connect(timer4, SIGNAL(timeout()), this, SLOT(plotLeft()));
	timer4->start(0);

	return 0;
}

int QT_GUIDEMO::plotrightImage()
{
	if (timer1->isActive())
	{
		timer1->stop();
	}
	if (timer4->isActive())
	{
		timer4->stop();
	}
	connect(timer5, SIGNAL(timeout()), this, SLOT(plotRight()));
	timer5->start(0);
	return 0;
}
void QT_GUIDEMO::plotLeft()
{
	
	ui.FilterLabel->plotHorizontalleft(leftEyeX, leftEyeY, leftEyeRadius,index);
	
}


void QT_GUIDEMO::plotRight()
{

	ui.FilterLabel->plotHorizontalright(rightEyeX, rightEyeY, rightEyeRadius, index);

	
}
int QT_GUIDEMO::plotPoint()
{
	ui.FilterLabel->plotHorizontalp1(leftEyeX, leftEyeY, leftEyeRadius, rightEyeX, rightEyeY, rightEyeRadius, index);

	return 0;
}

int QT_GUIDEMO::setEyeROI()
{
	image = a;
    imageleftROI = image(Rect(leftEyeX[index]-leftEyeRadius[index],leftEyeY[index]-leftEyeRadius[index],2*leftEyeRadius[index],2*leftEyeRadius[index]));
	QImage picleftQImage;
	picleftQImage = cvMat2QImage(imageleftROI);
	imagerightROI = image(Rect(rightEyeX[index]-rightEyeRadius[index],rightEyeY[index]-rightEyeRadius[index],2*rightEyeRadius[index], 2 * rightEyeRadius[index]));
	QImage picrightQImage;
	picrightQImage = cvMat2QImage(imagerightROI);

	QPixmap pp = QPixmap::fromImage(picleftQImage);
	pp = pp.scaled(ui.label_ShowLeftEye->size());
	ui.label_ShowLeftEye->setPixmap(pp);
	ui.label_ShowLeftEye->setScaledContents(true);
	ui.label_ShowLeftEye->show();

	QPixmap qq = QPixmap::fromImage(picrightQImage);
	qq = qq.scaled(ui.label_ShowRightEye->size());
	ui.label_ShowRightEye->setPixmap(qq);
	ui.label_ShowRightEye->setScaledContents(true);
	ui.label_ShowRightEye->show();
	return 0;
}

int QT_GUIDEMO::showROI()
{
	timer2->stop();
//elete timer2;
	timer3 = new QTimer(this);
	connect(timer3, SIGNAL(timeout()), this, SLOT(setEyeROI()));
	timer3->start(0);
	return 0;
}

void QT_GUIDEMO::detectPushBotton()
{
	timer2 = new QTimer(this);
	connect(timer2, SIGNAL(timeout()), this, SLOT(displayImage()));
	timer2->start(0);
}

int QT_GUIDEMO::displayImage()
{
	   image = a;
	   circle(image, cv::Point(leftEyeX[index],leftEyeY[index]), leftEyeRadius[index], cv::Scalar(255, 0, 0));
	   rectangle(image, Rect(leftEyeX[index]- leftEyeRadius[index], leftEyeY[index]- leftEyeRadius[index], 2*leftEyeRadius[index], 2*leftEyeRadius[index]), Scalar(0, 0, 255), 5, 1, 0);
	   circle(image, cv::Point(rightEyeX[index], rightEyeY[index]), rightEyeRadius[index], cv::Scalar(255, 0, 0));
	   rectangle(image, Rect(rightEyeX[index]- rightEyeRadius[index], rightEyeY[index]- rightEyeRadius[index],2* rightEyeRadius[index], 2* rightEyeRadius[index]), Scalar(0, 0, 255), 5, 1, 0);
	   QImage picQImage;	
		cvtColor(image, image, CV_BGR2RGB);
		QPixmap picQPixmap;
		picQImage = QImage((uchar*)image.data, image.cols, image.rows, image.cols*image.channels(), QImage::Format_RGB888);
		QPixmap pp = QPixmap::fromImage(picQImage);
		pp = pp.scaled(ui.label_GlobalImage->size());
		ui.label_GlobalImage->setPixmap(pp);
		ui.label_GlobalImage->setScaledContents(true);
		ui.label_GlobalImage->show();
		return 0;
}


