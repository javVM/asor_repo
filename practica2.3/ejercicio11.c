//Javier Verde Marin
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
 
  setenv("SLEEP_SECS", "30", 1);
 
  sigset_t set;
  sigset_t setpend;

  sigemptyset(&set);
  sigaddset(&set, SIGINT);
  sigaddset(&set, SIGTSTP);
  sigprocmask(SIG_BLOCK, &set, NULL);
  
  sleep(atoi(getenv("SLEEP_SECS")));

  sigpending(&setpend);
  if(sigismember(&setpend,SIGINT)){
   printf("Se ha recibido la señal SIGINT\n");
 }
 else printf("No se ha recibido la señal SIGINT\n");
  
  if(sigismember(&setpend,SIGTSTP)){
    printf("Se ha recibido la señal SIGTSTP\n");  
    sigprocmask(SIG_UNBLOCK, &set, NULL); 
   
 }
 else printf("No se ha recibido la señal SIGTSTP\n");

  printf("Se ha reanudado el programa\n");
  return 0;
}
