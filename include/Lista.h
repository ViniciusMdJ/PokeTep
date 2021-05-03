#ifndef Lista_H
#define Lista_H

#include <stdio.h>
#include <stdlib.h>
#include "Pokemon.h"
typedef void (*freeData)(void *);


typedef struct TipoPoke tTipoPoke;
typedef struct Lista List;
int InitLista(List* LISTA, int tam, freeData function);

int DestroyLista(List* LISTA);

int InserirUlt(List* LISTA, void* data);

#endif
