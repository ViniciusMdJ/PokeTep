#ifndef BATALHA_H
#define BATALHA_H

#include "Pokemon.h"
#include "Lista.h"
#include "Jogador.h"

int batalha(tJogador *player, FILE *arqLog);

void DadosAtaqueJogador(tPokemon *poke1, tPokemon *poke2, int pos);

void DadosAtaqueMaquina(tPokemon *poke1, tPokemon *poke2, int pos);

void PrintaStatus(int p, int d, int q);

void LogAtaqueJogador(FILE *arqLog, tPokemon *poke1, tPokemon *poke2, int pos);

void LogAtaqueMaquina(FILE *arqLog, tPokemon *poke1, tPokemon *poke2, int pos);

void LogStatus(FILE *arqLog,int p, int d, int q);

void LogCaptura(FILE *arqLog, int tentativa);

void LogFugir(FILE *arqLog, int tentativa);
#endif //BATALHA_H