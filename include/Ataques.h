#ifndef ATAQUES_H
#define ATAQUES_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef void (*fptrAtaque)(void *poke1, float mt, void *poke2);

float CalculaDano(void *poke1, const float poder, float mt, void *poke2);

float Modificador(float mt, float relacao);

void ChoquedoTrovao(void *poke1, float mt, void *poke2);

void OndadeChoque(void *poke1, float mt, void *poke2);

void Bater(void *poke1, float mt, void *poke2);

void LancaChamas(void *poke1, float mt, void *poke2);

void Dormir(void *poke1, float mt, void *poke2);

void ArmadeAgua(void *poke1, float mt, void *poke2);

void Proteger(void *poke1, float mt, void *poke2);

void PodeSono(void *poke1, float mt, void *poke2);

void BombadeSemente(void *poke1, float mt, void *poke2);

void DoisGumes(void *poke1, float mt, void *poke2);

void RabodeFerro(void *poke1, float mt, void *poke2);

void Cavar(void *poke1, float mt, void *poke2);

void Metronomo(void *poke1, float mt, void *poke2);

void AutoDestruir(void *poke1, float mt, void *poke2);

void iniciualizaVetor();

// tAtaque inicializaChoquedoTrovao(float mt);

// tAtaque inicializaOndadeChoque(float mt);

// tAtaque inicializaBater(float mt);

// tAtaque inicializaLancaChamas(float mt);

// tAtaque inicializaDormir(float mt);

// tAtaque inicializaArmadeAgua(float mt);

// tAtaque inicializaProteger(float mt);

// tAtaque inicializaPodeSono(float mt);

// tAtaque inicializaBombadeSemente(float mt);

// tAtaque inicializaDoisGumes(float mt);

// tAtaque inicializaRabodeFerro(float mt);

// tAtaque inicializaCavar(float mt);

// tAtaque inicializaMetronomo(float mt);

// tAtaque inicializaAutoDestruir(float mt);


#endif //ATAQUES_H