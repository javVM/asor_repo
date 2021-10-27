//Javier Verde Marin
#include <stdio.h>
#include <time.h>

int main() {
 const time_t currTime = time(NULL);
 struct tm *currDate = localtime(&currTime);
 //currDate devuelve los anios entre el actual y 1900
 printf("El anio actual es: %i\n", currDate->tm_year + 1900);

 return 0;
}
