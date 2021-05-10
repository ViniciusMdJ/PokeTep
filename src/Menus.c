#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"
#include "../include/Batalha.h"

int MenuEscolha(List* Lista){
    char op[128];
    int i;
    int escolha;
    Clean();
    i = ImprimeLista(Lista);

    do{
        printf("Escolha um Pokemon\n");
        scanf("%s", op);
        getchar();//pega o enter que o maldito scanf nao captura
        escolha = VerificaEntre(op, 1, i);
    }while(!escolha);

return escolha;
}

void MenuPrincipal(char* caminhoPontuacao,char* caminhoLogs){
    char aux[128];
    int  opcao, vitoriasPlayer; 
    tJogador *Player;
    List *pokePlayer;
    FILE *arqLogs;
    arqLogs = fopen(caminhoLogs, "w");

    if(arqLogs == NULL){
        printf("Arquivo de Log's nao foi aberto\n");
        exit(1);
    }

    while(1){
        Clean();
        printf("Escolha Uma Opcao\n\n");
        printf("\t1-Jogar\n");
        printf("\t2-Melhores Pontuacoes\n");
        printf("\t3-Sair\n\n\t");
        while(1){
            scanf("%s", aux);
            getchar();//pega o enter que o maldito scanf nao captura        
            opcao = VerificaEntre(aux, 1, 3);
            if(opcao == 1){
                Player = newPlayer();
                vitoriasPlayer = batalha(Player, arqLogs);
                addNewPontuacao(vitoriasPlayer, ReturnNomeJogador(Player), caminhoPontuacao);
                getchar();
                
                destroyJogador(Player);                
                break;
            }
            else if(opcao == 2){
                imprimePontuacao(caminhoPontuacao);
                break;
            }
            else if(opcao == 3){
                Clean();
                fclose(arqLogs);
                return;
            }
            else{
                printf("\tEscolha uma opcao valida\n\t");
            }
        }
    }
}

int MenuBatalha(tPokemon *poke, int qtdPokebola){
    char *op = malloc(sizeof(char) * 129);
    int escolha;

    printf("Escolha um movimento:\n");
    printf("1- %s\n", NomedoAtk(poke, 0));
    printf("2- %s\n", NomedoAtk(poke, 1));
    printf("3- %s\n", NomedoAtk(poke, 2));
    printf("4- Tentar capiturar (%d pokebola)\n", qtdPokebola);
    printf("5- Fugir\n");
    do{
        scanf("%s", op);
        getchar();//pegaro maldito \n q o scan nao le
        escolha = VerificaEntre(op, 1, 5);
        if(escolha == 4 && !qtdPokebola){
            escolha = 0;
        }
        if(escolha == 0){
            printf("Escolha uma opção valida\n");
        }
    }while(!escolha);

    free(op);
    return escolha;
}
