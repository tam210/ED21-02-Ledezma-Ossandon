#pragma once
/**
 * Clase que almacena la imagen y el identificador de la cara
 */
#include "opencv2/opencv.hpp"

class BinarySearchTreeNode {
public:
    int key;
    int frec;
    Mat image; // Imagen de tamaño 25x25
    BinarySearchTreeNode* left;
    BinarySearchTreeNode* right;
};
