#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;


#define filterWidth 3
#define filterHeight 3

double filter[filterHeight][filterWidth] =
        {
                1, 2, 1,
                2, 4, 2,
                1, 2, 1
        };

void salt(Mat image){
    RNG rng;
    double x = image.rows * image.cols * 0.1, y = image.rows * image.cols * 0.1;   //для уровня шума
    for(int i = 0; i < x; i++)    image.at<uchar>(rng.uniform(0, image.rows), rng.uniform(0, image.cols)) = 0;
    for(int i = 0; i < y; i++)    image.at<uchar>(rng.uniform(0, image.rows), rng.uniform(0, image.cols)) = 255;
}

void shum(Mat image, int n) {
    uchar * data = image.data;
    vector<int> values;
    for (int x = 0; x < (image.rows * image.cols); x++) {
        for (size_t i = 0; i < n; i++) {
            values.push_back(data[x + i]);
        }
        sort(values.begin(), values.end());

        image.data[x] = values[4]; // 4 is the median  of 9 plus the index number (0-4) ...
        values.clear();
    }
}

int main(int argc, char** argv ) {
    Mat out, image = imread("/home/o2b3k/losh.jpg", 1);
    if (!image.data) return -1;


    cvtColor(image, image, CV_RGB2GRAY, 1);
    namedWindow("Original", WINDOW_AUTOSIZE);
    imshow("Original", image);

    salt(image);
    namedWindow("Salt and pepper", WINDOW_AUTOSIZE);
    imshow("Salt and pepper", image);



    shum(image, 9);
    namedWindow("Gauss", CV_WINDOW_AUTOSIZE);
    imshow("Gauss", image);

    waitKey(0);
    return 0;


}