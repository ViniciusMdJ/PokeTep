#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pokemon tPokemon;

void DestroyPokemon(tPokemon* Pokemon);

tPokemon* FillPoke();

char* ReturnNome(tPokemon* Poke, int i);

float ReturnAtaque(tPokemon* Poke);

float ReturnDefesa(tPokemon* Poke);

float ReturnHPmax(tPokemon* Poke);

float* ReturnHPatual(tPokemon* Poke);

int ReturnTipo(tPokemon* Poke, int i);
#endif
