//Javier Verde Marin
#include <stdio.h>
#include <sched.h>
#include <string.h>

char * getPolicy(int policy){
  if(policy == SCHED_FIFO) return "SCHED_FIFO";
  else if (policy == SCHED_RR) return "SCHED_RR";
  else if (policy == SCHED_OTHER) return "SCHED_OTHER";
}

int main() {
  
  struct sched_param  p;
  sched_getparam(0, &p);
  int scheduler = sched_getscheduler(0);
  printf("Politica de planificacion del proceso actual: %s\n", getPolicy(scheduler));
  printf("Prioridad del proceso actual: %i\n", p.sched_priority);
  printf("Prioridad maxima: %i\n", sched_get_priority_max(scheduler));
  printf("Prioridad minima: %i\n", sched_get_priority_min(scheduler));
 
  return 0;
}
