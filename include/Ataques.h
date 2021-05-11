#ifndef ATAQUES_H
#define ATAQUES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * @brief Struct para os ataque dos pokemons
 * @var atk Funcao do atauqe naquela posicao
 * @var *nomeAtk String com o nome do ataque daquela posicao
 *  
*/
typedef struct Ataque tAtaque;

/**
 * @brief Ponteiro de funcao para os inicializadores dos tAtaques dos pokemons
*/
typedef tAtaque *(*fptrInicializaPoke)();

/**
 * @brief Calcula o dano que o pokemon 1 q vai dar no pokemon 2
 * @param *poke1 Pokemon que vai dar o dano
 * @param poder Poder do ataque utilizado
 * @param mt Verificador se o ataque é do mesmo tipo que o pokemon que esta utilizando
 * @param *poke2 pokemon que vai levar o dano
 * @return O dano que foi calculado
 */
float CalculaDano(void *poke1, const float poder, float mt, void *poke2);

/**
 * @brief Calcula o modificador do ataque
 * @param mt  Verificador se o ataque é do mesmo tipo que o pokemon que esta utilizando
 * @param relacao Relacao entre o pokemon atacante e o pokemons defensor
 * @return O modificador calculado com possivel critico
 */
float Modificador(float mt, float relacao);

/**
 * @brief Ponteiro de função para os ataques dos pokemons
 * @param *poke1 Pokemons atacante
 * @param *poke2 Pokemons defensor
 */
typedef void (*fptrAtaque)(void *poke1, void *poke2);

/**
 * @brief Funcao de ataque dos pokemons, o pokemon 1 sem é atacante e pokemon 2 é defensor
 * @param *poke1 Pokemon atacante
 * @param *poke2 Pokemon defensor
*/
void ChoquedoTrovao(void *poke1, void *poke2);  //causa dano e tem chance de paralisar o pokemon defensor
void OndadeChoque(void *poke1, void *poke2);    //paralisa o pokemon defensor por 1 rodada
void Bater(void *poke1, void *poke2);           //causa dano no pokemon defensor
void LancaChamas(void *poke1, void *poke2);     //causa dano no pokemon defensor e tem cance de deixar ele queimando
void Dormir(void *poke1, void *poke2);          //o pokemon dorme por duas rodadas e recupera toda vida na proxima rodada
void ArmadeAgua(void *poke1, void *poke2);      //causa dano no pokemon defensor 
void Proteger(void *poke1, void *poke2);        //Protege o pokemon atacante de qualquer dano por uma rodada
void PodeSono (void *poke1, void *poke2);       //Deixa o pokemon defensor dormindo de 1 a 3 turnos
void BombadeSemente(void *poke1, void *poke2);  //causa dano no pokemon defensor 
void DoisGumes(void *poke1, void *poke2);       //causa dano no pokemon defensor e o atacante recebe 1/3 desse dano causado
void RabodeFerro(void *poke1, void *poke2);     //causa dano no pokemon defensor 
void Cavar(void *poke1, void *poke2);           //protege o pokemon do dano causado no proximo turno e da o dano no outro
void Metronomo(void *poke1, void *poke2);       //da muito dano dano no pokemon defensor porem o pokemon atacante perde toda a vida
void AutoDestruir(void *poke1, void *poke2);    //usa qualquer dos um dos outro ataques aleatoriamente
void DanoCavar(void *poke1, void *poke2);       //da o dano do cavar no inimigo

/**
 * @brief Inicializa o vetor com as funçoes para os ataques da dispatch table
 */
void inicializaFptrAtaques();

/**
 * @brief Inicializ o vetor com as funçoes para inicializar o ponteiro de ataque de cada pokemon
 */
void InicializaFptrPokemons();

/**
 * @brief Libera todos os dados do tAtaque
 * @param *x Ponteiro de tAtaque a ser liberado
 */
void DestroytAtaques(tAtaque *x);

/**
 * @brief Retorna o nome do ataque na posicao passada
 * @param *x Ponteiro de ataque
 * @param *pos Posicao do ataque que quer saber o nome deve ser entre 0 e 2
 * @return Uma string com o nome do ataque
 */
char *ReturnNomeAtk(tAtaque *x, int pos);

/**
 * @brief Retorna a funcao para o ataque do tAtaque na posicao passada
 * @param *atak Ponteiro de tAtaque
 * @param pos Posicao do atauqe que equer utilizar entre 0 e 2
 * @return A funcao do ataque
 */
fptrAtaque ReturnMovimento(tAtaque *atak, int pos);

/**
 * @brief Retorna a função para inicializar o ponteiro de tAtaque do pokemon
 * Pré-Condição: O pos tem que ser entre 0 e 5
 * @param pos Posicao do pokemon a ser inicializado
 * @return A funcao que inicializa o ponteiro de tAtaque do pokemon
 */
fptrInicializaPoke ReturnInicializador(int pos);

/**
 * @brief Inicializa o ponteiro de tAtaque do pokemon
 * @return Ponteiro de tAtaque do pokemon
 */
tAtaque *InicializaPikachu();   //Inicializa o pikachu
tAtaque *InicializaCharizard(); //Inicializa o Charizard
tAtaque *InicializaBlastoise(); //Inicializa o Blastoise
tAtaque *InicializaVenusaur();  //Inicializa o Venusaur
tAtaque *InicializaSteelix();   //Inicializa o steelix
tAtaque *InicializaMew();       //Inicializa o Mew
#endif //ATAQUES_H