#ifndef POKEMON_H
#define POKEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Ataques.h"

enum TipoP{fogo, agua, planta, eletrico, psiquico, metal, normal};

typedef struct pokemon tPokemon;

/**
 * @brief Libera as variaveis alocadas dentro do Pokemon
 * @param void* Pokemon Ponteiro para struct pokemon que passara por casting
 */
void DestroyPokemon(void* Pokemon);

/**
 * @brief Retorna o pokemon correspondente ao inteiro passado
 * @param int i numero do pokemon que sera criado
 * @return Struct tPokemon
 */
tPokemon *ListaPoke(int i);

/**
 * @brief Retorna o Nome do Pokemon
 * @param *tPokemon ponteiro para um struct tPokemon
 * @return Nome do Pokemon
 */
char* ReturnNome(tPokemon* Poke);

/**
 * @brief Retorna o Ataque do Pokemon
 * @param *tPokemon ponteiro para um struct tPokemon
 * @return Ataque do Pokemon
 */
float ReturnAtaque(tPokemon* Poke);

/**
 * @brief Retorna a Defesa do Pokemon
 * @param *tPokemon ponteiro para um struct tPokemon
 * @return Defesa do Pokemon
 */
float ReturnDefesa(tPokemon* Poke);

/**
 * @brief Retorna o HPmax do Pokemon
 * @param *tPokemon ponteiro para um struct tPokemon
 * @return HPmax do Pokemon
 */
float ReturnHPmax(tPokemon* Poke);

/**
 * @brief Retorna o HPatual do Pokemon
 * @param *tPokemon ponteiro para um struct tPokemon
 * @return HPatual do Pokemon
 */
float* ReturnHPatual(tPokemon* Poke);

/**
 * @brief Retorna o tipo do Pokemon
 * @param *tPokemon ponteiro para um struct tPokemon
 * @return tipo do Pokemon
 */
int ReturnTipo(tPokemon* Poke);

/**
 * @brief Chama a funcao para escolha dos iniciais e retorna a lista dos escolhidos
 * @return Lista com os pokemons iniciais
 */
List* InitIniciais();

/**
 * @brief Ponteiro de Funcao referente as funcoes de ataque
 * @param tPokemon* ponteiro para struct tPokemon
 * @param int pos inteiro referente ao ataque
 * @return
 */
fptrAtaque MovimentoPokemon(tPokemon *poke, int pos);

/**
 * @brief Funcao que modifica o HPatual do pokemon
 * @param tPokemon* ponteiro para struct tPokemon
 * @param float dano float referente ao dano que sera causado
 */
void CausarDano(tPokemon *poke, float dano);

/**
 * @param tPokemon* ponteiro para struct tPokemon
 * @param tPokemon* ponteiro para struct tPokemon
 * @return inteiro referente a relacao entre os dois pokes dentro da matriz
 */
float VerificaRelacao(tPokemon *poke1, tPokemon *poke2);

/**
 * @brief Retorna os staros do pokemon para o padrao
 * @param tPokemon* ponteiro para struct tPokemon
 */
void ResetaStatus(tPokemon *poke);

/**
 * @brief Funcao que modifica o HPatual do pokemon
 * @param tPokemon* ponteiro para struct tPokemon
 * @param float qtd float referente ao HP que sera restaurado
 */
void AumenteHp(tPokemon *poke, float qtd);

/**
 * @brief Funcao para retornar o nome do ataque
 * @param tPokemon* ponteiro para struct tPokemon
 * @param int pos inteiro referente ao ataque
 * @return Nome do ataque
 */
char *NomedoAtk(tPokemon *poke, int pos);

/**
 * @brief Verifica se o pokemon pode atacar
 * @param tPokemon* ponteiro para struct tPokemon
 * @return 1 caso o pokemon possa atacar e 0 caso contrario
 */
int PodeAtacar(tPokemon *poke);

/**
 * @brief Verifica o status queimando do poke
 * @param tPokemon* ponteiro para struct tPokemon
 * @return 1 caso o status seja positivo e 0 caso contrario
 */
int Queimando(tPokemon *poke);

/**
 * @brief Verifica o status Dormindo e diminui caso > 0
 * @param tPokemon* ponteiro para struct tPokemon
 */
void DiminuiDormindo(tPokemon *x);

/**
 * @brief Verifica o status Paralisado e diminui caso > 0
 * @param tPokemon* ponteiro para struct tPokemon
 */
void DiminuiParalisado(tPokemon *x);

/**
 * @brief Verifica o status Imune e diminui caso > 0
 * @param tPokemon* ponteiro para struct tPokemon
 */
void DiminuiImune(tPokemon *x);

/**
 * @brief Verifica o status AtkDormir e diminui caso > -1
 * @param tPokemon* ponteiro para struct tPokemon
 */
void DiminuiAtkDormir(tPokemon *x);

/**
 * @brief Verifica o status Cavar e diminui caso > 0
 * @param tPokemon* ponteiro para struct tPokemon
 */
void DiminuiCavar(tPokemon *poke);

/**
 * @brief Muda o status queimando para 1 caso o poke nao seja do tipo fogo
 * @param tPokemon* ponteiro para struct tPokemon
 */
void Queimar(tPokemon *x);

/**
 * @brief Muda o status Dormindo para x caso Dormindo seja < x
 * @param int x inteiro referente ao numero de turnos para dormir
 * @param tPokemon* ponteiro para struct tPokemon
 */
void SetDormindo(tPokemon *poke, int x);

/**
 * @brief Muda o status Paralisado para x caso Paralisado seja < x
 * @param int x inteiro referente ao numero de turnos para paralisar
 * @param tPokemon* ponteiro para struct tPokemon
 */
void SetParalisado(tPokemon *poke, int x);

/**
 * @brief Muda o status Imune para x caso Imune seja < x
 * @param int x inteiro referente ao numero de turnos para imunizar
 * @param tPokemon* ponteiro para struct tPokemon
 */
void SetImune(tPokemon *poke, int x);

/**
 * @brief Muda o status AtkDormir para x caso AtkDormir seja < x
 * @param int x inteiro referente ao numero de turnos para dormir
 * @param tPokemon* ponteiro para struct tPokemon
 */
void SetAtkDormir(tPokemon *poke, int x);

/**
 * @brief Verifica o valor de AtkDormir
 * @param tPokemon* ponteiro para struct tPokemon
 * @return 1 caso atkdormir == 0 e 0 caso contrario
 */
int VerificaAtkDormir(tPokemon *x);

/**
 * @brief Verifica o valor de cavar
 * @param tPokemon* ponteiro para struct tPokemon
 * @return 1 caso cavar == 1 e 0 caso contrario
 */
int VerificaCavar(tPokemon *x);

/**
 * @brief Verifica o valor de imune
 * @param tPokemon* ponteiro para struct tPokemon
 * @return 1 caso imune == 1 e 0 caso contrario
 */
int VerificaImune(tPokemon *x);

/**
 * @brief Verifica o valor de Paralisado
 * @param tPokemon* ponteiro para struct tPokemon
 * @return 1 caso o poke esteja paralisado e 0 caso contrario
 */
int VerificaParalisado(tPokemon *x);

/**
 * @brief Verifica o valor de dormindo ou atakDormir
 * @param tPokemon* ponteiro para struct tPokemon
 * @return 1 caso o poke esteja dormindo e 0 caso contrario
 */
int VerificaDormindo(tPokemon *x);

/**
 * @brief Muda o status cavar para 1
 * @param tPokemon* ponteiro para struct tPokemon
 */
void Cavou(tPokemon *x);

/**
 * @brief Muda o os statatus do poke capturado e insere como ultimo na lista
 * @param tPokemon* ponteiro para struct tPokemon
 * @param List* Lista atual dos pokemons do jogador
 */
void Capturar(List *Pokemons, tPokemon *capturado);
#endif
