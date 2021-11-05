//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if(argc == 2){
     const char * route = argv[1];
     const char * termination1 = ".hard";
     const char * termination2 = ".sym";
     
     //Para poder añadir las terminaciones creamos nuevos strings, reservando espacio para la ruta + la terminacion
     char * hardlroute  = malloc(strlen(route) + strlen(termination1) + 1);
     char * symlroute =  malloc(strlen(route) + strlen(termination2) + 1);
    
     //Se copia la ruta a los strings de resultado y lo unimos con las terminaciones 
     strcpy(hardlroute, route);
     strcat(hardlroute, termination1);
     strcpy(symlroute, route);
     strcat(symlroute, termination2);
    
    //Se crea el enlace rigido y el simbolico
     link(route, hardlroute);
     symlink(route, symlroute);

     //Se libera la memoria
     free(hardlroute);
     free(symlroute);
  }
  else{
    perror("Se necesita 1 argumento para poder ejecutar la funcion\n");
  }
  return 0;
}
