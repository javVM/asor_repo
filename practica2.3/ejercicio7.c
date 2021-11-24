#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/****************** PARA EJECUTAR UNO U OTRO, DESCOMENTAR LA VERSION DESEADA Y COMENTAR LA OTRA ******************/

//Respuesta a la pregunta: El mensaje de finalizacion solo se mostrara en la version con SYSTEM ya que EXEC esta sustituyendo la imagen del proceso original por
//el comando que se está realizando.

//VERSION UTILIZANDO SYSTEM:

/*int main(int argc, char * argv[]) {
  if(argc !=  2){
    perror("Por favor, introduce un solo argumento (comando)\n");
    return 1;
  }
  else{
    system(argv[1]);
    printf("El comando termino de ejecutarse\n");
  }
  
  return 0;
}
*/

//VERSION UTILIZANDO EXEC:

int main(int argc, char * argv[]) {
  if(argc !=  2){
    perror("Por favor, introduce un solo argumento (comando)\n");
    return -1;
  }
  else{
    execvp(argv[1], argv+1);
    printf("El comando termino de ejecutarse\n");
  }
  
  return 0;
}
