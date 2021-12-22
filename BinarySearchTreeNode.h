#pragma once
#include <vector>
/**
 * Clase que almacena la imagen y el identificador de la cara
 */
#include "opencv2/opencv.hpp"
using namespace std;

class BinarySearchTreeNode {
public:
    int key;
    int frec;
    vector<string> frames;
    Mat image; // Imagen de tamaño 25x25
    Mat croppedImg;
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;

};
