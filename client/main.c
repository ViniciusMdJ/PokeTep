#include "../include/Pokemon.h"

int main(int argc, char *argv[]){
    int n;
    tPokemon* P;

    scanf("%d", &n);
    //getchar();
    P = ListaPoke(n);
    printf("%d\n", ReturnTipo(P));

return 0;
}

