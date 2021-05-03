#include "../include/Utilidades.h"

float CriaAleatorio(){
    float aleatorio = (float)rand()/(float)(RAND_MAX);
    printf("ALEATORIO %f\n", aleatorio);
    return aleatorio;
}

void Clean(){
    system("clear");
}
