#pragma once

#include "opencv2/core.hpp"
#include <vector>

using namespace cv;

class ArbolFrecuencias {

private:
    const int DIFFERENT = 1700;
    const int SIMILAR = 1300;
    /**
     * Contador para asignar identificadores a las caras
     */
    int counter;
public:
    struct BinarySearchTreeNode* root;
private:
    BinarySearchTreeNode* insert(BinarySearchTreeNode* node, Mat, String * frameIn);
    double euclideanDistance(Mat, Mat);



public:
    ArbolFrecuencias() {
        counter = 0;
        root = nullptr;
    }

    void insert(Mat, String*);
    
    BinarySearchTreeNode* getRoot(void);

    void enOrden(BinarySearchTreeNode* root);
    


    //TODO: Falta hacer el destructor para eliminar cualquier el arbol complementamente
};


