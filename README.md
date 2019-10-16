# Files and Directories #

En esta tarea, nos familiarizaremos con el API descrito en el capítulo del libro. Para hacer esto, usted solo debe escribir unos cuantos programas, la mayoría basados en varias utilidades UNIX.

## Questions ##

1. **Stat**: Escriba su propia versión del comando ```stat```, la cual simplemente invoca la llamada del sistema ```stat()``` en un archivo o directorio. Imprima el tamaño del archivo, el número de bloques asignado, contador de referencias (links), etc. ¿Qué significa el contador de referencias (link count) de un directorio?, ¿cómo cambia el número de entradas en el directorio? Interfaces útiles: ```stat()```, naturalmente.

![alt tag](https://github.com/university777/files-directories/blob/master/carpeta_vacia_primer_punto.JPG)  
![alt tag](https://github.com/university777/files-directories/blob/master/carpeta_con_otracarpeta_primer_punto.JPG)  

>¿Qué significa el contador de referencias (link count) de un directorio?
El Link count de un directorio se refiere a el número de enlaces que tiene ese directorio. Como se ve en la primera captura primero se corre el comando en el directorio vacio "carpeta1" y nos arroja un count link de 2 ya que el directorio de sistemas tipo Unix crea dos entradas: una apuntando a si mismo y otra apuntando a su padre. Luego en la segunda captura creamos una carpeta dentro del directorio anterior y volvemos a correr el programa, ahora el count link nos arroja un valor de 3. Y así sucesivamente se cumple que cada count link del directorio es de 2+n, siendo n el número de subdirectorios.


2. **List Files**: Escriba un programa que liste los archivos en un directorio dado. Cuando sea llamado sin argumentos, el programa deberá imprimir solo los nombres del archivo. Cuando se invoque con la flag ```-l```, el programa deberá imprimir la información de cada archivo tal como, owner, group, permissions y otra información obtenida de la llamada de sistema ```stat()```. El programa deberá tomar un argumento adicional el cual es el directorio a leer, por ejemplo, ```myls -l directory```.  Si ningún directorio es dado, el programa deberá usar el directorio de trabajo actual. Interfaces útiles: ```stat()```, ```opendir()```, ```readdir()```, ```getcwd()```.

![alt tag](https://github.com/university777/files-directories/blob/master/segundo_punto_sin_parametros.JPG)  
![alt tag](https://github.com/university777/files-directories/blob/master/segundo_punto_con_parametros.JPG)  

3. **Tail**: Escriba un programa que imprima una cuantas líneas al final de un archivo. El programa deberá ser eficiente, de manera que realice un *seek* para desplazarse cerca del final del archivo, realice una lectura de un bloque de datos y luego retroceda hasta encontrar el número de líneas solicitado; hasta este punto, el programa debería imprimir esas lineas desde el principio al final del archivo. Para invocar el programa, uno deberia digitar: ```mytail -n file```, donde ```n``` es el número de lineas al final del archivo a imprimir. Interfaces Útiles: ```stat()```, ```lseek()```, ```open()```, ```read()```, ```close()```.
> En el siguiente ejemplo se tiene un archivo de 12 lineas y se le pide al programa imprimir las últimas 4 líneas:  
![alt tag](https://github.com/university777/files-directories/blob/master/tercerpunto1.png)  
Cuando se ingresa un número de líneas mayor a las del archivo, el programa simplemente imprime todo el archivo:  
![alt tag](https://github.com/university777/files-directories/blob/master/tercerpunto2.png)  





