#pragma once
#include <iostream>
#include <vector>
#include "highgui.h"


#ifdef MonkeySEGMENTMATCHDLL_EXPORTS
# define DLLExport _declspec(dllexport)
#else
# define DLLExport _declspec(dllimport)
#endif

using namespace std;
using namespace cv;



#define MIN_DIAMETER_PUPIL 40
#define MAX_DIAMETER_PUPIL 120




class DLLExport MonkeyIRIS {

public:
	MonkeyIRIS();
	~MonkeyIRIS();

	int Monkey_Pupil_Loc(Mat image, int workModel = 1);
	IplImage * mpOriginalImage;
	IplImage * mpSegmentedImage;



	CvPoint mPupilCenter;
	int mPupilRadius;
private:
	std::vector<CvPoint> mCoarsePupilContour;
	std::vector<float> mThetaCoarsePupil;


	

	int mMinPupilDiameter;
	int mMaxPupilDiameter;

};

