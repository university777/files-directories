#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void tail(int lines, char *file_name)
{
      struct stat file;
      int size = 0;
      char *ch = NULL;
      char *buf = NULL;

      FILE *fd = fopen(file_name, "r");

      if(fd == NULL)
      {
              printf("No fue posible abrir el archivo: %s\n", file_name);
              return;
      }

      // Se ubica el puntero al final
      fseek(fd, 0, SEEK_END);
      // Se obtiene el tamaño del archivo
      size = ftell(fd);
      --size;
      // Se asigna espacio en memoria al buffer que guardarà las lineas a imprimir
      ch = (char *)malloc(2);
      buf = (char *)malloc(80 * lines);
      memset(buf, 0, 80 * lines);
      char * start = buf;
      *buf++ = '\0';

      // Se copia el contenido del archivo en el buffer desde el final del archivo hacia arriba
      // Se usa fseek --> SEEK_SET para navegar en el archivo desde atràs

      while(size && lines)
      {
              --size;
              fseek(fd, size , SEEK_SET);
              fread(ch, 1, 1, fd);
              *buf++ = *ch;
              if(*ch == '\n')
                      lines--;
      }
      fclose(fd);

      // Se imprime el contenido del buffer
      while( start != buf)
              printf("%c", *buf--);

      printf("\n");
      return;
}

int main(int argc, char **argv)
{
      if(argc != 3)
      {
              printf("Ejecutar asì: ./mytail num_of_lines file_name \n");
              return (-1);
      }

      char *file = argv[2];
      tail(atoi(argv[1]), file);

      return 0;
}