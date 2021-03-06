
#include "opencv2/core.hpp"

#include "BinarySearchTree.h"
#include "BinarySearchTreeNode.h"

#include <iostream>

using namespace std;
using namespace cv;

/**
 * Inserta la imagen en el arbol le asigna un identificador.
 *
 * @param image (Mat) imagen de tama?o 25x25 en gris
 */
void BinarySearchTree::insert(Mat image) {
    root = insert(root, image);
    
    //root es el nodo que devuelve el insert(root actual, imagen)
}

double BinarySearchTree::euclideanDistance(Mat img1, Mat img2) {
    return norm(img1, img2, NORM_L2);
}
/*
BinarySearchTreeNode* BinarySearchTree::getRoot() {
    return root;
}

void BinarySearchTree::enOrden(BinarySearchTreeNode* root) {

    if (root != nullptr) {
        enOrden(root->left);
        cout << root->key << endl;
        enOrden(root->right);
    }
}
*/
BinarySearchTreeNode* BinarySearchTree::insert(BinarySearchTreeNode* node, Mat image) {
    // TOLERANCIA para considerar una imagen igual
    //Si el ?rbol no tiene hijos
    if (node == nullptr) {
        node = new BinarySearchTreeNode();

        //node->frec = node->frec + 1; 

        node->key = ++counter;
        node->image = image;
        node->left = nullptr;
        node->right = nullptr;

        cout << "ID: " << node->key << endl;
        return node;
    }
    //Si es similar (menor a la distancia ideal de similitud)
    //y 
    else if (SIMILAR < euclideanDistance(node->image, image)
        && DIFFERENT > euclideanDistance(node->image, image)) {
        cout << "insertando en nodo izquierdo" << endl;
        node->left = insert(node->left, image);
    }
    else if (DIFFERENT <= euclideanDistance(node->image, image)) {
        cout << "insertando en nodo derecho" << endl;
        node->right = insert(node->right, image);
    }
    else { //La cara es igual (menor a la distancia exigida para similar)
        cout << "Distancia euclidea (Igual): " << euclideanDistance(node->image, image) << endl;
        node->image = image; //Cambio la imagen por la nueva
        cout << "Cara igual" << endl;

    }
    cout << "Distancia euclidea: " << euclideanDistance(node->image, image) << endl;
    return node;
}
