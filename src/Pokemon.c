#include "../include/Pokemon.h"

enum TipoP{eletrico, fogo, agua, planta, metal, psiquico};

typedef struct pokemon {
    char nome[20];
    int tipo;
    int dormindo;
    int queimando;
    int paralisado;

    float ataque;
    float defesa;
    float HPmax;
    float HPatual;
    tPokemon* prox;
    //- ponteiro de função de ataques
}tPokemon;


/*tPokemon* CriaPokemon(char* nome, int tipo, float ataque, float defesa, float HPmax){
    tPokemon* poke;

    poke = (tPokemon*)calloc(1, sizeof(tPokemon));

    strcpy(poke->nome, nome);
    poke->tipo = tipo;
    poke->ataque = ataque;
    poke->defesa = defesa;
    poke->HPmax = HPmax;
return poke;
}*/

void DestroyPokemon(tPokemon* Pokemon){
    free(Pokemon);
}

tPokemon* FillPoke(){
    int i;
    tPokemon* Lista;
    Lista = (tPokemon*)calloc(6, sizeof(tPokemon));

    for(i = 0; i < 6; i++){
        if(i == 0){
            strcpy(Lista[0].nome, "Picachu");
            Lista[0].tipo = eletrico;
            Lista[0].ataque = 110;
            Lista[0].defesa = 100;
            Lista[0].HPmax = 200;
        }
        else if(i == 1){
            strcpy(Lista[1].nome, "Charizard");
            Lista[1].tipo = fogo;
            Lista[1].ataque = 160;
            Lista[1].defesa = 150;
            Lista[1].HPmax = 260;
        }
        else if(i == 2){
            strcpy(Lista[2].nome, "Blastoise");
            Lista[2].tipo = agua;
            Lista[2].ataque = 180;
            Lista[2].defesa = 200;
            Lista[2].HPmax = 280;
        }
        else if(i == 3){
            strcpy(Lista[3].nome, "Venusaur");
            Lista[3].tipo = planta;
            Lista[3].ataque = 160;
            Lista[3].defesa = 160;
            Lista[3].HPmax = 300;
        }
        else if(i == 4){
            strcpy(Lista[4].nome, "Steelix");
            Lista[4].tipo = metal;
            Lista[4].ataque = 170;
            Lista[4].defesa = 400;
            Lista[4].HPmax = 280;
        }
        else if(i == 5){
            strcpy(Lista[5].nome, "Mew");
            Lista[5].tipo = psiquico;
            Lista[5].ataque = 200;
            Lista[5].defesa = 200;
            Lista[5].HPmax = 320;
        }
    }
return Lista;
}
char* ReturnNome(tPokemon* Poke){
    return Poke->nome;
}
float ReturnAtaque(tPokemon* Poke){
    return Poke->ataque;
}
float ReturnDefesa(tPokemon* Poke){
    return Poke->defesa;
}
float ReturnHPmax(tPokemon* Poke){
    return Poke->HPmax;
}
float* ReturnHPatual(tPokemon* Poke){
    return &Poke->HPatual;
}
