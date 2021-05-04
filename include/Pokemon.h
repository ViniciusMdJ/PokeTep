#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct pokemon tPokemon;

void DestroyPokemon(void* Pokemon);

tPokemon ListaPoke(int i);

char* ReturnNome(tPokemon* Poke);

float ReturnAtaque(tPokemon* Poke);

float ReturnDefesa(tPokemon* Poke);

float ReturnHPmax(tPokemon* Poke);

float* ReturnHPatual(tPokemon* Poke);

int ReturnTipo(tPokemon* Poke);

List* InitIniciais();

void Movimento_0(tPokemon *poke1, tPokemon *poke2);

void Movimento_1(tPokemon *poke1, tPokemon *poke2);

void Movimento_2(tPokemon *poke1, tPokemon *poke2);

void CausarDano(tPokemon *poke, float dano);

float VerificaRelacao(tPokemon *poke1, tPokemon *poke2);
#endif
