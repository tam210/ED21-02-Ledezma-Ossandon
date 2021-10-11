#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp> //para cascadas
#include <iostream>
using namespace cv;
using namespace std;
void main() {
	string path = "Resources/test_video2.mp4";        //hay k documentar
	VideoCapture cap(path);
	Mat img;
	while (true) {
		cap.read(img);
		CascadeClassifier faceCascade;
		faceCascade.load("Resources/haarcascade_frontalface_default.xml");
		vector<Rect> faces;
		faceCascade.detectMultiScale(img, faces, 1.1, 20);
		for (int i = 0; i < faces.size(); i++) {
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 3);
		}
		imshow("Image", img);
		waitKey(5);
	}
}
