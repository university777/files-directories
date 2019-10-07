    #include <stddef.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>

    int main(int argc, char *argv[]) {

        printf("Datos del archivo %s \n", argv[1]);
        struct stat buf;
        stat(argv[1], &buf);

        printf("Protección del archivo: %d \n",buf.st_mode);
        printf("Tamaño del archivo: %jd \n",buf.st_size);
        printf("Número de bloques: %jd \n",buf.st_blocks);
        printf("Tamaño de bloques: %jd \n",buf.st_blksize);
        printf("Número de Hardlinks: %jd \n",buf.st_nlink);

        return 0;
    }