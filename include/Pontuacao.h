#ifndef PONTUACAO_H
#define PONTUACAO_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief struct parasalvar a pontuação
 * @var char *nickname nome do jogador
 * @var int partidas partidas vencidas  
 * @var tPontuação *prox apontador para o proximo da lista
 */
typedef struct Pontuacao tPontuacao;

/**
 * @brief Le os jogadores salvos no arquivo
 * @param *caminho caminho para o arquivo de pontuacao
 * @return Uma lista de tPontuacao lido do arquivo
 */
static tPontuacao *LeArquivo(char *caminho);

/**
 * @brief Le o arquivo e imprime o historico salvo
 * @param *caminho Caminho para o arquivo de pontuacao
 */
void imprimePontuacao(char *caminho);

/**
 * @brief Adiciona um novo jogador no arquivo de maneira ordenada
 * @param partidas Quantidade de partidas vencidas
 * @param *nick Nome do jogador a ser salvo
 * @param *caminho Caminho para o arquivo de pontuacao
 */
void addNewPontuacao(int partidas, char *nick, char *caminho);

/**
 * @brief Libera toda a lista de tPontuacao passada
 * @param *x Lista de tPontuacao a ser liberada
 */
static void destroyPontuacao(tPontuacao *x);

/**
 * @brief Salva no arquivo do caminho passado toda a lista
 * @param *x Head da lista a ser salva
 * @param *caminho Caminho para o arquivo a ser salvo a pontuacao
 * @return  
 */
static void salvaPontuacao(tPontuacao *x, char *caminho);

/**
 * @brief Verifica se *le é maior do que *nova se for igual ele verifica de forma alfabetica
 * @param *le Jogardor de referencia
 * @param *nova Jogador verificado se é maior q o outro
 * @return 1 se *le for menor q *nova, 0 caso contrario
 */
static int maiorPontuacao(tPontuacao *le, tPontuacao *nova);

#endif //PONTUACAO_H