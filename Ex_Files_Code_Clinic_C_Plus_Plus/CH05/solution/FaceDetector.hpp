/**
 * FaceDetector.hpp by Olivia Stone for Code Clinic: C++
 **/

#ifndef FACEDETECTOR_H_
#define FACEDETECTOR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

#include <gif_lib.h>
#include <opencv2/opencv.hpp>

#include "json/json.h" // JSON support http://jsoncpp.sourceforge.net

#define HAAR_CASCADE_PATH "/usr/share/OpenCV/haarcascades/haarcascade_frontalface_alt2.xml"

class FaceDetector
{
    public:
        int loadCascade();
        int loadImage(std::string imagePath);
        int detectFaces();
        void displayImage();
        void saveJSON();

    private:
        std::string imagePath_;
        cv::Mat image_;
        cv::CascadeClassifier faceHaarCascade_;
        std::vector<cv::Rect> faces_;

        void shrinkImage(int maxWidth, int maxHeight);
};

#endif // FACEDETECTOR_H_