#ifndef JOGADOR_H
#define JOGADOR_H


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Lista.h"


typedef struct jogador tJogador;
/**
 * @brief Funcao para retornar struct tJogador
 * @return struct tJogador
 */
tJogador *newPlayer();

/**
 * @brief Funcao para verificar se o nick e valido
 * @param char *nome string referente ao nickname
 * @return 1 caso o nickname seja valido e 0 caso contrario
 */
static int VerificaNickname(char *nome);
/**
 * @brief Funcao para liberar tJogador
 * @param tJogador *x Jogador que sera liberado
 */
void destroyJogador(tJogador *x);

/**
 * @brief Funcao para retornar a lista de poke do tJogador
 * @param tJogador *x Jogador o qual sera acessado a lista
 * @return List* referente aos pokes contidos dentro de tJogador
 */
List *ReturnListaPoke(tJogador *x);

/**
 * @brief Funcao para retornar a a qtdPokebola do tJogador
 * @param tJogador *x Jogador o qual sera acessado a qtdPokebola
 * @return int referente a quantidade de pokebolas do tJogador
 */
int ReturnqtdPokebola(tJogador *x);

/**
 * @brief Funcao para retornar o nick do tJogadorj
 * @param tJogador *x Jogador o qual sera acessado o nick
 * @return string referente a tJogador
 */
char *ReturnNomeJogador(tJogador *x);

#endif //JOGADOR_H
