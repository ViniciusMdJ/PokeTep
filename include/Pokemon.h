#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Ataques.h"

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

fptrAtaque MovimentoPokemon(tPokemon *poke, int pos);

void CausarDano(tPokemon *poke, float dano);

float VerificaRelacao(tPokemon *poke1, tPokemon *poke2);

void ResetaStatus(tPokemon *poke);

void AumenteHp(tPokemon *poke, float qtd);

char *NomedoAtk(tPokemon *poke, int pos);

int PodeAtacar(tPokemon *poke);

int Queimando(tPokemon *poke);

void DiminuiDormindo(tPokemon *x);

void DiminuiParalisado(tPokemon *x);

void DiminuiImune(tPokemon *x);

void DiminuiAtkDormir(tPokemon *x);

void DiminuiCavar(tPokemon *poke);

void Queimar(tPokemon *x);

void SetDormindo(tPokemon *poke, int x);

void SetParalisado(tPokemon *poke, int x);

void SetImune(tPokemon *poke, int x);

void SetAtkDormir(tPokemon *poke, int x);

int VerificaAtkDormir(tPokemon *x);

int VerificaCavar(tPokemon *x);

int VerificaImune(tPokemon *x);

int VerificaParalisado(tPokemon *x);

int VerificaDormindo(tPokemon *x);

void Cavou(tPokemon *x);

void Capturar(List *Pokemons, tPokemon *capiturado);
#endif
