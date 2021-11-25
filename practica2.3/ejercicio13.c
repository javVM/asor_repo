//Javier Verde Marin
#include <stdio.h>
#include <signal.h>

volatile int saved = 0;

static void handler(int signal)
{
  saved = 1;
}


int main(int argc, char * argv[]) {
 
 if(argc != 2){
   perror("Por favor introduce el numero de segundos hasta borrado\n");
   return -1;
 }
 
 struct sigaction act;
 act.sa_handler = handler;
 sigemptyset(&act.sa_mask);
 sigaddset(&act.sa_mask, SIGUSR1);
 act.sa_flags = SA_RESTART;

 sigaction(SIGUSR1, &act, NULL);

 sigset_t set;
 sigemptyset(&set);

 int sec = atoi(argv[1]);
 if(sec < 0) sec = 0;
 
 sleep(sec);
 
 if(saved == 1){
  printf("Se ha detenido la eliminacion del fichero\n"); 
  sigsuspend(&set);
 }
 else{
   printf("Fichero borrandose\n");
   unlink(argv[0]);
 }

 return 0;
}
