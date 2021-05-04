#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"

int MenuEscolha(List* Lista){
    char op[128];
    int i;
    int escolha;
    i = ImprimeLista(Lista);

    do{
        printf("Escolha um Pokemon\n");
        scanf("%s", op);
        escolha = VerificaEntre(op, 1, i);
    }while(!escolha);
return escolha;
}

void MenuPrincipal(char* arqPontuacao,char* arqLogs){
    char aux[128];
    int  opcao; 

    while(1){
        printf("Escolha Uma Opcao\n\n");
        printf("\t1-Jogar\n");
        printf("\t2-Melhores Pontuacoes\n");
        printf("\t3-Sair\n");
        while(1){
            scanf("%s", aux);        
            opcao = VerificaEntre(aux, 1, 3);
            switch (opcao){
                case 1:
                    //funcao logar
                    printf("1\n");
                    break;
                case 2:
                    //funcao pontuao
                    printf("2\n");
                    break;
                case 3:
                    return;
                default:
                    printf("Escolha uma opcao valida\n");
                    break;
            }
        }
    }
}
