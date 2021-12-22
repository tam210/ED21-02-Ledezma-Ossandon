#pragma once

#include <vector>

#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

class NodoAVL {

public:
    int altura;
    int key;
    int frec;
    vector<string> frames;
    Mat image;
    Mat cropImg;


    NodoAVL* left;
    NodoAVL* right;

    NodoAVL(int k, int f, vector<string> frms, Mat img, Mat croppedImg) {
        left = nullptr;
        right = nullptr;
        key = k;
        frames = frms;
        frec = f;
        image = img;
        altura = 1;
        cropImg = croppedImg;
    }
};