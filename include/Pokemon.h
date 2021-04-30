#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Pokemon tPokemon;


tPokemon* CriaPokemon(char* nome, int tipo, float ataque, float defesa, float HPmax);

void DestroyPokemon(tPokemon* Pokemon);

#endif
