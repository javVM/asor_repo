//Javier Verde Marin
#include <stdio.h>
#include <unistd.h>

int main() {
  
  pid_t pid = getpid();
  
  printf("El el PID es: %i\n", getpid());
  printf("El PPID es: %i\n",getppid());
  printf("El PGID es: %i\n", getpgid(pid));
  printf("El SID es: %i\n", getsid(pid));


}
