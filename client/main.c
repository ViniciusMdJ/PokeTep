#include "../include/Pokemon.h"
#include "../include/Utilidades.h"
#include "../include/Ataques.h"
#include "../include/Pontuacao.h"
#include "../include/Lista.h"
#include "../include/Jogador.h"
#include "../include/Menus.h"
#include <time.h>

int main(int argc, char *argv[]){
    
    char* CaminhoPont = strdup(argv[1]);
    char* CaminhoLogs = strdup(argv[2]);
    int semente = atoi(argv[3]);
    srand(semente);


    inicializaFptrAtaques();
    InicializaFptrPokemons();

    MenuPrincipal(CaminhoPont, CaminhoLogs);

    free(CaminhoPont);
    free(CaminhoLogs);



return 0;
}

