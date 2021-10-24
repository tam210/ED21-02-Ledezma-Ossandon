#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp> //para cascadas
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include "Node.hpp"
#include "Node.cpp"
#include "LinkedList.cpp"
#include <stdlib.h>

using namespace cv;
using namespace std;
int main() {
    LinkedList lista;
    double scale = 3.0;
    CascadeClassifier faceCascade;
    faceCascade.load("C:\\OpenCV\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"); 
    string path = "Resources/ekisde.mp4";
    VideoCapture cap(path);
  	
    if (!cap.isOpened()) {
        return -1;
    }
    int count = 0;
    for (;;) {

        Mat frame;
        cap >> frame;

        Mat auxFrame;
        cap >> auxFrame;

        Mat grayscale;
        cvtColor(frame, grayscale, COLOR_BGR2GRAY);
        resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));
        
        vector<Rect> faces;
        faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));

        for (Rect area : faces) {
            Scalar drawColor = Scalar(255, 0, 0);
                rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)), Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawColor);
                Rect myROI(area.x, area.y, area.x + area.width-1, area.y+area.height-1);
                Mat rostro = auxFrame(myROI);
                
                string countString = to_string(count);
                
                string str_target = "C:\\Users\\jimimix\\Desktop\\IMAGENES OPENCV TALLER\\img_"+countString+".jpg";
                imwrite(str_target, rostro);
                count = count + 1; //A

                //ingresa a la lista 
                list.insertNode(rostro);
        }
        imshow("Webcam frame", frame);
        if (waitKey(30) >= 0) {
            break;
        }
    }
}
