#ifndef FILTERCLASS_H
#define FILTERCLASS_H

#include <QLabel>
#include "ui_filterclass.h"
#include <vector>

using namespace std;

class FilterClass : public QLabel
{
	Q_OBJECT

public:
	FilterClass(QWidget *parent = 0);
	~FilterClass();
	int plotHorizontal(vector<float> lx,vector<float> ly, vector<float> lr, vector<float> rx, vector<float> ry, vector<float> rr, int index);

	int plotHorizontalleft(vector<float> lx, vector<float> ly, vector<float> lr, int index);
	int plotHorizontalright(vector<float> rx, vector<float> ry, vector<float> rr, int index);
	//int plotHorizontalp1(float* p, int length,int index);
	int plotHorizontalp1(vector<float> lx, vector<float> ly, vector<float> lr, vector<float> rx, vector<float> ry, vector<float> rr, int index);
private:
	Ui::FilterClass ui;

public:
	QPixmap m_pixmap;

private:
	

};

#endif // FILTERCLASS_H
