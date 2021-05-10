#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Utilidades.h"
#include "Pokemon.h"

int MenuEscolha(List* Lista);

void MenuPrincipal(char* arqPontuacao,char* arqLogs);

int MenuBatalha(tPokemon *poke, int qtdPokebola);
#endif
