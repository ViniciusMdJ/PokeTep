#include "../include/Pokemon.h"
#include "../include/Utilidades.h"
#include "../include/Ataques.h"
#include "../include/Pontuacao.h"
#include "../include/Lista.h"
#include "../include/Jogador.h"
#include "../include/Menus.h"
#include <time.h>

int main(int argc, char *argv[]){
    srand(time(0));
    char* CaminhoPont = "data/pontuacao.txt";
    char* CaminhoLogs;


    inicializaFptrAtaques();
    InicializaFptrPokemons();

    MenuPrincipal(CaminhoPont, CaminhoLogs); 
    


return 0;
}

