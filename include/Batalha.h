#ifndef BATALHA_H
#define BATALHA_H

#include "Pokemon.h"
#include "Lista.h"
#include "Jogador.h"

/**
 * @brief Batalha entre os pokemons do jogador e os aleatorios gerados
 * @param *player Struct com todos os dados do jogador 
 * @param *arqLog Ponteiro do arquivo de log ja aberto
 * @return Retorna a quantidade de vitorias que o jogador conseguiu
 */
int batalha(tJogador *player, FILE *arqLog);

/**
 * @brief Imprime as vidas e status dos pokemons quando o Jogador ataca
 * @param *poke1 Pokemon do jogador
 * @param *poke2 Pokemon da maquina
 * @param pos Posicao do ataque que foi usado
 */
void DadosAtaqueJogador(tPokemon *poke1, tPokemon *poke2, int pos);

/**
 * @briefImprime as vidas e status do pokemons quando a maquina ataca
 * @param *poke1 Pokemon da maquina
 * @param *poke2 Pokemon do jogador
 * @param pos Posicao do ataque que foi usado
 */
void DadosAtaqueMaquina(tPokemon *poke1, tPokemon *poke2, int pos);

/**
 * @brief Verifica quais status estao ativo e imprime 
 * @param p Paralisado
 * @param d Dormindo
 * @param q Queimando
 */
void PrintaStatus(int p, int d, int q);

/**
 * @briefImprime no arquivo de Log a vida e os status dos pokemons
 * @param *arqLog Arquivo de log
 * @param *poke1 Pokemon do jogador
 * @param *poke2 Pokemon da maquina
 * @param pos Posicao do ataque que foi usado
 */
void LogAtaqueJogador(FILE *arqLog, tPokemon *poke1, tPokemon *poke2, int pos);

/**
 * @brief Imprime no arquivo de Log a vida e os status do pokemons
 * @param *arqLog Arquivo de log
 * @param *poke1 Pokemon do maquina
 * @param *poke2 Pokemon da jogador
 * @param pos Posicao do ataque que foi usado  
 */
void LogAtaqueMaquina(FILE *arqLog, tPokemon *poke1, tPokemon *poke2, int pos);

/**
 * @brief Verifica quais status estao ativo e imprime no arquivo passado 
 * @param *arqLog Arquivo para ser impresso
 * @param p Paralisado
 * @param d Dormindo
 * @param q Queimando  
 */
void LogStatus(FILE *arqLog,int p, int d, int q);

/**
 * @brief Imprime no arquivo de log a Tentativa de captura
 * @param *arqLog Arquivo para ser impresso
 * @param tentativa 0 se for fracasso ou 1 para sucesso
 */
void LogCaptura(FILE *arqLog, int tentativa);

/**
 * @brief Imprime no arquivo de Log a tentativa de fuga
 * @param *arqLog Arquivo para ser impresso
 * @param tentativa 0 se for fracasso ou 1 para sucesso
 */
void LogFugir(FILE *arqLog, int tentativa);
#endif //BATALHA_H