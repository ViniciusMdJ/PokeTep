#include "../include/Utilidades.h"

float CriaAleatorio(){
    float aleatorio = (float)rand()/(float)(RAND_MAX);
    return aleatorio;
}

void Clean(){
    system("clear");
}
