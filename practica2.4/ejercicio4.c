//Javier Verde Marín
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char * argv[]) {
  
 if(argc < 2){
    perror("Se necesita un argumento\n");
    return -1;
 } 

 int fd = open("tuberia", O_WRONLY); 

 if(fd == -1) {
    perror("Problema al abrir la tuberia con open()\n");
    return -1;
 }
 
 write(fd, argv[1], strlen(argv[1])+1);
 close(fd);

 return 0;
}
