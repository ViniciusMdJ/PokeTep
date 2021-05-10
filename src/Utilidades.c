#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"

float CriaAleatorio(){
    float aleatorio = (float)rand()/(float)(RAND_MAX);
    //printf("ALEATORIO %f\n", aleatorio);
    return aleatorio;
}

int VerificaEntre(const char* x, int bottom, int up){
    int escolha;

    if(VerificaNum(x)){
        escolha = atoi(x);
        if(bottom <= escolha && escolha <= up){
            return escolha;
        }
    }
    return 0;
};

void Clean(){
    system("clear");
}

int VerificaNum(const char *x){
    int i;
    for(i=0; x[i] != '\0'; i++){
        if(!isdigit(x[i])){
            return 0;
        }
    }
    return 1;
}