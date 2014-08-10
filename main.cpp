
#include "detection.h"

extern  IplImage *frame2;
extern int lastX1;
extern int lastY1;

extern int lastX2;
extern int lastY2;
extern unsigned DetectedBread;

extern char* PathToVideo;



int main( void )
{
   StartDetection( BLACK_BREAD );

   return 0;
}

