#include <iostream>
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

using std::cout;
using std::endl;
using std::string;
using std::vector;
int c =0;

void cantidad(BinarySearchTreeNode* root, int *cant)
{
    if (root != nullptr)
    {
        (*cant)++;
        cantidad(root->left, cant);
        cout << root->left << endl;
        cantidad(root->right, cant);
        cout << root->right << endl;

    }
}

void enOrden(BinarySearchTreeNode* root) {
    if (root != nullptr) {
        enOrden(root->left);
        cout << "ID de la imagen: " << root->key << " // Frecuencia: " << root->frec << endl;
        enOrden(root->right);          
    }
}


void identidades(BinarySearchTreeNode* root, int *c, int omision) {
 //6-5 = 1, a partir del 1 imprime
    if (root != nullptr) {
        identidades(root->left, c, omision);
        if (omision==0) {
            cout << "ID de la imagen: " << root->key << " // Frecuencia: " << root->frec << endl;
        }
        else {
            omision--;
        }
        identidades(root->right, c, omision);
    }
}


void insertarNodosOrdenadosFrecuencia(BinarySearchTreeNode* &root, ArbolOrdenado &aoo) {
    if (root != nullptr) {
        insertarNodosOrdenadosFrecuencia(root->left, aoo);
        cout << "[Insertando] ID: " << root->key << " // Frecuencia: " << root->frec << endl;
        aoo.insert(aoo.root,root);
        cout << "[Insertado] ID: " << aoo.root->key << " // Frecuencia: " << aoo.root->frec << endl;

        insertarNodosOrdenadosFrecuencia(root->right, aoo);
    }
}



int main()
{
    int f;
    cout << "Para salir del programa presione ESC o q(uit)." << endl;

    vector<string> imagesStr;
    //TODO: Cargar todos los archivos del directorio automáticamente
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-007.jpeg");   // ID 1 = 4 IMAGENES
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-007_2.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-008.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-008_2.jpeg"); 

    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-024.jpeg");   //ID 2 = 2 IMAGENES
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-025.jpeg");   

    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-047.jpeg");   //ID 3 = 1 IMAGEN

    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-175.jpeg");   //ID 4 = 3 IMAGENES
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-176.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-177.jpeg");

    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-041.jpeg");   //ID 5 = 5 IMAGENES
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-042.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-043.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-044.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-045.jpeg");

    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-055.jpeg");   //ID 6 = 6 IMAGENES
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-055.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-055.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-055.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-055.jpeg");
    imagesStr.push_back("C:/Users/jimimix/Desktop/datita/image-055.jpeg");

    cout << "imagesStr = { ";
    for (string n : imagesStr) {
        cout << n << ", ";
    }
    cout << "};" << endl;

    // Leemos todas las caras de los archivos de imágenes y las insertamos en el árbol

    ArbolFrecuencias af;
    ArbolOrdenado aord;

    BinarySearchTree abb;
    FaceDetector fdetector;
    ImageCoding icoding;
    Mat image;
    Scalar color(0, 0, 255);

    cout << "COLOR";
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

        for (const auto& cf : faceCodingGray) {
            // Inserto la imagen en el arbol y obtengo el identificador
            //abb.insert(cf);

            af.insert(cf);
            //aord.insert(asd);

            // Muestro la imagen codificada en la imagen original
            cvtColor(cf, colorImage, COLOR_GRAY2BGR);
            resize(colorImage, newSize, Size(widthImageInGrayColor, widthImageInGrayColor), INTER_LINEAR);
            newSize.copyTo(image(cv::Rect(posX, 10, newSize.cols, newSize.rows)));
            posX += widthImageInGrayColor + 10;
        }

        
        // Para ver caras detectadas
        //Muestro las caras encontradas en la imaggen original
        for (const auto& fm : facesMarkers) {
            rectangle(image, fm, color, 4);
        }
        // Mostrar la imagen con las marcas (rectángulos) indicando la posición de la cara
        imshow("Detected Face", image);
        waitKey(0);
    }        
    //enOrden(af.root,c);
    insertarNodosOrdenadosFrecuencia(af.root, aord); //inserta los nodos del arbol del profe

   // cout << "XD" << aord.root->right->key<< endl;
    enOrden(aord.root); //despliega los datos ordenaditos de menor a mayor

    //cout << "MAYOR" << aord.buscarmayor(aord);

    //verArbol2(aord.root, 0);

    int canti = 0; //se guarda la cantidad de elementos que tiene el arbol
    cantidad(aord.root, &canti);
    cout << "Cantidad de imagenes procesadas: "<<canti << endl;

    int omision = canti - 5; //los nodos que no se imprimiran
    identidades(aord.root, &canti, omision); //Imprime las 5 identidades con mayor frecuencia

     
    // Esperar hasta presionar la tecla ESC
    while (true) {
        int pressKey = waitKey(100);
        if (pressKey == 27 || pressKey == 113) break;
    }

    destroyAllWindows();

    return 0;
}





























/*
#include <opencv2/opencv.hpp>
#include <stdio.h>
using namespace cv;
int main(int argc, char** argv) {
	Mat image;
	image = imread("C:/Users/jimimix/Desktop/electro.png");
	if (!image.data) {
		printf("No image data ");
		return -1;
	}
	namedWindow("Display image", WINDOW_AUTOSIZE);
	imshow("Display image", image);
	waitKey(0);
	return 0;
}
*/