#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "CalibrateClass.h"
#include "Plugin.h"

using namespace cv;
using namespace std;



// Link following functions C-style (required for plugins)
extern "C"
{

	EXPORT_API double fillSomeArrayData(double* imagePoints, double* objectPoints, int resultVertCount, double* res)
	{
		std::vector<cv::Point2f> imagePointsVec;
		for (int r = 0; r < resultVertCount; ++r)
		{
			imagePointsVec.push_back(cv::Point2f(imagePoints[r * 3], imagePoints[r * 3 + 1]));
		}

		std::vector<cv::Point3f> objectPointsVec;
		for (int r = 0; r < resultVertCount; ++r)
		{
			objectPointsVec.push_back(cv::Point3f(objectPoints[r * 3], objectPoints[r * 3 + 1], objectPoints[r * 3 + 2]));
		}

		return CalibrateClass::CalibrateFunction(objectPointsVec, imagePointsVec, 600, 600, res);
	}

// The functions we will call from Unity.
//
const EXPORT_API char*  PrintHello(){
	int i = CalibrateClass::MyFunction();
	return "Hello";
}

int EXPORT_API PrintANumber(){
	return CalibrateClass::MyFunction();
}

int EXPORT_API AddTwoIntegers(int a, int b) {
	return a + b;
}

float EXPORT_API AddTwoFloats(float a, float b) {
	return a + b;
}

} // end of export C block

