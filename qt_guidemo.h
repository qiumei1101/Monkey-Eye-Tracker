#ifndef QT_GUIDEMO_H
#define QT_GUIDEMO_H

#include <QMouseEvent>
#include <QTimer>
#include <QtWidgets/QMainWindow>
#include <opencv2/opencv.hpp>
#include "ui_qt_guidemo.h"
#include <string>
#include "MonkeyIris.h"
#include<vector>
#include <iostream>
#include "stdafx.h"
#include "windows.h"
//#include <IDevice.h>
#include"taskthread.h"
//#include<qthread.h>
#include<map>
#include<mutex>
#define USING_CAPTURE false
using namespace std;
using namespace cv;

extern Mat a;


static VideoCapture capture;
class QT_GUIDEMO : public QMainWindow
{
	Q_OBJECT

public:
	
	QT_GUIDEMO(QWidget *parent = 0);
	~QT_GUIDEMO();
	Ui::QT_GUIDEMOClass ui;
	//int ManualToDA(vector<float> leftEyeXtoDA, vector<float> leftEyeYtoDA, vector<float> rightEyeXtoDA, vector<float> rightEyeYtoDA);

    
public slots:
	int plotPoint();
	void plotLeft();
	void plotRight();
	void detectPushBotton();
	int displayImage();
	int showROI();
	int setEyeROI();
	
	int showPlotImage();
	int plotleftImage();
	int plotrightImage();
	int stopPlotImage();
	void mousePressEvent(QMouseEvent *event);
	int selectPoint();
	int recvData2();
	int recvData(int indexm, vector<float>leftEyeXm, vector<float>leftEyeYm, vector<float>leftEyeRadiusm, vector<float>rightEyeXm, vector<float>rightEyeYm, vector<float>rightEyeRadiusm);
	//int ManualDA();
private:
	QLabel *label;
	QPushButton *btn;
	
public:
	Mat image;
	CascadeClassifier cascade;
	
	Rect eyeRect, leftEyeRect, rightEyeRect;
	QTimer *timer1, *timer2, *timer3, *timer4, *timer5, *timer6;

	  vector<float> leftEyeX;
	 vector<float> leftEyeY;
	 vector<float> leftEyeRadius;
	
	 vector<float> rightEyeX;
	 vector<float> rightEyeY;
	 vector<float> rightEyeRadius;
	
	
	int index;
	int start;
	int end;
	int flag;
	QPoint fClick, sClick;
	int currDataPt;
	int VectLength;
	float *p1, *p2;
};
QT_GUIDEMO* getQT_GUIDEMO();
#endif // QT_GUIDEMO_H
