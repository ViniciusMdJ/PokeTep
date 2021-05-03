#include "../include/Pokemon.h"

int main(int argc, char *argv[]){
    tPokemon* Lista;
    Lista = FillPoke();
    for(int i = 0; i < 6; i++){
        printf("%d\n", ReturnTipo(Lista, i));
    }

return 0;
}
