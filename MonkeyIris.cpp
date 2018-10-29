#include"MonkeyIris.h"
#include <fstream>
#include <stdexcept>
#include "cv.h"
#include "OsiEye.h"
#include "OsiProcessings.h"
#include "OsiManager.h"
using namespace MonkeyIris;



OsiCircle mPupil;



int MonkeyIRIS::Monkey_Pupil_Loc(Mat image,int workModel)
{
	if (image.channels() != 1)
		cvtColor(image, image, CV_BGR2GRAY);

	mpOriginalImage = cvCreateImage(cvSize(image.cols, image.rows), IPL_DEPTH_8U, 1);
	IplImage imgTmp = image;
	cvCopy(&imgTmp, mpOriginalImage);
	int minPupilDiameter = MIN_DIAMETER_PUPIL;
	int maxPupilDiameter = MAX_DIAMETER_PUPIL;

	if (!mpOriginalImage)
	{
		throw runtime_error("Cannot segment image because original image is not loaded");
	}

	mpSegmentedImage = cvCreateImage(cvGetSize(mpOriginalImage), IPL_DEPTH_8U, 3);
	cvCvtColor(mpOriginalImage, mpSegmentedImage, CV_GRAY2BGR);
	
	OsiProcessings op;
	op.detectPupil(mpOriginalImage, mPupil, minPupilDiameter, maxPupilDiameter);
	

	mPupilCenter = mPupil.getCenter();
	mPupilRadius = mPupil.getRadius();
	return 0;
}




MonkeyIRIS::MonkeyIRIS()
{
	mpOriginalImage = 0;
	mpSegmentedImage = 0;
	mPupil.setCircle(0, 0, 0);
	mMinPupilDiameter = MIN_DIAMETER_PUPIL;
	mMaxPupilDiameter = MAX_DIAMETER_PUPIL;
	
}

MonkeyIRIS::~MonkeyIRIS()
{
	cvReleaseImage(&mpSegmentedImage);
	cvReleaseImage(&mpOriginalImage);
	mCoarsePupilContour.clear();
	mThetaCoarsePupil.clear();

}
