//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() {

 struct passwd *info  = getpwuid(getuid());

 printf("El UID (UID real) del usuario es %i y el EUID (UID efectivo) es %i\n", getuid(), geteuid());
 printf("El nombre de usuario es: %s\n", info->pw_name);
 printf("Directorio home: %s\n", info->pw_dir);
 printf("Descripcion de usuario: %s\n", info->pw_gecos);
 return 0;
}

