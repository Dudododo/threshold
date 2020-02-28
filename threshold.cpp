#include <opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
	cv::Mat scrMat = imread("C:\\Users\\duzhi\\Pictures\\Saved Pictures\\1.jpg");
	int hight = scrMat.rows;
	int width = scrMat.cols;
	uchar threshold = 100;

	for (int j = 0; j < hight; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar average = (scrMat.at<Vec3b>(j, i)[0] + scrMat.at<Vec3b>(j, i)[1] + scrMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold)
			{
				scrMat.at<Vec3b>(j, i)[0] = 255;
				scrMat.at<Vec3b>(j, i)[1] = 255;
				scrMat.at<Vec3b>(j, i)[2] = 255;
			}
			else
			{
				scrMat.at<Vec3b>(j, i)[0] = 0;
				scrMat.at<Vec3b>(j, i)[1] = 0;
				scrMat.at<Vec3b>(j, i)[2] = 0;
			}
		}
	}
	imshow("ImputImage", scrMat);

	waitKey(0);
	return 0;
}
