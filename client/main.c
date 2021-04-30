#include "../include/Jogador.h"
#include "../include/Pontuacao.h"

int main(int argc, char *argv[]){
    tJogador *player;
    player = newPlayer();
    imprimeJogador(player);

    char caminho[] = "data/pontuacao.txt";
    imprimePontuacao(caminho);
    printf("\n\n");
    //addNewPontuacao(28, "c", caminho);

    destroyJogador(player);



return 0;
}