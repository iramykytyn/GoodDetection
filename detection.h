/**
 * @file	detectobjects.h
 * @brief	Searching objects on image header
 * @author  Iryna Mykytyn
 *
 * Copyright 2014 by Iryna Mykytyn,
 *
 * This software is the confidential and proprietary information
 * of Iryna Mykytyn ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with mnxoid.
 **/

#ifndef DETECTION_H
#define DETECTION_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


enum GOODS { WHITE_BREAD, BLACK_BREAD }; // -->enum of goods for detection

int StartDetection ( GOODS );


/**
 * @brief       Function that do detection of shapes of bread forms
 * @param       [in]    pointer to image
 **/

void DetectBread( IplImage* frame);

void SetScope( void );

void DrawScope( IplImage* img);

#endif // DETECTION_H
