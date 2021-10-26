//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
 long int maxArguments = sysconf(_SC_ARG_MAX);
 long int maxChild = sysconf(_SC_CHILD_MAX);
 long int maxFiles = sysconf(_SC_OPEN_MAX);
 printf("La longitud maxima de los argumentos es: %li\n", maxArguments);
 printf("El maximo numero de hijos es: %li\n", maxChild);
 printf("El maximo numero de ficheros abiertos es: %li\n", maxFiles);
 return 0;
}

