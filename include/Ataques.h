#ifndef ATAQUES_H
#define ATAQUES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Ataque tAtaque;

typedef void (*fptrAtaque)(void *poke1, void *poke2);

typedef tAtaque *(*fptrInicializaPoke)();

float CalculaDano(void *poke1, const float poder, float mt, void *poke2);

float Modificador(float mt, float relacao);

void ChoquedoTrovao(void *poke1, void *poke2);

void OndadeChoque(void *poke1, void *poke2);

void Bater(void *poke1, void *poke2);

void LancaChamas(void *poke1, void *poke2);

void Dormir(void *poke1, void *poke2);

void ArmadeAgua(void *poke1, void *poke2);

void Proteger(void *poke1, void *poke2);

void PodeSono (void *poke1, void *poke2);

void BombadeSemente(void *poke1, void *poke2);

void DoisGumes(void *poke1, void *poke2);

void RabodeFerro(void *poke1, void *poke2);

void Cavar(void *poke1, void *poke2);

void Metronomo(void *poke1, void *poke2);

void AutoDestruir(void *poke1, void *poke2);

void iniciualizaFptrAtaques();

void InicializaFptrPokemons();

void DestroytAtaques(tAtaque *x);

fptrInicializaPoke ReturnInicializador(int pos);

fptrAtaque ReturnMovimento(tAtaque *atak, int pos);

tAtaque *InicializaPikachu();

tAtaque *InicializaCharizard();

tAtaque *InicializaBlastoise();

tAtaque *InicializaVenusaur();

tAtaque *InicializaSteelix();

tAtaque *InicializaMew();

#endif //ATAQUES_H