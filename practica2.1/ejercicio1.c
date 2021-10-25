#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

   if(setuid(0) != 0){
     perror("Ha ocurrido un error./n");
   }
   else printf("Se ha cambiado el UID de forma satisfactoria./n");
   return 1;
}
