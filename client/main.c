#include "../include/Jogador.h"
#include "../include/Pontuacao.h"
#include "../include/Utilidades.h"

int main(int argc, char *argv[]){
    tJogador *player;
    player = newPlayer();
    imprimeJogador(player);
    Clean();

    char caminho[] = "data/pontuacao.txt";
    imprimePontuacao(caminho);
    
    //addNewPontuacao(28, "c", caminho);

    destroyJogador(player);



return 0;
}