# Files and Directories #

En esta tarea, nos familiarizaremos con el API descrito en el capítulo del libro. Para hacer esto, usted solo debe escribir unos cuantos programas, la mayoria basada en varias utilidades UNIX.

## Questions ##

1. **Stat**: Escriba su propia versión del comando ```stat```, la cual simplemente invoca la llamada del sistema ```stat()``` en un archivo o directorio. Imprima el tamaño del archivo, el número de bloques asignado, reference (link) count, etc. Que es el link count de un directorio, como el numero de entradas en el directorio cambia? Interfaces Útiles: ```stat()```, naturalmente.

2. **List Files**: Escriba un programa que liste los archivos en un directorio dado. Cuando sea llamado sin argumentos, el programa deberá solo imprimir los nombres del archivo. Cuando se invoque con la flag ```-l```, el programa deberá imprimir la información de cada archivo tal como, owner, group, permissions y otra información obtenida de la llamada de sistema ```stat()```. El programa deberá tomar un argumento adicional el cual es el directorio a leer, por ejemplo, ```myls -l directory```.  Si ningún directorio es dado, el programa solo deberá usar el directorio de trabajo actual. Interfaces Útiles: ```stat()```, ```opendir()```, ```readdir()```, ```getcwd()```.

3. **Tail**: Escriba un programa que imprima una cuantas lineas de un archivo. El programa deberá ser eficiente, la forma como busca acercarse al final del archivo, leer un bloque de datos y luego retroceder hasta encontrar el número de líneas solicitado; hasta este punto, este podria imprimir esas lineas desde el principio al final del archivo. Para invocar el programa, uno deberia digitar: ```mytail -n file```, donde ```n``` es el número de lineas al final del archivo a imprimir. Interfaces Útiles: ```stat()```, ```lseek()```, ```open()```, ```read()```, ```close()```.

4. **Recursive Search**: Escriba un programa que imprima los nombres de cada archivo y directorio del arbol del sistema de archivos (file system tree), empezando en un punto dado del sistema de archivos en el arbol. Por ejemplo, cuando ejecute sin argumentos, el programa deberá empezar con el directorio de trabajo actual e imprimir su contenido, asi como con los contenidos de cualquier subdirectorio en este, etc., hasta que el arbol entero, root en el CWD sea impreso. Si se da un unico argumento (de un nombre de un directorio), use este como root en vez de el del sistema. Refine su busqueda recursiva con mas opciones de busqueda divertidas, similar a la poderosa herramienta por linea de comandos ```find```. Interfaces Útiles: Resolverlo.


## Referencias de utilidad ##

1. [Conceptos basicos claves resumidos](https://docs.google.com/document/d/1-336S7oKYwzSSSH-vzks8lGJ0R5VJoZu3PGBsz3vP2w/edit?usp=sharing)
2. [Aspectos basicos de C](https://github.com/repos-SO-UdeA/lab3)
3. [Manejo dinamico de memoria en C](https://github.com/repos-SO-UdeA/lab5)
4. [Manejo de archivos en C](https://github.com/repos-SO-UdeA/lab6)

