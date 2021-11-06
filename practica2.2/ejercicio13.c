//Javier Verde Marin
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

//En respuesta a las preguntas: Si, el orden de las redirecciones importa.
//ls > dirlist 2>&1 es diferente a ls 2>&1 > dirlist porque  en el primer caso se redirige la salida estandar al fichero y luego se redirige la salida de error al fichero, que es donde
//apunta la salida estandar; mientras que en el segundo caso la salida de error estandar se redirige a la salida estandar y luego esa salida al fichero por lo que en ese caso la salida de
//error no apunta al fichero. 
int main(int argc,  char * argv[]){
  int fd = open(argv[1], O_RDWR | O_CREAT, 0664);
  if(fd == -1){
     perror("No se ha podido ejecutar open() correctamente\n");
     return -1; 
  }
  else{ 

    dup2(fd,1);
    dup2(fd,2);
  
   //Cadenas de prueba
   printf("Hola.");
   printf("Esto es una prueba.");
   printf("Adios.");
   perror("Se ha producido un error");
  }   

  return 0;
}
