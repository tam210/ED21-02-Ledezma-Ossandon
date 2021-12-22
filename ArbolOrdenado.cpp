#include "ArbolOrdenado.h"
#include "opencv2/core.hpp"

#include "BinarySearchTreeNode.h"
#include <iostream>
using namespace std;
using namespace cv;

/**
 * Inserta la imagen en el arbol le asigna un identificador.
 *
 * @param image (Mat) imagen de tamaño 25x25 en gris
 */

BinarySearchTreeNode* ArbolOrdenado::getRoot(void) {
    return root;
}

void ArbolOrdenado::enOrden(BinarySearchTreeNode* root) {

    if (root != nullptr) {
        enOrden(root->left);
        cout << root->key << endl;
        enOrden(root->right);
    }
}

int ArbolOrdenado::buscarmayor(ArbolOrdenado &arbol){
     int mayorID;
     while (arbol.root->right != NULL) {
         arbol.root = arbol.root->right;
     }
     mayorID=arbol.root->key;
     return mayorID;
}

void ArbolOrdenado::insert(BinarySearchTreeNode* &node, BinarySearchTreeNode* nodoIn) {
    //Si el árbol no tiene hijos

    if (node == nullptr) {
        node = new BinarySearchTreeNode();

        node->key = nodoIn->key;
        node->frec = nodoIn->frec;
        node->image = nodoIn->image;
        node->croppedImg = nodoIn->croppedImg;

        node->frames = nodoIn->frames;

        node->left = nullptr;
        node->right = nullptr;

    }
    else if (nodoIn->frec < node->frec){
        insert(node->left, nodoIn);
    }
    else if (nodoIn->frec > node->frec) {
       insert(node->right, nodoIn);


    }
    
}
