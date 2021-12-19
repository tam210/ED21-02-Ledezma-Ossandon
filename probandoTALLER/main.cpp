#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>
#include <string>
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"

//TALLER FUNCIONAL OFICIAL TRABAJANDO HASTA EL MOMENTO

#include "FaceDetector.h"
#include "ImageCoding.h"

#include "BinarySearchTreeNode.h"
#include "BinarySearchTree.h"

#include "ArbolFrecuencias.h"

#include "ArbolOrdenado.h"  

#include "AVL.cpp"
#include "NodoAVL.h"


using std::cout;
using std::endl;
using std::string;
using std::vector;
int c =0;

void escribirTxt(String s, String decision) {
    ofstream archivo;
    string info_principal;
    if (decision == "total") {
        archivo.open("./identidades_registros_txt/registro_identidades.txt", ios::out);
        info_principal = "---------- Registro total de identidades ----------";
    }
    else {
        archivo.open("./identidades_registros_txt/registro_identidades_frecuentes.txt", ios::out);
        info_principal = "---------- Registro de identidades frecuentes ----------";

    }
    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    archivo << info_principal;
    archivo << s;
    archivo.close();
}



void cantidad(BinarySearchTreeNode* root, int *cant)
{
    if (root != nullptr)
    {
        (*cant)++;
        cantidad(root->left, cant);
        //cout << root->left << endl;
        cantidad(root->right, cant);
        //cout << root->right << endl;

    }
}

void enOrden(BinarySearchTreeNode* root, int*i ) {
    if (root != nullptr) {
        enOrden(root->left, i);
        //cout << "ID de la imagen: " << root->key << " // Frecuencia: " << root->frec << " // Cantidad Frames: "<< root->frames.size() << endl;
        imwrite("./identidades_totales/identidad_ID_"/* + to_string(*i)   " _ID_"*/ + to_string(root->key) + ".png", root->image);
        (*i)++;
        enOrden(root->right, i);          
    }
}


void identidades(BinarySearchTreeNode* root, int *c, int omision, String *info5IdentidadesTxt, int * i) {
 //6-5 = 1, a partir del 1 imprime
    if (root != nullptr) {
        identidades(root->left, c, omision, info5IdentidadesTxt, i);
        if (omision==0) {
            cout << "> ID de la imagen: " << root->key << " // Frecuencia de aparición: " << root->frec << endl;
            (*info5IdentidadesTxt) = (*info5IdentidadesTxt) + "\n ID: " + to_string(root->key) + ", Frecuencia de aparición: " + to_string(root->frec) + " veces";
            //Mat imgen = ;
            *i = *i + 1;
            imwrite("./identidades_mas_frecuentes/identidad_ID_"+ /*to_string(*i) + "_ID_" + */ to_string(root->key) + ".png", root->image);
            imshow("Rostros mas frecuentes", root->image);
            waitKey(1000);
        }
        else {
            omision--;
        }
        identidades(root->right, c, omision, info5IdentidadesTxt, i);
    }
}


void insertarNodosOrdenadosFrecuencia(BinarySearchTreeNode* &root, ArbolOrdenado &aoo, ArbolAVL &avl) {
    if (root != nullptr) {
        insertarNodosOrdenadosFrecuencia(root->left, aoo, avl);
        //cout << "[Insertando] ID: " << root->key << " // Frecuencia: " << root->frec << endl;
        aoo.insert(aoo.root,root);
        //cout << "INSERTANDO EN ARBOL AVL !!!!!!!!!!!" << endl;
        avl.insertar(root->key, root->frec, root->frames, root->image);
        //cout << "[Insertado] ID: " << avl.root->key << " // Frecuencia: " << avl.root->frec <<" // Frames: " << endl;

        insertarNodosOrdenadosFrecuencia(root->right, aoo, avl);
    }
}



int main()
{
    string stringFrame;
    int contadorFrame = 1;



    int f;
    cout << "Para salir del programa presione ESC o q(uit)." << endl;

    vector<string> imagesStr;
    //TODO: Cargar todos los archivos del directorio automáticamente
    imagesStr.push_back("./datita/image-007.jpeg");   // ID 1 = 4 IMAGENES
    imagesStr.push_back("./datita/image-007_2.jpeg");
    imagesStr.push_back("./datita/image-008.jpeg");
    imagesStr.push_back("./datita/image-008_2.jpeg");

    imagesStr.push_back("./datita/image-024.jpeg");   //ID 2 = 2 IMAGENES
    imagesStr.push_back("./datita/image-025.jpeg");

    imagesStr.push_back("./datita/image-047.jpeg");   //ID 3 = 1 IMAGEN

    imagesStr.push_back("./datita/image-175.jpeg");   //ID 4 = 3 IMAGENES
    imagesStr.push_back("./datita/image-176.jpeg");
    imagesStr.push_back("./datita/image-177.jpeg");

    imagesStr.push_back("./datita/image-041.jpeg");   //ID 5 = 5 IMAGENES
    imagesStr.push_back("./datita/image-042.jpeg");
    imagesStr.push_back("./datita/image-043.jpeg");
    imagesStr.push_back("./datita/image-044.jpeg");
    imagesStr.push_back("./datita/image-045.jpeg");

    imagesStr.push_back("./datita/image-055.jpeg");   //ID 6 = 6 IMAGENES
    imagesStr.push_back("./datita/image-055.jpeg");
    imagesStr.push_back("./datita/image-055.jpeg");
    imagesStr.push_back("./datita/image-055.jpeg");
    imagesStr.push_back("./datita/image-055.jpeg");
    imagesStr.push_back("./datita/image-055.jpeg");

    cout << "imagesStr = { ";
    for (string n : imagesStr) {
        cout << n << ", ";
    }
    cout << "};" << endl;

    // Leemos todas las caras de los archivos de imágenes y las insertamos en el árbol

    ArbolFrecuencias af;
    ArbolOrdenado aord;

    ArbolAVL arbolAVL;

    BinarySearchTree abb;
    FaceDetector fdetector;
    ImageCoding icoding;
    Mat image;
    Scalar color(0, 0, 255);

    //cout << "COLOR";
    for (string im : imagesStr) {
        cout << "Leyendo imagen" << endl;
        cout << im << endl;
        image = imread(im, IMREAD_COLOR);
        auto facesMarkers = fdetector.detectFaceRectangles(image);

        // Codifico las caras detectadas
        icoding.setImage(image);

        auto faceCodingGray = icoding.codeGray(facesMarkers, true, Size(25, 25));
        // Muestro las caras codificadas
        Mat colorImage;
        Mat newSize;
        // Muestro las caras detectadas en la imagen original
        int widthImageInGrayColor = 40;
        int posX = 10;

        //resize(colorImage, newSize, Size(widthImageInGrayColor, widthImageInGrayColor), INTER_LINEAR);
        //imshow("aa", image);
        for (const auto& cf : faceCodingGray) {
            // Inserto la imagen en el arbol y obtengo el identificador
            //abb.insert(cf);

            stringFrame = "Frame_" + to_string(contadorFrame);
            cout << " Frame actualmente leyendo: " << stringFrame << endl;
            af.insert(cf, &stringFrame);
            //aord.insert(asd);



            // Muestro la imagen codificada en la imagen original
            cvtColor(cf, colorImage, COLOR_GRAY2BGR);
            resize(colorImage, newSize, Size(widthImageInGrayColor, widthImageInGrayColor), INTER_LINEAR);
            newSize.copyTo(image(cv::Rect(posX, 10, newSize.cols, newSize.rows)));
            posX += widthImageInGrayColor + 10;

            contadorFrame++;
        }


        // Para ver caras detectadas muestro las caras encontradas en la imaggen original
        for (const auto& fm : facesMarkers) {
            rectangle(image, fm, color, 4);
        }
        // Mostrar la imagen con las marcas (rectángulos) indicando la posición de la cara
        imshow("Detected Face", image);
        waitKey(0);
    }
    insertarNodosOrdenadosFrecuencia(af.root, aord, arbolAVL); //inserta los nodos del arbol del profe
    int indice_mostrar_arbol = 0;

    enOrden(aord.root, &indice_mostrar_arbol); //despliega los datos ordenaditos de menor a mayor

    int canti = 0; //se guarda la cantidad de elementos que tiene el arbol

    cout << "\n-----------------------------------------------------------------------------\n" << endl;
    cantidad(aord.root, &canti);
    cout << "\nCantidad de identidades procesadas: " << canti << endl;
    int indice_ = 0;




    int omision = canti - 5; //los nodos que no se imprimiran
    cout << " \n---------- Información de las 5 identidades más frecuentes del metraje ---------- " << endl;

    cout << "Las 5 identidades que más aparecieron en el metraje corresponden a: " << endl;
    String info5IdentidadesTXT;

    identidades(aord.root, &canti, omision, &info5IdentidadesTXT, &indice_); //Imprime las 5 identidades con mayor frecuencia
    escribirTxt(info5IdentidadesTXT, "5identidades");


    cout << " \n---------- Información de las apariciones de cada identidad ----------" << endl;

    String infoTxt = " ";
    arbolAVL.mostrarArbolAVL(infoTxt);
    cout << infoTxt;

    escribirTxt(infoTxt, "total");
    //  system("pause");


    
   









    // Esperar hasta presionar la tecla ESC
    while (true) {
        int pressKey = waitKey(100);
        if (pressKey == 27 || pressKey == 113) break;
    }

    destroyAllWindows();

    return 0;
}



