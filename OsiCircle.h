#ifndef OSI_CIRCLE_H
#define OSI_CIRCLE_H
#include <iostream>
#include "highgui.h"

namespace MonkeyIris
{
    class OsiCircle
    {

    public :
        OsiCircle ( ) ;
        ~OsiCircle ( ) ;
        OsiCircle ( const CvPoint & rCenter , int rRadius ) ;
        void computeCircleFitting ( const std::vector<CvPoint> & rPoints ) ;
        void drawCircle ( IplImage * pImage , const CvScalar & rColor = cvScalar(255) , int thickness = 1 ) ;
        CvPoint getCenter ( ) const ;
        int getRadius ( ) const ;
        void setCenter ( const CvPoint & rCenter ) ;
        void setRadius ( int rRadius ) ;
        void setCircle ( const CvPoint & rCenter , int rRadius ) ;
        void setCircle ( int rCenterX , int rCenterY , int rRadius ) ;


    private :
        CvPoint mCenter ;
        int mRadius ;
    } ; 

} 

#endif

