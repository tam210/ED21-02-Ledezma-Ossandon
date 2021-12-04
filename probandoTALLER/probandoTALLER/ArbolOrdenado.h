#pragma once

#include "opencv2/core.hpp"

using namespace cv;

class ArbolOrdenado{


public:
    struct BinarySearchTreeNode* root;


    void insert(BinarySearchTreeNode* &node, BinarySearchTreeNode* nodoIn);

public:
    ArbolOrdenado() {
        root = nullptr;
    }

    //void insert(BinarySearchTreeNode* nodoIn);
    
    BinarySearchTreeNode* getRoot(void);

    void enOrden(BinarySearchTreeNode* root);
    int buscarmayor(ArbolOrdenado& arbol);


    //TODO: Falta hacer el destructor para eliminar cualquier el arbol complementamente
};


