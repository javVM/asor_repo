//Javier Verde Marin
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    
   if(setuid(0) != 0){
     printf("Se ha producido un error, con numero %d: %s\n", errno, strerror(errno));
   }
   else printf("Se ha cambiado el UID de forma satisfactoria.\n");
   
   return 1;
}

