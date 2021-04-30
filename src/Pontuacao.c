#include "../include/Pontuacao.h"


typedef struct Pontuacao{
    char *nickname;
    int partidas;
    tPontuacao *prox;
}tPontuacao;

static tPontuacao *LeArquivo(char *caminho){

    tPontuacao *head, *lida, *anterior;
    head = calloc(1, sizeof(tPontuacao));
    head->prox = NULL;

    FILE *arq = fopen(caminho, "r");

    if(arq == NULL){
        return head;
    }

    const int tam = 129;
    char *linha, *token;

    linha = malloc(sizeof(char) * tam);
    anterior = head;
    while(fgets(linha, tam, arq)){
        lida = calloc(1, sizeof(tPontuacao));
        token = strtok(linha, " ");
        lida->nickname = strdup(token);
        token = strtok(NULL, "\n");
        lida->partidas = atoi(token);
        lida->prox = NULL;
        anterior->prox = lida;
        anterior = lida;

    }

    free(linha);
    fclose(arq);
    return head;
}

void imprimePontuacao(char *caminho){
    FILE *arq;
    arq = fopen(caminho, "r");

    if(arq == NULL){
        printf("Nenhum historico de pontuação existente neste arquivo\n");
        getchar();
        return;
    }

    tPontuacao *next, *lista = LeArquivo(caminho);
    int i=1;

    for(next = lista->prox; next != NULL; next = next->prox){
        printf("%d- %s: %d\n", i, next->nickname, next->partidas);
        i++;
    }

    fclose(arq);
    destroyPontuacao(lista);
    getchar();
}

static void destroyPontuacao(tPontuacao *x){
    tPontuacao *next;
    next = x->prox;
    free(x);
    while(next != NULL){
        x = next;
        next = next->prox;
        free(x->nickname);
        free(x);
    }
}

void addNewPontuacao(int partidas, char *nick, char *caminho){
    tPontuacao *lista = LeArquivo(caminho);

    tPontuacao *ant, *next, *novo = calloc(1, sizeof(tPontuacao));
    novo->nickname = strdup(nick);
    novo->partidas = partidas;

    ant = lista;
    next = lista->prox;
    while(next != NULL && !maiorPontuacao(next, novo)){
        ant = next;
        next = next->prox;
    }

    novo->prox = next;
    ant->prox = novo;

    salvaPontuacao(lista, caminho);
    imprimePontuacao(caminho);
    destroyPontuacao(lista);

}

static void salvaPontuacao(tPontuacao *x, char *caminho){
    FILE *arq = fopen(caminho, "w");

    tPontuacao *next;

    for(next = x->prox; next != NULL; next = next->prox){
        fprintf(arq, "%s %d\n", next->nickname, next->partidas);
    }

    fclose(arq);
}

static int maiorPontuacao(tPontuacao *le, tPontuacao *nova){
    if(le->partidas < nova->partidas){
        return 1;
    }
    else if(le->partidas == nova->partidas){
        if(strcmp(le->nickname, nova->nickname) > 0){
            return 1;
        }
    }
    return 0;
}