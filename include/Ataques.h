#ifndef ATAQUES_H
#define ATAQUES_H

#include "Pokemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


Dano = ((14*poder*A/D)/50 + 2) * modificador
modificador = critico*MT*tipo
float Dano(tPokemon *atacante, int poder, float chance, tPokemon *defensor);

float Modificador(float mt, float chance, float relacao);

void ChoquedoTrovao(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void OndadeChoque(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void Bater(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void LancaChamas(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void Dormir(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void ArmadeAgua(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void Proteger(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void PodeSono(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void BombadeSemente(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void DoisGumes(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void RabodeFerro(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void Cavar(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void Metronomo(tPokemon *atacante, int pos, float chance, tPokemon *defensor);

void AutoDestruir(tPokemon *atacante, int pos, float chance, tPokemon *defensor);


#endif //ATAQUES_H