#ifndef PONTUACAO_H
#define PONTUACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct Pontuacao tPontuacao;

void imprimePontuacao(char *caminho);

void addNewPontuacao(int partidas, char *nick, char *caminho);

static tPontuacao *LeArquivo(char *caminho);

static void destroyPontuacao(tPontuacao *x);

static int maiorPontuacao(tPontuacao *le, tPontuacao *nova);

static void salvaPontuacao(tPontuacao *x, char *caminho);

#endif //PONTUACAO_H