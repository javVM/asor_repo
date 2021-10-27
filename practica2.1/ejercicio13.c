//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

const int MAX  = 1000000;

int main(){

 int i = 0;
 struct timeval beforeloop;
 struct timeval afterloop;
 
 gettimeofday(&beforeloop, NULL);
 while(i < MAX){
   i++;
 }
 gettimeofday(&afterloop, NULL);

 printf("La ejecucion del bucle tarda %ld microsegundos\n", afterloop.tv_usec - beforeloop.tv_usec); 
 return 0;
}
