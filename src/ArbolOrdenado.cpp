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
/*
void ArbolOrdenado::insert(BinarySearchTreeNode* nodoIn) {
    root = insert(root, nodoIn);
}
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
    // TOLERANCIA para considerar una imagen igual
    //Si el árbol no tiene hijos

    if (node == nullptr) {
        node = new BinarySearchTreeNode();

        //node->frec = node->frec + 1; 

        node->key = nodoIn->key;
        node->frec = nodoIn->frec;
        node->image = nodoIn->image;
        node->left = nullptr;
        node->right = nullptr;

        cout << "asdasdasdasdasdas" << "id: " << node->key << " FREC: " << node->frec << endl;

    }
    else if (nodoIn->frec < node->frec){
        cout << "insertando: SITUACION FREC < NODO" << endl;
        insert(node->left, nodoIn);
    }
    else if (nodoIn->frec > node->frec) {
        cout << "insertando: SITUACION FREC > NODO" << endl;
       insert(node->right, nodoIn);


    }
    
}
