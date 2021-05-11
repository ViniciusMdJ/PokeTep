#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Utilidades.h"
#include "Pokemon.h"

/**
 * @brief Menu para escolha do pokemon inicial 
 * @param *Lista Ponteiro de List com os pokemons inicias
 * @return Retorna o numero do pokemon da lista escolhido 
 */
int MenuEscolha(List* Lista);

/**
 * @brief Menu principal onde comeca tudo
 * @param *arqPontuacao Caminho para o arquivo de pontuacao
 * @param *arqLogs Caminho para o arquivo de Log's
 */
void MenuPrincipal(char* arqPontuacao,char* arqLogs);

/**
 * @brief Menu para escolhas do movimento do jogador na batalha
 * @param *poke Pokemon que vai atacar
 * @param qtdPokebolas Quantidade de pokebolas que estao disponiveis
 * @return Opcao escolhida entre 1 e 5
 */
int MenuBatalha(tPokemon *poke, int qtdPokebola);
#endif
