#ifndef JOGADOR_H
#define JPGADOR_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Lista.h"


typedef struct jogador tJogador;

tJogador *newPlayer();

static int VerificaNickname(char *nome);

void destroyJogador(tJogador *x);

List *ReturnListaPoke(tJogador *x);

int ReturnqtdPokebola(tJogador *x);

char *ReturnNomeJogador(tJogador *x);

#endif //JOGADOR_H