#include "opencv2/opencv.hpp"
#include "opencv2/core/types_c.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "imgui.h"

using namespace std;
using namespace cv;

int main() {

	Mat frame;
	//--- INITIALIZE VIDEOCAPTURE
	VideoCapture cap;
	// open the default camera using default API
	// cap.open(0);
	// OR advance usage: select any API backend
	int deviceID = 0;             // 0 = open default camera
	int apiID = cv::CAP_ANY;      // 0 = autodetect default API
	// open selected camera using selected API
	//cap.open(deviceID + apiID);
	//// check if we succeeded
	//if (!cap.isOpened()) {
	//	cerr << "ERROR! Unable to open camera\n";
	//	return -1;
	//}

	Mat src;
	src = imread("C://opencv//test.jpg", -1);
	if (src.empty()) return -1;

	//show image
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", src);
	waitKey(0);
	destroyWindow("image");

	//calculate histogram
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	int histSize = 256;
	float range[] = { 0, 256 }; //the upper boundary is exclusive
	const float* histRange[] = { range };
	bool uniform = true, accumulate = false;
	Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, histRange, uniform, accumulate);

	int hist_w = 512, hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	for (int i = 0; i < histSize; i++)
	{
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(200, 50, 50), 2, 8, 0);
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(50, 200, 50), 2, 8, 0);
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(50, 50, 200), 2, 8, 0);
	}

	//show histogram
	namedWindow("histogram", WINDOW_AUTOSIZE);
	imshow("histogram", histImage);
	waitKey();
	destroyWindow("histogram");

	//

	return 0;
}
