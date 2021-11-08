//Javier Verde Marin
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>

//Se ha supuesto que el fichero se pasa por parametro 
int main(int argc, char * argv[]) {
 if(argc == 2) {
   int fd = open(argv[1], O_RDWR | O_CREAT , 0645);
    
   int locked = lockf(fd, F_TEST, 0);
  
   if(locked != -1){;
     lockf(fd, F_LOCK, 0);
     const time_t currTime = time(NULL);
     const  struct tm *currDate = localtime(&currTime);
     char * s = malloc(6);
     const char * format = "%H:%M"; 
     strftime(s, 6, format, currDate); 
     printf("%s\n", s);
     free(s);
     sleep(3);
     close(fd);

     lockf(fd, F_ULOCK, 0);
   }
   else {
    perror("El lock ya esta bloqueado\n");
    return -1;
   }
 }
 else {
   perror("Introduce una ruta de fichero\n");
   return -1;
 }
 return 0;
}
