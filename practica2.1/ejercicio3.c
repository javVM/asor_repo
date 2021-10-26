//Javier Verde Marin
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

const int  MAX = 255;

int main() {
  //El 0 no es realmente un error, implica que, de hecho no se ha producido ninguno.
  for(int i = 0; i < MAX; i++){
   printf("Error %d: %s\n",i, strerror(i));  

  }
  return 1;
}
