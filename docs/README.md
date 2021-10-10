![UCN](images/60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Tamara Ossandón (Rol)
* Sebastian Ledezma (Rol)

## Resumen 

> Como grupo se tuvieron varias instancias de aprendizaje en el transcurrir de las semanas, como primer objetivo fue crear un lugar donde poder tener contacto y crear reuniones al momento de estudiar o realizar trabajos en conjunto, la plataforma usada fue Discord debido a su propuesta de chat de voz y chat escrito, también se dio la tarea de entender y aplicar lo enseñado en clases sobre C y C++, luego se tuvo una instancia de aprendizaje sobre github ya que se nos presento como plataforma de desarrollo, pero como grupo fue una plataforma totalmente nueva debido a  eso se aprendió lo básico tanto la creación de nuevos archivos, carpetas, el funcionamiento de la plataforma y como interactuar con esta misma. Como ultimo objetivo como grupo se coordinó realizar la instalación de IDE y configuración de librerías openCV que se pidió con anterioridad y esto también trajo consigo una instancia de aprendizaje de esta plataforma igualmente nueva para el grupo.

## 1. Introducción

La primera función de un reporte técnico es plasmar la información necesaria para que otras personas puedan reproducir el sistema propuesto o puedan entender su fucnionamiento . Para cumplir anterior se debe diferenciar claramente entre los artefactos de diseño e implementación. En el caso de un desarrollo tecnológico los algoritmos son importantes como componente de diseño y los programas generalmente son irrelevantes y deben resumidos o agregados en anexos en el documento. Los programas no son importantes en el documento, salvo si se quiere explicar conceptos expecíficos del lenguaje o del algoritmo implementado.

La redacción debe ser formal y de modo impersonal. No se debe utlizar primera persona del singular o plural. Se debe evitar el uso de cualquier calificativo sustituyéndolo siempre utilizando datos concretos y rastreables en documentos o publicaciones a través de referencias bibliográficas. Por ejemplo, no calificar algo como: "muy importante", "sustancial", "muy usadoo" o "mucho mejor".

Las comparaciones deben concretarse con hechos y datos, sin frases ambiguas o términos generales. Por ejemplo, nunca se debe redactar frases como "el método es mejor que el método B". Lo correcto es decir, el error promedio de el método A es de 5 %, correspondiendo a la mitad del error de 10% obtenido utilizando el método B". El tiempo verbal es usualmente presente. No se debe perder de vista que se está explicando ”como hacer algo”, en vez de ”qué se hizo”. Todo aspecto circunstancial es irrelevante para el documento. Por ejemplo, si se ha desarrollado en el laboratorio X, o en el curso Y, con el profesor Z, etc.

### 1.1 Descripción del problema (Revisar si esta bien)

Para este proyecto se plantea la problemática de detectar rostros faciales usando C++ donde se dispondrá de un video en el cual circulan personas, se tendrá que crear una inteligencia artificial la cual detectara el rostro y por cada rostro detectado este se señalara en un recuadro de color rojo, agregado a eso se implementaran diferentes funciones tales como la cantidad de personas detectadas y el tiempo que estas personas están siendo detectadas, también se darán estadísticas derivadas del tiempo en el cual la persona está siendo detectada.

### 1.2 Objetivos (Revisar si esta bien)

**Objetivo General**

Construir un sistema el cual sea capas de detectar rostros faciales y de estos rostros entregar diferentes tipos de datos y estadísticas.

**Objetivos específicos**

1. Implementar la detección del rostro.
2. Señar el rostro detectado con un recuadro de un color rojo.
3. Entregar a cada rostro detectado un código de identidad.
4. Obtener las cinco identidades que más tiempo fueron detectados.
5. Establecer e implementar intervalos de tiempo donde se arrojarán diferentes tipos de estadísticas y valores sobre las identidades.
6. Crear una lista de las diferentes identidades detectadas.
7. Implementar los intervalos de tiempo junto con los listados para ver las estadísticas y valores.

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


