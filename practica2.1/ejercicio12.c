//Javier Verde Marin
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
 time_t  time_now = time(NULL);
 printf("La hora en segundos desde Epoch es: %lli\n", time_now);
 return 0;
}
