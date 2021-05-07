#ifndef JOGADOR_H
#define JPGADOR_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Lista.h"


typedef struct jogador tJogador;

void imprimeJogador(tJogador *x);

tJogador *newPlayer();

static int VerificaNickname(char *nome);

void destroyJogador(tJogador *x);

List *ReturnListaPoke(tJogador *x);

int *ReturnVitorias(tJogador *x);

int ReturnqtdPokebola(tJogador *x);

#endif //JOGADOR_H