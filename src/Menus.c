#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"

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

void MenuPrincipal(char* arqPontuacao,char* arqLogs){
    char aux[128];
    int  opcao; 
    tJogador *Player;

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
                destroyJogador(Player);
                break;
            }
            else if(opcao == 2){
                imprimePontuacao(arqPontuacao);
                break;
            }
            else if(opcao == 3){
                Clean();
                return;
            }
            else{
                printf("\tEscolha uma opcao valida\n\t");
            }
        }
    }
}
