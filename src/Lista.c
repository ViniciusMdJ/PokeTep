#include "../include/Lista.h"
#include "../include/Pokemon.h"

typedef struct TipoPoke {
	tPokemon* Poke;			// Ponteiro para pokemon
	struct TipoPoke* prox;	// Ponteiro para o proximo item
} tTipoPoke;

typedef struct Lista{
	tTipoPoke* primeiro; 			// Ponteiro para o primeiro
	tTipoPoke* ultimo;			// Ponteiro para o ultimo
	freeData freeFunc;		// Ponteiro para funcao free
    int tamanho;
} List;

int InitLista(List* LISTA,int tam, freeData function) {
	
    LISTA->tamanho = tam;	
	LISTA->primeiro = NULL;
	LISTA->ultimo = NULL;
	LISTA->freeFunc = function;
	
	return 0;
	
}


int DestroyLista(List* LISTA) {
	
	while(LISTA->primeiro) {
		tTipoPoke* atual = LISTA->primeiro;
		LISTA->primeiro = atual->prox;
		if (LISTA->freeFunc)
			LISTA->freeFunc(atual->Poke);
		free(atual->Poke);
		free(atual);
	}
	
	return 0;
	
}

int InserirUlt(List* LISTA, void* data) {
	
	
	tTipoPoke * node = calloc(1, sizeof(tTipoPoke));
	
	node->Poke = calloc(1, LISTA->tamanho);
	
	memcpy(node->Poke, data, LISTA->tamanho);
	node->prox = NULL;
	
	if (!LISTA->primeiro)
		LISTA->primeiro = node;
	
	
	if (LISTA->ultimo)
		LISTA->ultimo->prox = node;
	
	LISTA->ultimo = node;
	
	return 0;
	
}
