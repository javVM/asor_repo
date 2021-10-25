#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

const int  MAX = 255;

int main() {
  //Se ignora el 0 porque significa que no se han producido errores
  for(int i = 1; i < MAX; i++){
   printf("Error %d: %s\n",i, strerror(i));  

  }
  return 1;
}
