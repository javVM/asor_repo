#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>

#define PATH_MAX 4097

void processAtributes(){

 pid_t pid = getpid();
 char * buffer = malloc(PATH_MAX);
 struct rlimit rlim;

 printf("El el PID es: %i\n", pid);
 printf("El PPID es: %i\n",getppid());
 printf("El PGID es: %i\n", getpgid(pid));
 printf("El SID es: %i\n", getsid(pid));

 if(getrlimit(RLIMIT_NOFILE, &rlim) != -1)
 printf("El maximo numero de ficheros es %i\n", rlim.rlim_max);
 else perror("Error al usar getrlimit()\n");

 if(getcwd(buffer, PATH_MAX))
 printf("El directorio de trabajo actual es: %s\n", buffer); 
 else perror("Error al usar getcwd()\n"); 
 free(buffer);
} 

int main(int argc, char * argv[]) {

 if(argc < 2){
   perror("Introduce un comando por favor\n");
   return -1;
 }

 pid_t pid = fork();
 
 switch(pid) {
  case -1:; //Error
       perror("Error al usar fork()\n");
       exit(1);

  case 0:; //Hijo
      if(setsid() == -1) perror("Error al crear una nueva sesion\n");
      if(chdir("/tmp") == -1) perror("Error al cambiar el directorio de trabajo\n");
    
      processAtributes(pid);
      
      int fd = open("/tmp/daemon.out", O_RDWR|O_CREAT, 0644);
      int fd2 = open("/tmp/daemon.err", O_RDWR|O_CREAT, 0644);
      int fd3 = open("/dev/null", O_RDWR|O_CREAT, 0644);

      if(fd == -1 || fd2 == -1 || fd3 == -1) perror("Error al usar open()\n");
       else {
         dup2(fd,1);     
         dup2(fd2,2);
         dup2(fd3,0);
      
       }
       execvp(argv[1], argv+1);
      break; 

  default:; //Padre
      processAtributes(pid);
      break;
 }
  
 return 0;
}

