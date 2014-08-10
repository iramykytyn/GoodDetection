/**
 * @file	detectobjects.cpp
 * @brief	Searching objects on image implementation
 * @author  Iryna Mykytyn
 *
 * Copyright 2014 by Iryna Mykytyn,
 *
 * This software is the confidential and proprietary information
 * of Iryna Mykytyn ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with Iryna Mykytyn.
 **/

#include "detection.h"



extern int lastX1;
extern int lastY1;
extern int lastX2;
extern int lastY2;
extern unsigned DetectedBread;

vector<Point> DetectedPoints;
CvPoint *line1, *line2 , *line3 ;

int StartDetection ( GOODS type_of_good )
{
    switch ( type_of_good )
    {
    case BLACK_BREAD:
        DetectBread( frame );
        break;
    case WHITE_BREAD:
        DetectBread( frame );
        break;
    default:

    }
}



void DetectBread( IplImage* frame)
{
    IplImage *copy_of_frame = cvCreateImage(cvGetSize(frame2), 8, 1);
   // cvCvtColor(frame2,frame,CV_BGR2GRAY);

    cvSetImageROI(frame, cvRect( lastX1 ,lastY1,lastX2 - lastX1,lastY2 - lastY1 ) );
    cvThreshold(frame,frame,100,255,CV_THRESH_BINARY);
    cvSmooth(frame, frame, CV_GAUSSIAN,3,3);
    cvCanny( frame, frame, 10, 100, 3);

    // создаём ядро
    int radius = 1;
    IplConvKernel* Kern = cvCreateStructuringElementEx(radius*2+1, radius*2+1, radius, radius, CV_SHAPE_ELLIPSE);

    cvDilate(frame, frame, Kern,0);

        CvSeq* contour;
        CvMemStorage *storage = cvCreateMemStorage(0);

        //finding all contours in the image
        cvFindContours(imgThresh, storage, &contour, sizeof(CvContour), CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));

        for( CvSeq* current = contour; current != NULL; current = current->h_next )
        {
                        //obtain a sequence of points of the countour, pointed by the variable 'countour'
                        //current = cvApproxPoly(contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(contour)*0.02, 0);

                        double area = fabs(cvContourArea(current));
                        double perim = cvContourPerimeter(current);

                        // 1/4*CV_PI = 0,079577
                        if ( (area / (perim * perim) > 0.02 && area / (perim * perim)< 0.8 ))// && ( ) )
                        {
                             CvBox2D rect = cvMinAreaRect2( current, 0);
                             if( ( rect.center.x <= ( lastX2 - lastX1 + 1 ) ) || (rect.center.x >= lastX2 - lastX1 - 1 ) )
                             {
                                 std::vector<Point>::iterator it;
                                 if( area > 500 && area < 800 )
                                 {
                                     it = std::find( DetectedPoints.begin(), DetectedPoints.end(), Point(rect.center.x, rect.center.y));
                                     if( it == DetectedPoints.end())
                                     {
                                         DetectedPoints.push_back( Point(rect.center.x, rect.center.y) );
                                        // qDebug()<<"x:"<<rect.center.x<<", y = "<<rect.center.y ;

                                        if( ( rect.center.x <= (lastX2 - lastX1 )/2 + 0.2 )  && ( rect.center.x >= (lastX2 - lastX1)/2 - 0.2 ) )
                                        {
                                            ++DetectedBread;
                                        }
                                     }

                                 }
                                 else if( area > 1000 && area < 1400 )
                                 {
                                     it = std::find( DetectedPoints.begin(), DetectedPoints.end(), Point(rect.center.x, rect.center.y));
                                     if( it == DetectedPoints.end())
                                     {
                                         DetectedPoints.push_back( Point(rect.center.x, rect.center.y) );
                                         if( ( rect.center.x <= (lastX2 - lastX1 )/2 + 0.2)  && ( rect.center.x >= (lastX2 - lastX1)/2 - 0.2 ) )
                                         {
                                             DetectedBread += 2;
                                         }
                                     }

                                }
                             }
                        }
        }


        cvReleaseMemStorage(&storage);
 }


void SetScope( void )
{
    line1 = new CvPoint[2];
    line2 = new CvPoint[2];
    line3 = new CvPoint[2];

    line1[0].x = lastX1;  line1[0].y = lastY1;
    line1[1].x = lastX1;  line1[1].y = lastY2;

    line2[0].x = (lastX1 + lastX2)/2;   line2[0].y = lastY1;
    line2[1].x = (lastX1 + lastX2)/2;   line2[1].y = lastY2;

    line3[0].x = lastX2;  line3[0].y = lastY1;
    line3[1].x = lastX2;  line3[1].y = lastY2;
}

void DrawScope( IplImage* img)
{
    cvLine(img, *(line1+1), *line1, cvScalar(0,255,0),1);
    cvLine(img, *(line2+1), *line2, cvScalar(255,0,0),1);
    cvLine(img, *(line3+1), *line3, cvScalar(0,255,0),1);
}

