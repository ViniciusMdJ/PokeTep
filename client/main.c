#include "../include/Pokemon.h"
#include "../include/Utilidades.h"
#include "../include/Ataques.h"
#include "../include/Pontuacao.h"
#include "../include/Lista.h"
#include "../include/Jogador.h"

int main(int argc, char *argv[]){
    int n;
    tPokemon* P;

    scanf("%d", &n);
    //getchar();
    P = ListaPoke(n);
    printf("%d\n", ReturnTipo(P));

return 0;
}

