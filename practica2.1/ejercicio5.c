#include <sys/utsname.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  struct utsname buffer;
  
  if(uname(&buffer) == 0) {
    printf("Nombre del SO: %s\n", buffer.sysname);
    printf("Nombre del host: %s\n", buffer.nodename);
    printf("Release del SO : %s\n", buffer.release);
    printf("Version del SO: %s\n", buffer.version);
    printf("Hardware: %s\n", buffer.machine);
    printf("Dominio: %s\n", buffer.__domainname);
  
  }
  else{
    perror("Ha ocurrido un error\n");
  }
  
  return 0;
}
