//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  const char dir[] = "/";
  long int maxLinks = pathconf(dir,_PC_LINK_MAX);
  long int maxRoute = pathconf(dir,_PC_PATH_MAX);
  long int maxName = pathconf(dir,_PC_NAME_MAX);
  
  if(maxLinks != -1) printf("El numero maximo de enlaces es: %li\n", maxLinks);
  else printf("No hay numero maximo de enlaces.\n");
  
  if(maxRoute != -1) printf("La longitud maxima de ruta es: %li\n", maxRoute);
  else printf("No hay longitud maxima de ruta.\n");

  if(maxName != -1) printf("La longitud maxima del nombre de fichero es: %li\n", maxName);
  else printf("No hay longitud maxima  para los nombres de fichero\n");
}
