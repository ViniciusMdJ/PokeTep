#include "../include/Batalha.h"
#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"


int batalha(List *ListaJogador){
    static int qtdBatalha = 0;
    int qtdVitorias = 0, pokeBatalhados = 0, ultimaPokebola = 0, UltimoMew = 0;
    float *HpPokeJogador, *HpMaquina;
    *HpMaquina = 0;
    float random;
    tPokemon *maquina, *pokeJogador;
    pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
    HpPokeJogador = ReturnHPatual;
    

    while(pokeJogador != NULL){
        if(*HpMaquina == 0){
            random = CriaAleatorio();
            if(random <= (UltimoMew/128.0)){
                maquina = ListaPoke(5);
                HpMaquina = ReturnHPatual(maquina);
                UltimoMew = 0; 
                printf("gerou o mew\n");
                getchar();
            }
            else{
                maquina = ListaPoke((rand() % 5));
                HpMaquina = ReturnHPatual(maquina);
                printf("gerou %s\n", ReturnNome(maquina));
                UltimoMew++;
                getchar();
            }
        }
        
        while(1){
            //ataque jogador
            //verifica hp dos dois
            //maquina ataca
            //verificar hp dos dois
        }

    }
    return qtdVitorias;
}