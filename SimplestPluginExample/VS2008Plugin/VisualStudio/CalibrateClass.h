#include "opencv2/calib3d/calib3d.hpp"

#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class CalibrateClass
{
public:
	static int MyFunction();

	static int CalibrateFunction(std::vector<cv::Point3f> inputObjectPoints, std::vector<cv::Point2f> inputImagePoints, int rows, int cols, double* res);
};