    #include <stddef.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <dirent.h>
    #include <pwd.h>
    #include <grp.h>
    #include <string.h>
    #define DirectorioActual getcwd

    int main(int argc, char *argv[]) {
        struct dirent *pDirent;
        DIR *pDir;
        struct stat buf;

        if(argc <= 2) {
            char actual[FILENAME_MAX];
            DirectorioActual(actual, FILENAME_MAX);
            printf("Se usará %s \n",actual);
            pDir = opendir(actual);
        } else if (argc > 2){
            printf("Se usará %s \n",argv[2]);
            pDir = opendir(argv[2]);
            stat(argv[2], &buf);
        }


        while ((pDirent = readdir(pDir)) != NULL) {
            printf("[%s] \n",pDirent->d_name);
            if(argc >= 2) {
             struct passwd *pwd = getpwuid(buf.st_uid);
             struct group *gr = getgrgid(buf.st_gid);
             printf("Usuario propietario: %s \n",pwd->pw_name);
             printf("Grupo del propietario: %s \n",gr->gr_name);
             printf("Protección del archivo: %d \n",buf.st_mode);
            }
        }
        
        closedir(pDir);
        return 0;
    }