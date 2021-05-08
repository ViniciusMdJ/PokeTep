#ifndef BATALHA_H
#define BATALHA_H

#include "Pokemon.h"
#include "Lista.h"
#include "Jogador.h"

int batalha(tJogador *player);

void DadosAtaqueJogador(tPokemon *poke1, tPokemon *poke2, int pos);

void DadosAtaqueMaquina(tPokemon *poke1, tPokemon *poke2, int pos);

void PrintaStatus(int p, int d, int q);

#endif //BATALHA_H