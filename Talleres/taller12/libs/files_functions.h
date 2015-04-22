
#include <dirent.h>


char * show_dir(char * path){
    DIR *my_path;
    struct dirent * dir;
    
    if ((my_path = opendir(path)) == NULL) {
        fprintf(stderr,"Error al leer el directorio\n");
        exit (1);
    }

    char *buf = (char *)malloc(sizeof(char) * 400);
    strcat(buf, "DIRECTORIO COMPARTIDO: ");
    strcat(buf, path);
    strcat(buf, "\n\n");
    while ((dir=readdir(my_path)) != NULL) {
        // printf("%d - %c - %s\n", dir->d_ino, dir->d_type, dir->d_name);
        strcat(buf, "\t");
        strcat(buf, dir->d_name);
        strcat(buf, "\n");
    }
    printf("\n\nNo hay mas archivos.\n\n\n");

    // Cerramos el directorio
    closedir(my_path);

    printf("show_dir\n");
    return buf;
}


char * upload_file(char * path){
    printf("upload_file: %s\n", path);
    return "upload_file.......... %s", path;
}


char * delete_file(char * path){
    printf("delete_file: %s\n", path);
    return "delete_file.......... %s", path;
}