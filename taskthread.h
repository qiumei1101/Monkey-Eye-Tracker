#pragma once
#include <QThread>
#include"QT_GUIDEMO.h"
#include<QTimer>
#include "ua326d.h"

extern float currT;


class taskthread :
	public QThread
{
	Q_OBJECT
public:
	
	taskthread();
	 bool m_isStop;
	
	~taskthread();
	void run();
	int  WriteDA(vector<float> leftEyeX2, vector<float> leftEyeY2, vector<float> rightEyeX2, vector<float> rightEyeY2);
	int WriteToDA();
public:
	vector<float> leftEyeX2;
	vector<float> leftEyeY2;
	vector<float> leftEyeRadius2;
	vector<float> rightEyeX2;
	vector<float> rightEyeY2;
	vector<float> rightEyeRadius2;
	vector<float> STtime2;
	int index2;
	//VideoCapture capture2;
	//Mat image2;
	void stop();
	
	FILE  *fp;
	FILE  *fp2;
signals:
	 void startm(); 
	 void send_export_signal(int index2, vector<float> leftEyeX2, vector<float> leftEyeY2, vector<float> leftEyeRadius2,vector<float> rightEyeX2, vector<float> rightEyeY2, vector<float> rightEyeRadius2);
	 //void send_export_signal();
public slots:
    int Ontimeout();
protected:
	Mat grayImage;

	QTimer *m_timer;
};

