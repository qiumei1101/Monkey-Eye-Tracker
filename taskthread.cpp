
#include "taskthread.h"
#include<iostream>
using namespace std;
using namespace cv;
#include <QDebug>
#include<iostream>
#include <sys/timeb.h>
#include<vector>
#include<windows.h>
#include<math.h>
#include<time.h>
#include<mutex>
struct timeb tb;
char tmp[64];
struct timeb tb2;
char tmp2[64];
HANDLE h326a;
HANDLE h326b;
static clock_t start2, end2;
//QT_GUIDEMO *m_pWindow;
//taskthread::taskthread(QT_GUIDEMO *pWindow, QObject *parent):QThread(parent)
taskthread::taskthread()
{
	m_isStop = false;
	Mat a = Mat::zeros(640, 480, CV_8UC3);//全局变量
	currT = 0.0;



	int  A1 = 5;
	if (USING_CAPTURE)
	{
		capture.open(0);
	}
	else
		capture.open("C:/QT_GUIDEMO/QT_GUIDEMO/Movie_0924103642.avi");
	if (!capture.isOpened())
		cout << "fail to open!" << endl;

	capture.set(CV_CAP_PROP_FRAME_WIDTH, 640);//宽度 
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, 480);//高度
	capture.set(CV_CAP_PROP_FPS, 100);//帧率 帧/秒


	fp = fopen("C:\\QT_GUIDEMO\\file29.txt", "a");   //写的方式打开文件
	if (fp == NULL)
	{
		printf("can't open file.txt/n");  exit(1);
	}  //打开文件失败则退出

	

	//m_pWindow = pWindow;
	//Added by  Candy 5/7/2018

	if (OpenUA326_a(0, h326a) != 0)  // 打开设备,得到句柄
	{
		printf("device open error!!\n");
	}

	if (OpenUA326_b(0, h326b) != 0)  // 打开设备,得到句柄
	{
		printf("device open error!!\n");
	}
}


taskthread::~taskthread()
{

	CloseUA326_a(h326a);
	CloseUA326_b(h326b);
}

int taskthread::WriteToDA()
{

	WriteDA(leftEyeX2, leftEyeY2, rightEyeX2, rightEyeY2);


	return 0;
}

int taskthread::WriteDA(vector<float> leftEyeX2, vector<float> leftEyeY2, vector<float> rightEyeX2, vector<float> rightEyeY2)
{


	int x = leftEyeX2.size() - 1;

	daout4(h326b, 2048 + leftEyeX2[x], 2048 + leftEyeY2[x], 2048 + rightEyeX2[x], 2048 + rightEyeY2[x]);
	//	cout << leftEyeY[x] << endl;


	return 0;
}

void delay_msec(int msec)
{
	clock_t now = clock();
	while (clock() - now< msec);
}

void taskthread::run()
{

	MatIterator_<uchar> it, end;

	int index2 = 0;
	int numl = 0;
	int numr = 0;

	float sumxl = 0.0;
	float sumxr = 0.0;
	float sumyl = 0.0;
	float sumyr = 0.0;
	float rl = 0.0;
	float rr = 0.0;
	vector<Rect>Eyes;
	CascadeClassifier cascade;
	cascade.load("C:\opencv\sources\data\haarcascades\haarcascade_eye.xml");
	while (1)
	{
		if (m_isStop)
		{
			break;
		}
		if (USING_CAPTURE)
		{
			
			capture >> a;
			ftime(&tb);
			sprintf(tmp, "%d.%03d\n", tb.time, tb.millitm);
			fputs(tmp, fp);
			
		}
		else
		{
			capture.read(a);
			//resize(a, a, Size(640, 480));
				//ebug() << "data is failed";
		}
			
		//start2 = clock();
		if (a.channels() == 3)
			cvtColor(a, grayImage, CV_BGR2GRAY);
		else
			grayImage = a;

		float minxl = grayImage.cols *2/12+2;
		float maxxl = grayImage.cols / 2-2;
		float minyl = grayImage.rows*5/12+2;
		float maxyl = grayImage.rows*8/12-2;
		float minxr = grayImage.cols / 2 +2;
		float maxxr = grayImage.cols * 9/12-2;
		float minyr = grayImage.rows*5/12+2 ;
		float maxyr = grayImage.rows*8/12-2;

		for (int i = grayImage.cols *2/ 12 ; i <grayImage.cols * 9/ 12 ; i++)
		{

			for (int j = grayImage.rows *5/ 12; j <grayImage.rows *8/ 12; j++)
			{

				//cout << int(grayImage.at<uchar>(i, j)) << endl;
				if (grayImage.at<uchar>(i, j) < 25 && grayImage.at<uchar>(i, j) > 10)
				{
					if (i < grayImage.cols /2)
					{
						numl++;
						sumxl += i;
						sumyl += j;
						if (i < minxl)
							minxl = i;
						if (i > maxxl)
							maxxl = i;
						if (j < minyl)
							minyl = j;
						if (j > maxyl)
							maxyl = j;
					}
					else
						if (i > grayImage.cols *13/ 24)
						{
							numr++;
							sumxr += i;
							sumyr += j;
							if (i < minxr)
								minxr = i;
							if (i > maxxr)
								maxxr = i;
							if (j < minyr)
								minyr = j;
							if (j > maxyr)
								maxyr = j;
						}

				}
			}
		}
	

		float lr = (maxxl - minxl) < (maxyl - minyl) ? (maxxl - minxl) : (maxyl - minyl);
		float rr = (maxxr - minxr) < (maxyr - minyr) ? (maxxr - minxr) : (maxyr - minyr);
		if (numl == 0)
		{
			leftEyeRadius2.push_back(0);
			leftEyeX2.push_back(0);
			leftEyeY2.push_back(0);
		}
			
		else
		{
			leftEyeRadius2.push_back(lr / 2);
			leftEyeX2.push_back(float(sumxl / numl));
			leftEyeY2.push_back(float(sumyl / numl));
		}
		if (numr == 0)
		{
			rightEyeRadius2.push_back(0);
			rightEyeX2.push_back(0);
			rightEyeY2.push_back(0);
		}
		else
		{
			rightEyeRadius2.push_back(rr / 2);
			rightEyeX2.push_back(float(sumxr / numr));
			rightEyeY2.push_back(float(sumyr / numr));
		}	
		
		WriteToDA();

		/*cout << rightEyeX2[index2] << endl;
		cout << rightEyeY2[index2] << endl;		
		cout << rightEyeRadius2[index2] << endl;*/
	    emit send_export_signal(index2,  leftEyeX2,  leftEyeY2, leftEyeRadius2, rightEyeX2,  rightEyeY2, rightEyeRadius2);
		//emit send_export_signal();
		//cout << index2 << endl;
		index2++;	
		delay_msec(10);
		
	}

	/*m_timer = new QTimer();
	connect(m_timer, SIGNAL(timeout()), this, SLOT(Ontimeout()));
	m_timer->start(10);
	exec();*/
}

int taskthread::Ontimeout()
{
	if (m_isStop)
	{
		return -1;
	}

	if (USING_CAPTURE)
	{
		capture >> a;

		ftime(&tb);
		sprintf(tmp, "%d.%03d\n", tb.time, tb.millitm);
		fputs(tmp, fp);

	}
	else
	{
		capture.read(a);
	}
	return 0;
}


void taskthread::stop()
{
	m_isStop = true;
}