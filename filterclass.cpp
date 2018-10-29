#include "filterclass.h"
#include <QPainter>
#include<iostream>
#include <vector>
using namespace std;

FilterClass::FilterClass(QWidget *parent)
	: QLabel(parent)
{
	ui.setupUi(this);
	m_pixmap = QPixmap(ui.labelTopFilter->width(), ui.labelTopFilter->height());
	
}

FilterClass::~FilterClass()
{


}



int FilterClass::plotHorizontal(vector<float> lx, vector<float> ly, vector<float> lr, vector<float> rx, vector<float> ry, vector<float> rr, int index)
{
	
	if (index % 200 == 0)
		m_pixmap.fill(Qt::black);

	QPainter painter(&m_pixmap);
	painter.setPen(Qt::white);
	painter.drawLine(0, ui.labelTopFilter->height() / 2, ui.labelTopFilter->width(), ui.labelTopFilter->height() / 2);
	painter.drawLine(ui.labelTopFilter->width() / 20, 0, ui.labelTopFilter->width() / 20, ui.labelTopFilter->height());


	int x = (rx.size() - 1) % 200;



	painter.setPen(QColor(255, 255, 255));
	painter.drawPoint(QPoint(x, rx[x] - 700));
	painter.drawLine(x, rx[x] - 700, x + 1, rx[x - 1] - 700);

	painter.setPen(QColor(255, 0, 255));
	painter.drawPoint(QPoint(x, ry[x] - 300 - 4 * ui.labelTopFilter->height() / 40));
	painter.drawLine(x, ry[x] - 300 - 4 * ui.labelTopFilter->height() / 40
		, x + 1, ry[x - 1] - 300 - 4 * ui.labelTopFilter->height() / 40);

	painter.setPen(QColor(255, 255, 0));
	painter.drawPoint(QPoint(x, rr[x]));
	painter.drawLine(x, rr[x], x + 1, rr[x - 1]);


	painter.setPen(QColor(12, 255, 230));
	painter.drawPoint(QPoint(x, ly[index] - 400 - 4 * ui.labelTopFilter->height() / 20));
	painter.drawLine(x, ly[index] - 400 - 4 * ui.labelTopFilter->height() / 20, x + 1, ly[index + 1] - 400 - 4 * ui.labelTopFilter->height() / 20);

	painter.setPen(QColor(0, 255, 0));
	painter.drawPoint(QPoint(x, lr[index] - 400 - 8 * ui.labelTopFilter->height() / 20));
	painter.drawLine(x, lr[index] - 400 - 8 * ui.labelTopFilter->height() / 20, x + 1, lr[index + 1] - 400 - 8 * ui.labelTopFilter->height() / 20);

	painter.setPen(QColor(20, 255, 0));
	painter.drawPoint(QPoint(x, rx[index] - 400 + 4 * ui.labelTopFilter->height() / 20));
	painter.drawLine(x, rx[index] - 400 + 4 * ui.labelTopFilter->height() / 20, x + 1, rx[index + 1] - 400 + 4 * ui.labelTopFilter->height() / 20);

	painter.setPen(QColor(255, 0, 255));
	painter.drawPoint(QPoint(x, ry[index] - 400 + 8 * ui.labelTopFilter->height() / 20));
	painter.drawLine(x, ry[index] - 400 + 8 * ui.labelTopFilter->height() / 20
	, x + 1, ry[index + 1] - 400 + 8 * ui.labelTopFilter->height() / 20);
	

	ui.labelTopFilter->setPixmap(m_pixmap);
	ui.labelTopFilter->setScaledContents(true);
	ui.labelTopFilter->show();
	return 0;
}
int FilterClass::plotHorizontalleft(vector<float> lx, vector<float> ly, vector<float> lr, int index)
{
	if (index % 200 == 0)
		m_pixmap.fill(Qt::black);

	QPainter painter(&m_pixmap);
	painter.setPen(Qt::white);
	painter.drawLine(0, ui.labelTopFilter->height() / 2, ui.labelTopFilter->width(), ui.labelTopFilter->height() / 2);
	painter.drawLine(ui.labelTopFilter->width() / 20, 0, ui.labelTopFilter->width() / 20, ui.labelTopFilter->height());


	int x = (lx.size() - 1) % 200;
	//cout << lx[x] << endl;
	painter.setPen(QColor(255, 221, 230));
	// float y1 = sin(lx[x]) + 100;
	painter.drawPoint(QPoint(x, lx[x] - 300 - 5));

	painter.setPen(QColor(255, 100, 230));
	//float y2 = sin(ly[x]) + 90;
	painter.drawPoint(QPoint(x, ly[x] - 300 - 10));

	painter.setPen(QColor(255, 150, 230));
	//float y3 = sin(lr[x]) + 140;
	painter.drawPoint(QPoint(x, lr[x] - 10));

	ui.labelTopFilter->setPixmap(m_pixmap);
	ui.labelTopFilter->setScaledContents(true);
	ui.labelTopFilter->show();
	return 0;
}
int FilterClass::plotHorizontalright( vector<float> rx, vector<float> ry, vector<float> rr, int index)
{
	if (index % 200 == 0)
		m_pixmap.fill(Qt::black);

	QPainter painter(&m_pixmap);
	painter.setPen(Qt::white);
	painter.drawLine(0, ui.labelTopFilter->height() / 2, ui.labelTopFilter->width(), ui.labelTopFilter->height() / 2);
	painter.drawLine(ui.labelTopFilter->width() / 20, 0, ui.labelTopFilter->width() / 20, ui.labelTopFilter->height());


	int x = (rx.size() - 1) % 200;
	
	painter.setPen(QColor(255, 150, 210));
	//float y4 = sin(rx[x]) + 130;
	painter.drawPoint(QPoint(x, rx[x] - 700 - 10));

	painter.setPen(QColor(255, 150, 170));
	//float y5 = sin(ry[x]) + 150;
	painter.drawPoint(QPoint(x, ry[x] - 300 - 20));

	painter.setPen(QColor(255, 150, 190));
	//float y6 = sin(rr[x]) + 160;
	painter.drawPoint(QPoint(x, rr[x]));

	ui.labelTopFilter->setPixmap(m_pixmap);
	ui.labelTopFilter->setScaledContents(true);
	ui.labelTopFilter->show();
	return 0;
}


int FilterClass::plotHorizontalp1(vector<float> lx, vector<float> ly, vector<float> lr, vector<float> rx, vector<float> ry, vector<float> rr, int index)
{
	
	if(index%200==0)
		m_pixmap.fill(Qt::black);

	QPainter painter(&m_pixmap);
	painter.setPen(Qt::white);
	painter.drawLine(0, ui.labelTopFilter->height() / 2, ui.labelTopFilter->width(), ui.labelTopFilter->height() / 2);
	painter.drawLine(ui.labelTopFilter->width() / 20, 0, ui.labelTopFilter->width() / 20, ui.labelTopFilter->height());

	
	int x = (lx.size() - 1) % 200;
	//cout << lx[x] << endl;
	painter.setPen(QColor(255, 221, 230));
   // float y1 = sin(lx[x]) + 100;
	painter.drawPoint(QPoint(x,lx[x]-300-5));

	painter.setPen(QColor(255, 100, 230));
	//float y2 = sin(ly[x]) + 90;
	painter.drawPoint(QPoint(x, ly[x]-300-10));

	painter.setPen(QColor(255, 150, 230));
	//float y3 = sin(lr[x]) + 140;
	painter.drawPoint(QPoint(x, lr[x]-10));

	painter.setPen(QColor(255, 150, 210));
	//float y4 = sin(rx[x]) + 130;
	painter.drawPoint(QPoint(x, rx[x]-700-10));

	painter.setPen(QColor(255, 150, 170));
	//float y5 = sin(ry[x]) + 150;
	painter.drawPoint(QPoint(x, ry[x]-300-20));

	painter.setPen(QColor(255, 150, 190));
	//float y6 = sin(rr[x]) + 160;
	painter.drawPoint(QPoint(x, rr[x]));

	/*painter.setPen(QColor(255, 0, 255));
	painter.drawPoint(QPoint(x, ly[x]));*/

	//int x_L = lx.size();

	//float x = float(x_L - 1) / 1024.0*200.0;
	//float y = lx[x_L - 1] * 0 + 100;
	//painter.drawPoint(QPoint(x, y));
	/*
	for (int i = 0; i < length -1; i++)
	{
		int x = (length - 1) % 200;
		float x = float(index)/index*200.0;
		float y = q[length - 1] + 100;
		painter.drawPoint(QPoint(x, y));
	}*/

	
	ui.labelTopFilter->setPixmap(m_pixmap);
	ui.labelTopFilter->setScaledContents(true);
	ui.labelTopFilter->show();
	return 0;
}
