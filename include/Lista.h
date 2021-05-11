#ifndef Lista_H
#define Lista_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*freeData)(void *);

typedef struct TipoPoke tTipoPoke;

typedef struct Lista List;
/**
 * @brief Funcao para iniciar a lista
 * @param int tam Tamanho de cada novo pedaco que sera adicionado
 * @param functio funcao para liberar datos
 * @return Lista inicial
 */
List* InitLista(int tam, freeData function);

/**
 * @brief Funcao para liberar a LISTA
 * @param LISTA list que sera liberada
 */
void DestroyLista(List* LISTA);
/**
 * @brief Funcao para inserir um elemento como ultimo da lista
 * @param LISTA list utilizada
 * @param data elemento que sera adicionado a lista
 */
void InserirUlt(List* LISTA, void* data);

/**
 * @brief Funcao para buscar um elemento da lista, retira-lo e retornar
 * @param lista list que sera utilizada
 * @param pos posicao do elemento que sera buscado e removido
 * @return elemento referennte ao int pos
 */
void *BuscaRetorna(List* lista, int pos);
/**
 * @brief Funcao para imprimir os poke iniciais
 * @param x List referente aos pokemons iniciais
 * @return int referente a quantidade de pokemons que foram impressos
 */
int ImprimeLista(List* x);

/**
 * @brief Funcao para liberar e remover o primeiro poke da lista
 * @param x Lista de pokemons que sera utilizada
 */
void RemoveFirst(List *poke);

/**
 * @brief Funcao para retorar o primeiro poke da lista
 * @param x Lista de pokemons que sera utilizada
 */
void *ReturnFirstPoke(List *x);
#endif
