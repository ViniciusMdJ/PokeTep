#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

enum TipoP{fogo, agua, planta, eletrico, psiquico, metal, normal};

typedef struct pokemon tPokemon;

void DestroyPokemon(void* Pokemon);

tPokemon *ListaPoke(int i);

char* ReturnNome(tPokemon* Poke);

float ReturnAtaque(tPokemon* Poke);

float ReturnDefesa(tPokemon* Poke);

float ReturnHPmax(tPokemon* Poke);

float* ReturnHPatual(tPokemon* Poke);

int ReturnTipo(tPokemon* Poke);

List* InitIniciais();

void CausarDano(tPokemon *poke, float dano);

float VerificaRelacao(tPokemon *poke1, tPokemon *poke2);

void ResetaStatus(tPokemon *poke);

void AumenteHp(tPokemon *poke, float qtd);

char *NomedoAtk(tPokemon *poke, int pos);

int PodeAtacar(tPokemon *poke);

int Queimando(tPokemon *poke);
#endif
