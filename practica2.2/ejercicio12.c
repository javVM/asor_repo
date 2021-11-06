//Javier Verde Marin
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,  char * argv[]){
  int fd = open(argv[1], O_RDWR | O_CREAT, 0664);
  if(fd == -1){
     perror("No se ha podido ejecutar open() correctamente\n");
     return -1; 
  }
  else{
    //Cadenas de caracteres de prueba
    printf("Hola.");
    printf("Esto es una prueba.");
    printf("Adios.");
   
    dup(fd,1);
  }   

  return 0;
}
