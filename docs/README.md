![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Tamara Ossandón (Encargada de bitácora)
* Sebastian Ledezma (Coordinador)

## Resumen

> En las graduales instancias de aprendizaje que se han dispuesto, tanto de manera autónoma o guiada, como primera instancia se realizó una retroalimentación de la materia respecto a la sintaxis del lenguaje de programación C y C++ y se investigó acerca del funcionamiento de las librerías de OpenCV para relacionar algunos algoritmos con los requerimientos de la primera historia de usuario a implementar. En segunda instancia, se realizó una capacitación necesaria sobre GitHub para poder tener control respecto a las versiones desarrolladas del programa para establecer una mejor organización y planificación del proyecto a nivel general, además de aprender lo básico en cuanto a la creación de  archivos y carpetas, y cómo interactuar con la plataforma. Posteriormente, se instaló una IDE de desarrollo (Visual Studio Code) y OpenCV, en donde se empezó a probar en la IDE distintos algoritmos que estuvieran relacionados a la detección de rostros en archivos multimedia, concluyendo así en el desarrollo del código que permite hacer seguimiento a cada identidad identificada en el video, señalándola con un marco de color rojo.

## 1. Introducción

El reconocimiento facial es una tarea que, si bien, parece difícil, hay algunos procesos ya continuados pre-construidos anteriormente para construir grandes esqueletos de procesamiento de información que pueden satisfacer grandes problemas de la sociedad, sobretodo últimamente en lo que respecta al reconocimiento e identificación facial, tema importante de seguridad y seguimiento que aporta tanto a las áreas de economía, seguridad, compras diarias, etc. Es por esto, que a través de OpenCV, se quiere construir un programa por el cual tenga como objetivo principal el reconocimiento facial para poder construir un sistema de vigilancia basado en este reconocimiento facial. Para ello, se cuenta con un dispositivo de adquisición, en el cual se deben detectar las caras de diferentes personas que aparecen en la grabación, haciendo un resumen de las iddentidades presentes y las estadísticas relacionadas a la duración de la exposición en el metraje.


### 1.1 Descripción del problema 

El presente proyecto tiene como objetivo implementar un sistema desarrollado en el lenguaje de programación C++ y librerías de OpenCV, que conste en la detección de rostros faciales de un archivo multimedia que presenta distintas identidades, es por tanto, por lo que el se tiene que diseñar y desarrollar una inteligencia artificial la cual detecte cada rostro presente en el video señalándolo con un cuadro de color rojo alrededor de él. Además, se debe implementar diferentes funciones que tendrán un uso en el ámbito de la vigilancia, tales como; un listado de las personas (identidades) detectadas en un intervalo de tiempo definido en el video, y un listado de todas las identidades que se vieron expuestas en la grabación. Ambas, mostrando el número de cada identidad correspondiente y su duración efectiva de exposición. 

### 1.2 Objetivos 

**Objetivo General**

Construir un sistema de vigilancia a través del reconocimiento de rostros, en donde, mediante una cámara o un video, se detecten los rostros de las diferentes personas que están presentes en la grabación, obteniendo diferentes datos y estadísticas relacionadas a las identidades identificadas.

**Objetivos específicos**

1.	Investigar el funcionamiento de las librerías de OpenCV para comprender el funcionamiento de los algoritmos relacionados al reconocimiento facial.
2.	Implementar las librerías de OpenCV utilizando el lenguaje de programación C++ para realizar el seguimiento e identificación facial.
3.	Señalar un marco de color rojo alrededor de cada rostro identificado para visualizar de mejor manera la identidad.
4.	Definir un código de identidad a cada rostro identificado para poder diferenciarlas entre las demás.
5.	Establecer intervalos de tiempo en la secuencia de video para obtener las diferentes identidades que se vieron identificadas específicamente en ese lapso.
6.	Obtener las cinco identidades que más tiempo fueron detectadas en la grabación.
7.	Crear un listado de todas las identidades detectadas indicando el tiempo total de las veces que aparecieron en la grabación.
8.	Comprobar el correcto funcionamiento del programa a través del uso de distintos archivos multimedia.


### 1.3 Solución propuesta

Esbozo de la solución propuesta, se espera que esta vaya evolucionando a medida que se avanza en el proyecto.

## 2. Materiales y métodos

Explicar brevemente como se espera desarrollar el trabajo de implementación.

### 2.1 Instalación

El entorno de desarrollo empleado para desarrollar el programa es Visual Studio Community (2019) y las librerías utilizadas son de OpenCV. Las librerías ofrecen una sólida base que están orientadas a la identificación de rostros e incluso la señalización de estas identidades ya sea en imágenes, videos multimedia o en webcam con Haar Cascades, CascadeClassifier y para su visualización el método "rectangle".

### 2.2 Diseño 

Respecto al diseño del programa, se trata de tratar a cada rostro como una identidad, por lo que, través de las librerías de OpenCV, se leerán las identidades del video y se almacenarán en una lista general de rostros, en las cuales cada identidad tendrá su imagen (captura del rostro) y tiempo de duración en el video. Es con estas características que podremos dar inicio a poder recorrer esta lista para realizar distintas operaciones, por ejemplo capturar el rango de aparición de cada identidad, o la cantidad de apariciones en un tiempo determinado. De ser necesario, se crearán otras listas dinámicas para almacenar temporalmente algunos registros de identidades para usarlos en el problema solicitado.



### 2.3 Implementación

En la implementación, se utilizarán listas enlazadas para tratar con las identidades que serán guardadas en estas. Cabe señalar, que las clases utilizadas será la LinkedList, la clase Node y el main. En la clase Node se guardará la identidad del rostro (captura del rostro) de tipo Mat y su duración acumulada en el video de tipo int, indicando los segundos de aparición.


#### Detector de caras

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:
int main() {

 double scale = 3.0;
    CascadeClassifier faceCascade;
    faceCascade.load("C:\\OpenCV\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml");
    
    string path = "Resources/ekisde.mp4";
    VideoCapture cap(path);

    if (!cap.isOpened()) {
        return -1;
    }
   
for (;;) {

        Mat frame;
        cap >> frame;
        Mat grayscale;
        cvtColor(frame, grayscale, COLOR_BGR2GRAY);
        resize(grayscale, grayscale, Size(grayscale.size().width / scale, grayscale.size().height / scale));
        
        vector<Rect> faces;
        faceCascade.detectMultiScale(grayscale, faces, 1.1, 3, 0, Size(30, 30));

        for (Rect area : faces) {
            Scalar drawColor = Scalar(255, 0, 0);
                rectangle(frame, Point(cvRound(area.x * scale), cvRound(area.y * scale)), Point(cvRound((area.x + area.width - 1) * scale), cvRound((area.y + area.height - 1) * scale)), drawColor);
                
        }
        imshow("Webcam frame", frame);
        if (waitKey(30) >= 0) {
            break;
        }


    }
}

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos


## Anexo A: Instalación librerías OpenCV


Para la instalación de OpenCV, ingresar al link de la página oficial:
https://sourceforge.net/projects/opencvlibrary/files/opencv-win/

![ED21](images/PASO2.png)

Al ingresar, hacer click en donde dice "page on Sourceforge" para ir al link de descarga.

![ED21](images/PASO3.png)

Al cargar la página, hacer click en "Download Latest Version" y se pondrá automáticamente a descargar la última versión de OpenCV.

![ED21](images/PASO4.png)

Una vez descargado, hay que crear una carpeta en disco C: llamada "OpenCV". Cuando haya descargado el archivo, se abre y se instala en ese directorio (C:\)

![ED21](images/PASO5.png)

Ya instalado en la carpeta, hay que ir a modificar las variables de entorno del sistema. Para eso solo buscamos en el buscador "Edit the system environment variables" o en su defecto, "Editar las variables de entorno del sistema"

![ED21](images/PASO6.png)

Una vez abierto, hacer click en "Variables de entorno" en la parte inferior y aparecerá un cuadro, en donde hay que darle a "Nueva" para asignar una nueva variable de entorno en donde ingresaremos el directorio donde se encuentra la carpeta de OpenCV, en el directorio de bin, tal como se muestra en la captura. Una vez realizado esto, aceptamos y cerramos.

![ED21](images/PASO7.png)






## Anexo B: Instalación de IDE y configuración librerías OpenCV


Para instalar Visual Studio Community 2019, ingresar al siguiente link y hacer click donde dice "Descargar Visual Studio":
https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2019

![ED21](images/PASO1.png)

Luego, al redireccionar a otra página, hacer click en donde dice "Descarga gratuita" en la sección "Comunidad" y se pondrá a descargar el ejecutable. Una vez abierto, se instalará y pedirá que el computador se reinicie para finalizar la instalación.

![ED21](images/PASO1_2.png)

Para configurar las librerías que ofrece OpenCV, creamos un nuevo proyecto.

![ED21](images/PASO8.png)

Hacer click derecho en el nombre del archivo del proyecto, y clickear en propiedades.

![ED21](images/PASO9.png)

Una vez abiertas las propiedades del proyecto, realizar las siguientes configuraciones que se muestran en las capturas (las marcadas en negrita) 

![ED21](images/PASO10.png)
![ED21](images/PASO11.png)
![ED21](images/PASO12.png)
![ED21](images/PASO13.png)

Y finalmente, para que reconozca lo previamente realizado utilizar el "x64" en la configuración de compilación, ya que si se ingresa otra no funcionará, puesto que las configuraciones se hicieron solo para x64.

![ED21](images/PASO14.png)


# Referencias

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. Computer Vision Zone. (2021, 14 julio). OpenCV C++. https://www.computervision.zone/courses/opencv-cv/
2. Márquez, J. C. C. (2019, 6 mayo). Instalar OpenCV con Visual Studio 2017. aprendiendo ingeniería. https://aprendiendoingenieria.es/instalar-opencv-con-visual-studio-2017/
