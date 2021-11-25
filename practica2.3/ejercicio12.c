//Javier Verde Marin
#include <stdio.h>
#include <signal.h>

volatile int numInt=0;
volatile int numStp=0;

static void handler(int signal)
{
  if(signal == SIGINT) numInt++;
  else if(signal == SIGTSTP) numStp++;
}

int main() {

 struct sigaction act;
 act.sa_handler = handler;
 sigemptyset(&act.sa_mask);
 sigaddset(&act.sa_mask, SIGINT);
 sigaddset(&act.sa_mask, SIGTSTP);
 act.sa_flags = SA_RESTART;

 sigaction(SIGINT, &act, NULL);
 sigaction(SIGTSTP, &act, NULL);

 sigset_t set;
 sigfillset(&set);
 sigdelset(&set, SIGINT);
 sigdelset(&set, SIGTSTP);

 while(numInt + numStp < 10) {
   sigsuspend(&set);
 }
 
 printf("Se han recibido %i señales de tipo SIGINT\n", numInt);
 printf("Se han recibido %i señales de tipo SITSTP\n", numStp);

 return 0;
}
