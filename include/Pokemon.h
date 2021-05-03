#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pokemon tPokemon;


//tPokemon* CriaPokemon(char* nome, int tipo, float ataque, float defesa, float HPmax);

void DestroyPokemon(tPokemon* Pokemon);


tPokemon* FillPoke();

char* ReturnNome(tPokemon* Poke);

char* ReturnNome(tPokemon* Poke);

float ReturnAtaque(tPokemon* Poke);

float ReturnDefesa(tPokemon* Poke);

float ReturnHPmax(tPokemon* Poke);

float* ReturnHPatual(tPokemon* Poke);
#endif
