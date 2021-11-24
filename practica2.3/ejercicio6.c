//Javier Verde Marin
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define PATH_MAX 4097

/*
 Cuando se acaba el padre antes que el hijo, el PPID del hijo es 1 como se muestra aqui:  2630  1  2630  2630 ejercicio6 ya que es adoptado por Init()
 Cuando el hijo acaba antes que el padre ocurre lo siguiente:

 2618  2383  2618  2383 ejercicio6
 2619  2618  2619  2619 ejercicio6 <defunct>

 Se puede observar que el proceso hijo esta en estado zombie ya que el padre no ha hecho wait()
*/

void processAtributes(pid_t pid){

 char * buffer = malloc(PATH_MAX);
 struct rlimit rlim;

 printf("El el PID es: %i\n", getpid());
 printf("El PPID es: %i\n",getppid());
 printf("El PGID es: %i\n", getpgid(pid));
 printf("El SID es: %i\n", getsid(pid));
  
 if(getrlimit(RLIMIT_NOFILE, &rlim) != -1) printf("El maximo numero de ficheros que puede abrir el proceso es: %i\n", rlim.rlim_max);
 else perror("Error al usar getrlimit()\n");

 if(getcwd(buffer, PATH_MAX)) printf("El directorio de trabajo actual es: %s\n", buffer);
 else perror("Error al usar getcwd()\n"); 
 free(buffer);
} 

int main() {
  
  pid_t pid = fork();

 switch(pid) {
  case -1:; //Error
       perror("Error al usar fork()\n");
       break;

  case 0:; //Hijo
      if(setsid() == -1) perror("Error al crear una nueva sesion\n");
      if(chdir("/tmp") == -1) perror("Error al cambiar el directorio de trabajo\n");
    
      processAtributes(pid);

      break; 

 default:; //Padre
      //Se introduce una pausa para poder comprobar una de las preguntas:  sleep(3);
      processAtributes(pid);
      break;
 }
 
 return 0;
}

