//Javier Verde Marin
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
   
  int fd[2];
  
  if(pipe(fd) == -1){
    perror("Problema al crear el pipe\n");
    return -1;
  }
  
  pid_t pid = fork();

  switch(pid) {
  case -1:; 
     perror("Problema al realizar fork\n");
     return -1;

  case 0:; //Hijo
     close(fd[1]);
     dup2(fd[0], 0);
     close(fd[0]);
     execlp(argv[3], argv[3], argv[4], NULL);
     break;

 default:; //Padre
     close(fd[0]);
     dup2(fd[1],1);
     close(fd[1]);
     execlp(argv[1], argv[1], argv[2],NULL);
     break;
  }
 
 return 0;
}
