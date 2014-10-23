// in myclass.cpp
#include "CalibrateClass.h"
#include "opencv2/calib3d/calib3d.hpp"

#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void fprintMatrix(Mat matrix, string name);  
void fprintfVectorMat(vector< Mat> matrix, string name); 

int CalibrateClass::MyFunction()
{
	Mat im = cv::imread("C:\\Users\\localadmin\\Pictures\\google.png");

	std::vector<cv::Point3f> inputObjectPoints;
	inputObjectPoints.push_back(cv::Point3f(1.0f, 0.0f, 0.0f));
	inputObjectPoints.push_back(cv::Point3f(2.0f, 0.0f, 0.0f));
	inputObjectPoints.push_back(cv::Point3f(3.0f, 0.0f, 0.0f));
	inputObjectPoints.push_back(cv::Point3f(4.0f, 0.0f, 0.0f));
	inputObjectPoints.push_back(cv::Point3f(5.0f, 0.0f, 0.0f));
	inputObjectPoints.push_back(cv::Point3f(6.0f, 0.0f, 0.0f));
	std::vector<std::vector<cv::Point3f> > objectPoints;
	objectPoints.push_back(inputObjectPoints);

	std::vector<cv::Point2f> inputImagePoints;
	inputImagePoints.push_back(cv::Point2f(1.0f, 1.0f));
	inputImagePoints.push_back(cv::Point2f(2.0f, 2.0f));
	inputImagePoints.push_back(cv::Point2f(3.0f, 3.0f));
	inputImagePoints.push_back(cv::Point2f(4.0f, 4.0f));
	inputImagePoints.push_back(cv::Point2f(5.0f, 5.0f));
	inputImagePoints.push_back(cv::Point2f(6.0f, 6.0f));
	std::vector<std::vector<cv::Point2f> > imagePoints;
	imagePoints.push_back(inputImagePoints);
	
	vector< Mat> rvecs, tvecs;
	Mat distortion_coeffs(8, 1, CV_64F);
	Mat1d cameraMatrix = (Mat1d(3, 3) <<
		300, 0, 50,
		0, 300, 100,
		0, 0, 1);

	int flags = CV_CALIB_USE_INTRINSIC_GUESS;

	cv::calibrateCamera(objectPoints, imagePoints, cv::Size2i(im.rows, im.cols), cameraMatrix, distortion_coeffs, rvecs, tvecs, flags);
	

	fprintMatrix(cameraMatrix, "intrinsic.txt");
	fprintMatrix(distortion_coeffs, "distortion_coeffs.txt");

	fprintfVectorMat(rvecs, "rotation.txt");
	fprintfVectorMat(tvecs, "translation.txt");

	return im.rows;
}

void fprintfVectorMat(vector< Mat> matrix, string name)
{
	FILE * fp;
	fp = fopen(name.c_str(), "w");
	int i, j;
	printf("%s size %d, %d\n", name.c_str(), matrix.size(), matrix[0].cols, matrix[0].rows);
	for (i = 0; i< matrix.size(); ++i)
	{
		for (int j = 0; j< matrix[i].rows; ++j)
		{
			for (int k = 0; k< matrix[i].cols; ++k)
			{
				fprintf(fp, "%lf ", matrix[i].at<  double >(j, k));
			}
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n");
	}


	fclose(fp);
}

void fprintMatrix(Mat matrix, string name)
{
	FILE * fp;
	fp = fopen(name.c_str(), "w");
	int i, j;
	printf("%s size %d %d\n", name.c_str(), matrix.cols, matrix.rows);
	for (i = 0; i< matrix.rows; ++i)
	{
		for (j = 0; j< matrix.cols; ++j)
		{
			fprintf(fp, "%lf ", matrix.at<  double >(i, j));
		}
		fprintf(fp, "\n");
	}

	fclose(fp);
}