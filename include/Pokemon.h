#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Pokemon tPokemon;


tPokemon* CriaPokemon(char* nome, int tipo, float ataque, float defesa, float HPmax);

void DestroyPokemon(tPokemon* Pokemon);

char* ReturnNome(tPokemon* Poke);

char* ReturnNome(tPokemon* Poke);

float ReturnAtaque(tPokemon* Poke);

float ReturnDefesa(tPokemon* Poke);

float ReturnHPmax(tPokemon* Poke);

float* ReturnHPatual(tPokemon* Poke);

void Movimento_0(tPokemon *poke1, tPokemon *poke2);

void Movimento_1(tPokemon *poke1, tPokemon *poke2);

void Movimento_2(tPokemon *poke1, tPokemon *poke2);

void CausarDano(tPokemon *poke, float dano);

float VerificaRelacao(tPokemon *poke1, tPokemon *poke2);
#endif
