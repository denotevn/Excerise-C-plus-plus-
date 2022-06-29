/**
 * FaceDetectorMain.cpp by Olivia Stone for Code Clinic: C++
 **/

#include <iostream>

#include "FaceDetector.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		cerr << "ERROR: MIssing argument - path to image" << endl;
		return 1;
	}

    FaceDetector fd;
    fd.loadCascade();
   
    if (int ret = fd.loadImage(argv[1]))
    {
        return ret;
    }

    cout << endl << "Loaded " << argv[1] << endl;
    int faceCount = fd.detectFaces();
    cout << endl << "Detected " << faceCount << " faces" << endl;

    cout << endl;
    fd.saveJSON();

    cout << endl;
    fd.displayImage();

    return 0;
}