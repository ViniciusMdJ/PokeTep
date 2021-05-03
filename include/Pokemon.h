#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Pokemon tPokemon;

void DestroyPokemon(tPokemon* Pokemon);

void Movimento_0(tPokemon *poke1, tPokemon *poke2);

void Movimento_1(tPokemon *poke1, tPokemon *poke2);

void Movimento_2(tPokemon *poke1, tPokemon *poke2);

void CausarDano(tPokemon *poke, float dano);

float VerificaRelacao(tPokemon *poke1, tPokemon *poke2);
#endif
