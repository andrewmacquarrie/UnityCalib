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

