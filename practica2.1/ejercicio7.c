//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  const char dir[] = "/";
  long int maxLinks = pathconf(dir,_PC_LINK_MAX);
  long int maxRoute = pathconf(dir,_PC_PATH_MAX);
  long int maxName = pathconf(dir,_PC_NAME_MAX);

  printf("EL numero maximo de enlaces es: %li\n", maxLinks);
  printf("La longitud maxima de ruta es: %li\n", maxRoute);
  printf("La longitud maxima del nombre de fichero es: %li\n", maxName);
}
