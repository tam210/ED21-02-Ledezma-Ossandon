#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp> //para cascadas
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include "Node.hpp"
#include "Node.cpp"
#include "LinkedList.cpp"
#include <stdlib.h>

using namespace cv;
using namespace std;
int main() {
    LinkedList lista;
    double scale = 3.0;
    CascadeClassifier faceCascade;
    faceCascade.load("C:\\OpenCV\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"); 
    string path = "Resources/ekisde.mp4";
    VideoCapture cap(path);
  	
    if (!cap.isOpened()) {
        return -1;
    }
    int count = 0;
    for (;;) {

        Mat frame;
        cap >> frame;

        Mat auxFrame;
        cap >> auxFrame;

        Mat grayscale;
        cvtColor(frame, grayscale, COLOR_BGR2GRAY);
        resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));
        
        vector<Rect> faces;
        faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));

        for (Rect area : faces) {
            Scalar drawColor = Scalar(255, 0, 0);
                rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)), Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawColor);
                Rect myROI(area.x, area.y, area.x + area.width-1, area.y+area.height-1);
                Mat rostro = auxFrame(myROI);
                
                string countString = to_string(count);
                
                string str_target = "C:\\Users\\jimimix\\Desktop\\IMAGENES OPENCV TALLER\\img_"+countString+".jpg";
                imwrite(str_target, rostro);
                count = count + 1; //A

                //ingresa a la lista 
                list.insertNode(rostro);
        }
        imshow("Webcam frame", frame);
        if (waitKey(30) >= 0) {
            break;
        }
    }
}


#include <opencv2/opencv.hpp>
using namespace std;


class Node
{
public:
	Node();
	Node(Mat);
	~Node();
	Mat data;
	Node* next;


};



#include <opencv2/opencv.hpp>
class Node { //podria ser un struct
public:
    Mat data;
    Node* next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};



#include <opencv2/opencv.hpp>
#include "Node.cpp"
using namespace std;


class Linkedlist {

    struct Node { //podria ser un struct
    public:
        Mat data;
        Node* next;

        Node()
        {
            data = NULL;
            next = nullptr;
        }

        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node* head;

public:
    Linkedlist() {
        head = nullptr;
    }


    void insertNode(Mat);

    void printList();


    void deleteNode(Mat);
};



#include "LinkedList.hpp"
#include <iostream>

using namespace std;
//Funcion para eliminar el nodo en la posicion dada
void Linkedlist::deleteNode(int nodeOffset)
{
    Node* temp1 = head, * temp2 = nullptr;
    int ListLen = 0;

    if (head == nullptr) {
        cout << "Lista vacia" << endl;
        return;
    }

    // Encuentra el tamaño de la linked list
    while (temp1 != nullptr) {
        temp1 = temp1->next;
        ListLen++;
    }

    //Ve si la posicion debe ser eliminada en menos del tamaño
    // //de la linked list
    if (ListLen < nodeOffset) {
        cout << "Indice fuera de rango"
            << endl;
        return;
    }

    // Declare temp1
    temp1 = head;

    // Borrando head
    if (nodeOffset == 1) {

        // Update head
        head = head->next;
        delete temp1;
        return;
    }

    // Viaja por la lista buscando el nodo a eliminar
    while (nodeOffset-- > 1) {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Cambia puntero
    temp2->next = temp1->next;

    // Delete the node
    delete temp1;
}

// Insertar nodo
void Linkedlist::insertNode(int data)
{
    // Crea nodo
    Node* newNode = new Node(data);

    // Asigna head
    if (head == nullptr) {
        head = newNode;
        return;
    }

    // Recorre hasta el fin de la lista
    Node* temp = head;
    while (temp->next != nullptr) {

        // Actualiza temp
        temp = temp->next;
    }

    // Insert at the last.
    temp->next = newNode;
}

//Funcion que imprime los nodos de la linked list
void Linkedlist::printList()
{
    Node* temp = head;

    // Check for empty list.
    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }

 
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}














