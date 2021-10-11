![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Tamara Ossandón (Encargada de bitácora)
* Sebastian Ledezma (Coordinador)

## Resumen 

> Como grupo se tuvieron varias instancias de aprendizaje en el transcurrir de las semanas, como primer objetivo fue crear un lugar donde poder tener contacto y crear reuniones al momento de estudiar o realizar trabajos en conjunto, la plataforma usada fue Discord debido a su propuesta de chat de voz y chat escrito, también se dio la tarea de entender y aplicar lo enseñado en clases sobre C y C++, luego se tuvo una instancia de aprendizaje sobre github ya que se nos presento como plataforma de desarrollo, pero como grupo fue una plataforma totalmente nueva debido a  eso se aprendió lo básico tanto la creación de nuevos archivos, carpetas, el funcionamiento de la plataforma y como interactuar con esta misma. Como ultimo objetivo como grupo se coordinó realizar la instalación de IDE y configuración de librerías openCV que se pidió con anterioridad y esto también trajo consigo una instancia de aprendizaje de esta plataforma igualmente nueva para el grupo.

## 1. Introducción



### 1.1 Descripción del problema (Revisado)

El presente proyecto tiene como objetivo implementar un sistema desarrollado en el lenguaje de programación C++ y librerías de OpenCV, que conste en la detección de rostros faciales de un archivo multimedia que presenta distintas identidades, es por tanto, por lo que el se tiene que diseñar y desarrollar una inteligencia artificial la cual detecte cada rostro presente en el video señalándolo con un cuadro de color rojo alrededor de él. Además, se debe implementar diferentes funciones que tendrán un uso en el ámbito de la vigilancia, tales como; un listado de las personas (identidades) detectadas en un intervalo de tiempo definido en el video, y un listado de todas las identidades que se vieron expuestas en la grabación. Ambas, mostrando el número de cada identidad correspondiente y su duración efectiva de exposición. 

### 1.2 Objetivos (Revisado)

**Objetivo General**

Construir un sistema de vigilancia a través del reconocimiento de rostros, en donde, mediante una cámara o un video, se detect3n los rostros de las diferentes personas que están presentes en la grabación, obteniendo diferentes datos y estadísticas relacionadas a las identidades identificadas.

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

Describir brevemente las librerías utilizadas para la instalación y programas utilizados para la ejecución del código. (Agregar una sección de anexo para describir como fueron instaladas las librerías de OpenCV y la IDE utilzada para el trabajo)

### 2.2 Diseño 

Explicar los componentes (módulos o clases) utilizados para resolver el problema. Indicar arquitectura propuesta, diagrama de clases u otro artefacto que estime conveniente para explicar el diseño de su implimentación.

### 2.3 Implementación

Explicar brevemente algunos aspectos de implementación: Por ejemplo, detector de caras utilizado. Se pueden realizar pequeñas reseñas al código para indicar elementos importantes en el trabajo.

Por ejemplo, 

#### Detector de caras

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:

```c++
 1. faceCascadePath = "./haarcascade_frontalface_default.xml";
 2. faceCascade.load( faceCascadePath )
 3. std::vector<Rect> faces;
 4. faceCascade.detectMultiScale(frameGray, faces);

 5. for ( size_t i = 0; i < faces.size(); i++ )
 6. {
 7.  int x1 = faces[i].x;
 8.  int y1 = faces[i].y;
 9.  int x2 = faces[i].x + faces[i].width;
10.  int y2 = faces[i].y + faces[i].height;
11. }
```
La primera linea carga el archivo de entrenamiento... etc

## 3. Resultados obtenidos

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018


