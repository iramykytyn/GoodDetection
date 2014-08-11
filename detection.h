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
#define OK 0 // -> macro for returning in function in case everething is OK
#define ERROR_001 -1  // -> this type of error mean that
                      // -> there is not fubction to detect default type of goods

using namespace std;
using namespace cv;


enum GOODS { WHITE_BREAD, BLACK_BREAD }; // -->enum of goods for detection
                                        // ? this enum should change when extended user add new good
                                        // ?   DISCUSE HOW TO CHANGE IT

/**
 * @brief       Function start detection of goods, type of good set as parameter
 * @param       [in]    one of the enum GOODS value
 * @return      ERROR_001 or OK
 **/
int StartDetection ( GOODS );

/**
 * @brief       Function that organise cicle for detection of shapes of bread forms
 * @param       [in]  no params
 * @return      OK
 **/
int MakeBreadDetection( void );

/**
 * @brief       Function that do detection of shapes of bread forms
 * @param       [in]    pointer to image
 **/
void DetectBread( IplImage* frame);

void SetScope( void );

void DrawScope( IplImage* img);

IplImage* GetImageFromWemcam();

#endif // DETECTION_H
