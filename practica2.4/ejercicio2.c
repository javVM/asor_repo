//Javier Verde Marin
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>


int main(){
   
  int h_p[2];
  int p_h[2];
  
  if(pipe(h_p) == -1 || pipe(p_h) == -1){
    perror("Problema al crear el pipe\n");
    return -1;
  }
  
  pid_t pid = fork();

  switch(pid) {
  case -1:; 
     perror("Problema al realizar fork\n");
     return -1;

  case 0:; //Hijo
     int i = 0;
     close(h_p[0]);
     close(p_h[1]);
    
     char rec_h[512]; //Mensaje recibido del padre
     int rec_hl = 0;  //Longitud del mensaje que recibe del padre
    

     while (i < 10){            
        rec_hl = read(p_h[0], rec_h, 512);
        rec_h[rec_hl] = '\0'; //Read no lo añade
        write(1, rec_h, rec_hl);
 
        sleep(1);
        
        if(i < 9) write(h_p[1], "l" , 2);
        else write(h_p[1], "q" , 2); 
        i++;
       
     }
    
     close(h_p[1]);
     close(p_h[0]);
     break;

 default:; //Padre
     close(h_p[1]);
     close(p_h[0]);
    
     char message_p[512]; //Mensaje que envia el padre
     int message_pl; //Longitud del mensaje que envia el padre
     char rec_p[2]; //Mensaje que recibe del hijo
  
     while(strcmp(rec_p, "q") != 0) {
      
  	message_pl = read(0, message_p, 512);
       	message_p[message_pl] = '\0'; //Read no lo añade
       	write(p_h[1], message_p, message_pl);
       
        read(h_p[0], rec_p, sizeof(rec_p));
        printf("Se ha recibido el caracter  %s del hijo\n", rec_p);
     }
     wait(NULL);
     close(h_p[0]);
     close(p_h[1]);
     printf("Proceso padre acabado\n");
     break;
  }

 return 0;
}
