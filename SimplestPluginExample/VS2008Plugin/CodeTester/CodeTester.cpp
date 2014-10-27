// CodeTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../VisualStudio/CalibrateClass.h"



int _tmain(int argc, _TCHAR* argv[])
{
	int resultVertCount = 9;

	double imagePoints[24] = { 1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3 };

	std::vector<cv::Point2f> imagePointsVec;
	for (int r = 0; r < resultVertCount; ++r)
	{
		imagePointsVec.push_back(cv::Point2f(imagePoints[r], imagePoints[r + 1]));
	}

	double objectPoints[24] = { 1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3,
		1.1, 2.2, 3.3 };

	std::vector<cv::Point3f> objectPointsVec;
	for (int r = 0; r < resultVertCount; ++r)
	{
		objectPointsVec.push_back(cv::Point3f(objectPoints[r], objectPoints[r + 1], objectPoints[r + 2]));
	}

	double res[9];
	CalibrateClass::CalibrateFunction(objectPointsVec, imagePointsVec, 600, 600, res);

	return 0;
}

