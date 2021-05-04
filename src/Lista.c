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

List* InitLista(int tam, freeData function) {
	List* LISTA = malloc(sizeof(List));

    LISTA->tamanho = tam;	
	LISTA->primeiro = NULL;
	LISTA->ultimo = NULL;
	LISTA->freeFunc = function;	
	return LISTA;
}


void DestroyLista(List* LISTA) {
	
	while(LISTA->primeiro) {
		tTipoPoke* atual = LISTA->primeiro;
		LISTA->primeiro = atual->prox;
		if (LISTA->freeFunc)
			LISTA->freeFunc(atual->Poke);
		free(atual->Poke);
		free(atual);
	}	
}

void InserirUlt(List* LISTA, void* data) {
	
	
	tTipoPoke * node = calloc(1, sizeof(tTipoPoke));
	if(node == NULL){
		printf("node nulo\n");
	}
	
	node->Poke = calloc(1, LISTA->tamanho);
	if(node->Poke == NULL){
		printf("poke nulo\n");
	}
	
	memcpy(node->Poke, data, LISTA->tamanho);
	node->prox = NULL;
	
	if (!LISTA->primeiro)
		LISTA->primeiro = node;
	
	
	if (LISTA->ultimo)
		LISTA->ultimo->prox = node;
	
	LISTA->ultimo = node;

}

tTipoPoke *BuscaRetorna(List* lista, int pos){
	tTipoPoke *poke, *ant = NULL;
	int i;
	poke = lista->primeiro;
	for(i=0; i<pos-1; i++){
		ant = poke;
		poke = poke->prox;
	}

	if(ant == NULL){
		lista->primeiro = poke->prox;
		poke->prox = NULL;
	}
	else{
		ant = poke->prox;
		poke->prox = NULL;
	}
	
	return poke;
}

void ReturnData(List* x){
	tTipoPoke* poke = x->primeiro;

	while(poke){
		printf("%s\n", ReturnNome(poke->Poke));
		poke = poke->prox;
	}
}
