#include "../include/Jogador.h"


typedef struct jogador{
    char *nickname;
    unsigned int qtdPokemon;
    unsigned int qtdPokebola;
    unsigned int vitorias;
    //pokemons
}tJogador;

void imprimeJogador(tJogador *x){
    printf("nick: %s\nqtdpokemon: %d\nqtdpokebola: %d\nvitorias: %d\n", x->nickname, x->qtdPokemon, x->qtdPokebola, x->vitorias);
}

tJogador *newPlayer(){
    tJogador *novo;
    char *nome;
    novo = malloc(sizeof(tJogador));
    nome = malloc(sizeof(char) * 129);
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
    novo->qtdPokemon = 0;
    novo->vitorias = 0;
    //novo.pokemon = NULL ou
    //chama a função para escolher os pokemons aqui
    

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
    //destroyPokemon
    free(x);
}