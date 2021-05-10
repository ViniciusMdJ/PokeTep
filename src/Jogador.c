#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"


typedef struct jogador{
    char *nickname;
    unsigned int qtdPokebola;
    List *Pokemons; 
}tJogador;

tJogador *newPlayer(){
    tJogador *novo;
    char *nome;
    novo = malloc(sizeof(tJogador));
    nome = malloc(sizeof(char) * 129);

    Clean(); 
    printf("Qual o seu nome?\n");
    while(1){
        fgets(nome, sizeof(char) * 129, stdin);
        nome[strlen(nome) -1] = '\0'; //retirando a quebra de linha que o fgets captura
        if(VerificaNickname(nome)){
            break;
        }
        printf("Digite um nome válido! Somente letras e '_'\n");        
    }

    novo->nickname = strdup(nome);
    novo->qtdPokebola = 3;
    novo->Pokemons = InitIniciais();
    free(nome);
    return novo;
}

static int VerificaNickname(char *nome){
    int i;
    for(i=0; nome[i] != '\0'; i++){
        if(!isalpha(nome[i]) && !(nome[i] == '_')){
            return 0;
        }
    }
    return 1;
}

void destroyJogador(tJogador *x){
    free(x->nickname);
    DestroyLista(x->Pokemons);
    free(x);
}

List *ReturnListaPoke(tJogador *x){
    return x->Pokemons;
}

int ReturnqtdPokebola(tJogador *x){
    return x->qtdPokebola;
}

char *ReturnNomeJogador(tJogador *x){
    return x->nickname;
}