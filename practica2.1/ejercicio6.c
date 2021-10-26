//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
 long int maxArguments = sysconf(_SC_ARG_MAX);
 long int maxChild = sysconf(_SC_CHILD_MAX);
 long int maxFiles = sysconf(_SC_OPEN_MAX);

 if(maxArguments != -1) printf("La longitud maxima de los argumentos es: %li\n", maxArguments);
 else printf("Se ha procucido un error\n");

 if(maxChild != -1) printf("El maximo numero de hijos es: %li\n", maxChild);
 else printf("Se ha producido un error\n");

 if(maxFiles != -1) printf("El maximo numero de ficheros abiertos es: %li\n", maxFiles);
 else printf("Se ha producido un error\n");

return 0;
}

