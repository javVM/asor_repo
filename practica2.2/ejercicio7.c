//Javier Verde Marin
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
  umask(0027); 
  //Se puede comprobar la mascara del padre escribiendo umask en la shell
  //Aunque se cambie esta, la de la shell sigue siendo 0022, no 0027
  int fd = open("./fichero", O_RDWR | O_CREAT, 0645);
  
  if(fd == -1){
    perror("No se ha ejecutado open() correctamente./n"); 
  }
   
  return 0;
}

