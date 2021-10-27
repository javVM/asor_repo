//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main() {
 setlocale(LC_ALL, "es_ES.utf8");
 const time_t currTime = time(NULL);
 const  struct tm *currDate = localtime(&currTime);

 char * s = malloc(50);
 const char * format = "%A, %d de %B de %Y, %H:%M"; 

 strftime(s, 50, format, currDate);
 printf("%s\n", s);
 free(s);

 return 0;
}
