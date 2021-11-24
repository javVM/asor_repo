//Javier Verde Marin
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define PATH_MAX 4096

int main() {
  
  pid_t pid = getpid();
  char * buffer; 
  struct rlimit rlim; 

  printf("El el PID es: %i\n", getpid());
  printf("El PPID es: %i\n",getppid());
  printf("El PGID es: %i\n", getpgid(pid));
  printf("El SID es: %i\n", getsid(pid));
  
  if(getrlimit(RLIMIT_NOFILE, &rlim) != -1) printf("El maximo numero de ficheros que puede abrir el proceso es: %i\n", rlim.rlim_max);
  else perror("Error al usar getrlimit()\n");

  if(getcwd(buffer, PATH_MAX)) printf("El directorio de trabajo actual es: %s\n", buffer);  
  else perror("Error al usar getcwd()\n");

  return 0;
}
