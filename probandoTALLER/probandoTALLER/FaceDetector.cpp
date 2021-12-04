#include "FaceDetector.h"

#include <sstream>
#include <vector>
#include <string>


FaceDetector::FaceDetector() : scaleFactor_(1.05), minNeighbors_(8), imageWidth_(50), imageHeight_(50) {
    face_cascade.load("C:/Users/jimimix/Desktop/datita/classifiers/haarcascade_frontalface_alt.xml");
}

std::vector<cv::Rect> FaceDetector::detectFaceRectangles(const cv::Mat& frame) {

    std::vector<cv::Rect> faces;
    Mat imageGray;
    
    // Detecto las caras (Se debe pasar la imagen a escala de grises
    cvtColor(frame, imageGray, COLOR_BGR2GRAY);
    // Aumento el constraste de una imagen
    equalizeHist(imageGray, imageGray);
    face_cascade.detectMultiScale(imageGray,
        faces,
        scaleFactor_,
        minNeighbors_,
        0 | CASCADE_SCALE_IMAGE,
        Size(imageWidth_, imageHeight_));

    return faces;
}
