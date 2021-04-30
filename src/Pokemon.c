#include "../include/Pokemon.h"

enum TipoP{eletrico, fogo, agua, planta, metal, psiquico};

typedef struct Pokemon {
    char* nome;
    int tipo;
    int estado;
    float ataque;
    float defesa;
    float HPmax;
    float HPatual;
    tPokemon* prox;
    //- ponteiro de função de ataques
} tPokemon;


tPokemon* CriaPokemon(char* nome, int tipo, float ataque, float defesa, float HPmax){
    tPokemon* poke;

    poke = (tPokemon*)calloc(1, sizeof(tPokemon));

    poke->nome = nome;
    poke->tipo = tipo;
    poke->ataque = ataque;
    poke->defesa = defesa;
    poke->HPmax = HPmax;
return poke;
}

void DestroyPokemon(tPokemon* Pokemon){
    for(Pokemon = Pokemon; Pokemon != NULL; Pokemon = Pokemon->prox){
        free(Pokemon->nome);
        free(Pokemon);    
    }
}
/* func ataq devolve int(uma para calc o dano e outra para aplicar) ou void(passar point alvo)
 * salvar pokes padrao vet
 * struct ataq? salvar os ataqs no tPokemon ou em um vetor
 * */

