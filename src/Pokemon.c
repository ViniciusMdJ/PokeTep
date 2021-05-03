#include "../include/Pokemon.h"

enum TipoP{eletrico, fogo, agua, planta, metal, psiquico};

typedef struct pokemon {
    char* nome;
    int tipo;
    int dormindo;
    int queimando;
    int paralisado;

    float ataque;
    float defesa;
    float HPmax;
    float HPatual;
    //- ponteiro de função de ataques
} tPokemon;


tPokemon* ListaPoke(int i){
    tPokemon* Poke;
    Poke = malloc(sizeof(tPokemon));
    if(i == 0){
        Poke->nome = "Picachu";
        Poke->tipo = eletrico;
        Poke->ataque = 110;
        Poke->defesa = 100;
        Poke->HPmax = 200;
    }
    else if(i == 1){
        Poke->nome = "Charizard";
        Poke->tipo = fogo;
        Poke->ataque = 160;
        Poke->defesa = 150;
        Poke->HPmax = 260;
    }
    else if(i == 2){
        Poke->nome = "Blastoise";
        Poke->tipo = agua;
        Poke->ataque = 180;
        Poke->defesa = 200;
        Poke->HPmax = 280;
    }
    else if(i == 3){
        Poke->nome = "Venusaur";
        Poke->tipo = planta;
        Poke->ataque = 160;
        Poke->defesa = 160;
        Poke->HPmax = 300;
    }
    else if(i == 4){
        Poke->nome = "Steelix";
        Poke->tipo = metal;
        Poke->ataque = 170;
        Poke->defesa = 400;
        Poke->HPmax = 280;
    }
    else if(i == 5){
        Poke->nome = "Mew";
        Poke->tipo = psiquico;
        Poke->ataque = 200;
        Poke->defesa = 200;
        Poke->HPmax = 320;
    }
return Poke;
}
char* ReturnNome(tPokemon* Poke, int i){
    return Poke[i].nome;
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
int ReturnTipo(tPokemon* Poke, int i){
    return Poke[i].tipo;
}

void DestroyPokemon(tPokemon* Pokemon){
    free(Pokemon);
}
