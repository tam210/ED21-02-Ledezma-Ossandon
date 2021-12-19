#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "NodoAVL.h"

#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"



using namespace std;
using namespace cv;

class ArbolAVL {
public:
    NodoAVL* root;

public:
    ArbolAVL() {
       root = nullptr;
    }
    void clearAll() {
        root = nullptr;
    }

    /***************************************************************************/
    /****************************** INSERCION **********************************/
    /***************************************************************************/
    //public
    void insertar(int k, int f, vector<string> frms, Mat img) {
        root = insertarAVL(root, k, f, frms, img);
    }
    //private
    NodoAVL* insertarAVL(NodoAVL* nodoActual, int k, int f, vector<string> frms, Mat img) {
        if (nodoActual == nullptr) {
            //cout << "Nulo el nodo" << endl;
            return (new NodoAVL(k, f, frms, img));
        }

        if (f < nodoActual->frec) {
            nodoActual->left = insertarAVL(nodoActual->left, k, f, frms, img);
        }
        else if (f > nodoActual->frec) {
            nodoActual->right = insertarAVL(nodoActual->right, k, f, frms, img);
        }
        else {// Si la clave esta duplicada retorna el mismo nodo encontrado
            return nodoActual;
        }

        //Actualizacion de la altura
        nodoActual->altura = 1 +
            max(getAltura(nodoActual->left), getAltura(nodoActual->right));

        // Se obtiene el factor de equilibrio
        int fe = getFactorEquilibrio(nodoActual);

        // Caso Rotacion Simple a la derecha
        /*
                20 (2)
              /
            12 (1)
          /
        5 (0)
        */
        if (fe > 1 && f < nodoActual->left->frec) {
            return rightRotate(nodoActual);
        }

        // Caso Rotacion Simple a la izquierda
        /*
        5 (-2)
          \
           12 (-1)
              \
               20 (0)
        */
        if (fe < -1 && f > nodoActual->right->frec) {
            return leftRotate(nodoActual);
        }

        // Caso Rotacion Doble Izquierda Derecha
        /*
               12 (2)
              /
            5 (-1)
              \
               8 (0)
        */
        if (fe > 1 && f > nodoActual->left->frec) {
            nodoActual->left = leftRotate(nodoActual->left);
            return rightRotate(nodoActual);
        }

        // Caso Rotacion Doble Derecha Izquierda
        /*
        5 (-2)
          \
           12 (1)
          /
         8 (0)
        */
        if (fe < -1 && f < nodoActual->right->frec) {
            nodoActual->right = rightRotate(nodoActual->right);
            return leftRotate(nodoActual);
        }

        return nodoActual;
    }

    /***************************************************************************/
    /******************************* BUSQUEDA **********************************/
    /***************************************************************************/

    //---búsqueda de un elemento en el AVL
    //public
    void buscar(int elemento) {
        if (BuscaEnAVL(root, elemento)) {
            cout << "Existe" << endl;
        }
        else {
            cout << "No Existe" << endl;
        }
    }

    //Búsqueda recursiva en un AVL
    //private
    bool BuscaEnAVL(NodoAVL* nodoActual, int elemento) {
        if (nodoActual == nullptr) {
            return false;
        }
        else if (elemento == nodoActual->frec) {
            return true;
        }
        else if (elemento < nodoActual->frec) {
            return BuscaEnAVL(nodoActual->left, elemento);
        }
        else {
            return BuscaEnAVL(nodoActual->right, elemento);
        }
    }

    /***************************************************************************/
    /**************************** ELIMINACION **********************************/
    /***************************************************************************/
    //public
    void eliminar(int key) {
        root = eliminarAVL(root, key);
    }
    //private
    NodoAVL* eliminarAVL(NodoAVL* nodoActual, int key) {
        if (nodoActual == nullptr)
            return nodoActual;

        if (key < nodoActual->frec) {
            nodoActual->left = eliminarAVL(nodoActual->left, key);
        }
        else if (key > nodoActual->frec) {
            nodoActual->right = eliminarAVL(nodoActual->right, key);
        }
        else {
            //El nodo es igual a la clave, se elimina
            //Nodo con un unico hijo o es hoja
            if ((nodoActual->left == nullptr) || (nodoActual->right == nullptr)) {
                NodoAVL* temp = nullptr;
                if (temp == nodoActual->left) {
                    temp = nodoActual->right;
                }
                else {
                    temp = nodoActual->left;
                }

                // Caso que no tiene hijos
                if (temp == nullptr) {
                    nodoActual = nullptr;//Se elimina dejandolo en null
                }
                else {
                    //Caso con un hijo
                    nodoActual = temp;//Elimina el valor actual reemplazandolo por su hijo
                }
            }
            else {
                //Nodo con dos hijos, se busca el predecesor
                NodoAVL* temp = getNodoConValorMaximo(nodoActual->left);

                //Se copia dato del predecesor
                nodoActual->frec = temp->frec;

                //Se elimina el predecesor
                nodoActual->left = eliminarAVL(nodoActual->left, temp->frec);
            }
        }

        //Si solo tiene un nodo
        if (nodoActual == nullptr)
            return nodoActual;

        //Actualiza altura
        nodoActual->altura = max(getAltura(nodoActual->left), getAltura(nodoActual->right)) + 1;

        //Calcula factor de equilibrio (FE)
        int fe = getFactorEquilibrio(nodoActual);

        // Se realizan las rotaciones pertinentes dado el FE
        // Caso Rotacion Simple Derecha
        /*
                20 (2)
              /
            12 (1)
          /
        5 (0)
        */
        if (fe > 1 && getFactorEquilibrio(nodoActual->left) >= 0) {
            return rightRotate(nodoActual);
        }

        // Caso Rotacion Simple Izquierda
        /*
        5 (-2)
          \
           12 (-1)
              \
               20 (0)
        */
        if (fe < -1 && getFactorEquilibrio(nodoActual->right) <= 0) {
            return leftRotate(nodoActual);
        }

        // Caso Rotacion Doble Izquierda-Derecha
        /*
               12 (2)
              /
            5 (-1)
              \
               8 (0)
        */
        if (fe > 1 && getFactorEquilibrio(nodoActual->left) < 0) {
            nodoActual->left = leftRotate(nodoActual->left);
            return rightRotate(nodoActual);
        }

        // Caso Rotacion Doble Derecha-Izquierda
        /*
        5 (-2)
          \
           12 (1)
          /
         8 (0)
        */
        if (fe < -1 && getFactorEquilibrio(nodoActual->right) > 0) {
            nodoActual->right = rightRotate(nodoActual->right);
            return leftRotate(nodoActual);
        }

        return nodoActual;
    }

    /***************************************************************************/
    /****************************** ROTACIONES *********************************/
    /***************************************************************************/
    // Rotar hacia la derecha
    /*
            20 (2)
          /
        12 (1)
      /
    5 (0)
    */
    //private
    NodoAVL* rightRotate(NodoAVL* nodoActual) {
        NodoAVL* nuevaRaiz = nodoActual->left;
        NodoAVL* temp = nuevaRaiz->right;

        // Se realiza la rotacion
        nuevaRaiz->right = nodoActual;
        nodoActual->left = temp;

        // Actualiza alturas
        nodoActual->altura = max(getAltura(nodoActual->left), getAltura(nodoActual->right)) + 1;
        nuevaRaiz->altura = max(getAltura(nuevaRaiz->left), getAltura(nuevaRaiz->right)) + 1;

        return nuevaRaiz;
    }

    // Rotar hacia la izquierda
    //private
    NodoAVL* leftRotate(NodoAVL* nodoActual) {
        NodoAVL* nuevaRaiz = nodoActual->right;
        NodoAVL* temp = nuevaRaiz->left;

        // Se realiza la rotacion
        nuevaRaiz->left = nodoActual;
        nodoActual->right = temp;

        // Actualiza alturas
        nodoActual->altura = max(getAltura(nodoActual->left), getAltura(nodoActual->right)) + 1;
        nuevaRaiz->altura = max(getAltura(nuevaRaiz->left), getAltura(nuevaRaiz->right)) + 1;

        return nuevaRaiz;
    }

    /***************************************************************************/
    /******************************** MOSTRAR **********************************/
    /***************************************************************************/
public:
    void mostrarArbolAVL(string &r) {
        cout << "Arbol AVL" << endl;
        showTree(root, 0, &r);
    }
    //private
    void showTree(NodoAVL* nodo, int depth, string *r) {

        if (nodo->right != nullptr) {
            showTree(nodo->right, depth + 1, r);
            //cout << "emm id: " << nodo->key << endl;
        }
        for (int i = 0; i < depth; i++) {
            cout << ("    ") << endl;
        }
        cout << "> ID: " << nodo->key << endl;
        cout << "> Frecuencia: " << nodo->frec << endl;
        cout << "> Frames aparecidos: " << nodo->frec << endl;


        (*r) = (*r)+ "\n> ID: " + to_string(nodo->key);
        (*r) = (*r) + ", Frecuencia: " + to_string(nodo->frec);
        (*r) = (*r) + ", Frames aparecidos: ";


        //*i = *i + 1;


        for (vector<string>::iterator t = nodo->frames.begin(); t != nodo->frames.end(); ++t) {
            cout <<"> "<< * t << endl;
            (*r) = (*r) + *t+", ";
        }     


//        archivo << r;

        if (nodo->left != nullptr) {
            showTree(nodo->left, depth + 1, r);
            //cout << "emm id: " << nodo->key << endl;


        }
    }

    /***************************************************************************/
    /****************************** AUXILIARES *********************************/
    /***************************************************************************/

    //Obtiene el peso de un arbol dado
    //private
    int getAltura(NodoAVL* nodoActual) {
        if (nodoActual == nullptr) {
            return 0;
        }

        //Notar que no es necesario recorrer el arbol para conocer la altura del nodo
        //debido a que en las rotaciones se incluye la actualizacion de las alturas respectivas
        return nodoActual->altura;
    }

    // Devuelve el mayor entre dos numeros
    //private
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // Obtiene el factor de equilibrio de un nodo
    //private
    int getFactorEquilibrio(NodoAVL* nodoActual) {
        if (nodoActual == nullptr) {
            return 0;
        }

        return getAltura(nodoActual->left) - getAltura(nodoActual->right);
    }

    //private
    NodoAVL* getNodoConValorMaximo(NodoAVL* node) {
        NodoAVL* current = node;

        while (current->right != nullptr) {
            current = current->right;
        }

        return current;
    }

};