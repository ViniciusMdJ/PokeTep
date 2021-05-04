#ifndef Lista_H
#define Lista_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*freeData)(void *);

typedef struct TipoPoke tTipoPoke;

typedef struct Lista List;

List* InitLista(int tam, freeData function);

void DestroyLista(List* LISTA);

void InserirUlt(List* LISTA, void* data);

void *BuscaRetorna(List* lista, int pos);

void ImprimeLista(List* x);

#endif
