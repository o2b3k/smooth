#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;

int main(int argc, char** argv)
{
    namedWindow("Before" , CV_WINDOW_AUTOSIZE);

    // Load the source image
    Mat src = imread( "/home/o2b3k/losh.jpg", 1);

    // Create a destination Mat object
    Mat dst;

    // display the source image
    imshow("Before", src);

    for (int i=1; i<rand() % 255 +1; i=i+2)
    {
        //smooth the image in the "src" and save it to "dst"
        blur(src, dst, Size(i,i));

        //show the blurred image with the text
        imshow( "Smoothing by avaraging", dst );

        //wait for 1 seconds
        waitKey(1000);
    }
}
