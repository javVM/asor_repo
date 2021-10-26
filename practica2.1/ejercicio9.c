//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/*En respuesta a la pregunta: El bit setuid esta activo en programas que se pueden ejecutar con los privilegios del creador en vez de los
  privilegios o permisos que tiene el usuario que lo ejecuta. Por tanto podemos asegurar que el bit setuid estara activo cuando el UID y el EUID sean
  distintos. EL EUID sera el del propietario/creador del fichero mientras que el UID sera el nuestro.
*/
int main() {
 
 printf("El UID (UID real) del usuario es %i y el EUID (UID efectivo) es %i\n", getuid(), geteuid());
 return 0;
}
