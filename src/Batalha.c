#include "../include/Batalha.h"
#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"


int batalha(List *ListaJogador, int qtdPokebola){
    static int qtdBatalha = 0;
    qtdBatalha++;
    int qtdVitorias = 0, pokeBatalhados = 0, ultimaPokebola = 0, UltimoMew = 0, opJogador, randMaquina;
    float random, HpMax, aux;
    float *HpPokeJogador, *HpMaquina, i = 0; 
    HpMaquina = &i;

    fptrAtaque AtaquePokemon;

    tPokemon *maquina = NULL, *pokeJogador;
    pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
    HpPokeJogador = ReturnHPatual(pokeJogador);

    

    while(pokeJogador != NULL){
        if(*HpMaquina == 0){
            random = CriaAleatorio();
            if(random <= (UltimoMew/128.0)){
                if(maquina){
                    DestroyPokemon(maquina);
                }
                maquina = ListaPoke(5);
                HpMaquina = ReturnHPatual(maquina);
                UltimoMew = 0;
                ResetaStatus(pokeJogador);
                AumenteHp(pokeJogador, 10);
            }
            else{
                if(maquina){
                    DestroyPokemon(maquina);
                }
                maquina = ListaPoke((rand() % 5));
                HpMaquina = ReturnHPatual(maquina);
                UltimoMew++;
                ResetaStatus(pokeJogador);
                AumenteHp(pokeJogador, 10);
            }
        }
        
        while(1){

            //ataque do Jogador
            if(pokeJogador){//pokemon do jogador nao for nulo
                
                if(Queimando(pokeJogador)){
                    HpMax = ReturnHPmax(pokeJogador);
                    CausarDano(pokeJogador, (HpMax/16.0));
                }
                if(*HpPokeJogador){
                    if(PodeAtacar(pokeJogador)){
                        opJogador = MenuBatalha(pokeJogador, qtdPokebola);
                        if(opJogador == 5){
                            random = CriaAleatorio();
                            if(random <= (1.0/16.0)){
                                *HpMaquina = 0;
                                break;
                            }
                        }
                        else if(opJogador == 4){
                            if(qtdPokebola){
                                HpMax = ReturnHPmax(maquina);
                                aux = (HpMax/ (*HpMaquina)) / 20;
                                random = CriaAleatorio();
                                if(random <= aux){
                                    //chama a funcao de capturar
                                    //adiciona ao final
                                    //da free na maquina e coloca NULL
                                }
                            }
                        }
                        else{
                            if(VerificaAtkDormir(pokeJogador)){
                                AumenteHp(pokeJogador, 99999);
                                DiminuiAtkDormir(pokeJogador);
                            }
                            if(VerificaCavar(pokeJogador)){
                                DanoCavar(pokeJogador, maquina);
                            }
                            AtaquePokemon = MovimentoPokemon(pokeJogador, opJogador-1);
                            AtaquePokemon(pokeJogador, maquina);
                            getchar();
                            printf("\n\n");
                            //chama o log
                        }
                        if(!*HpPokeJogador){
                            RemoveFirst(ListaJogador);
                            pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                            if(pokeJogador){
                                HpPokeJogador = ReturnHPatual(pokeJogador);
                            }
                            break;
                        }
                        if(!*HpMaquina){
                            break;
                        }
                    }
                    else{
                        printf("Jogador paralisado ou dormindo\n");
                    }
                }
                else{
                    break;
                }
            }
            else{
                break;
            }

            DiminuiAtkDormir(maquina);
            DiminuiDormindo(pokeJogador);
            DiminuiImune(pokeJogador);
            DiminuiParalisado(pokeJogador);

            //ataque da maquina
            if(pokeJogador){//pokemon do jogador nao for nulo
                
                if(Queimando(maquina)){
                    HpMax = ReturnHPmax(maquina);
                    CausarDano(maquina, (HpMax/16.0));
                }
                if(*HpMaquina){
                    if(PodeAtacar(maquina)){
                        if(VerificaAtkDormir(maquina)){
                            AumenteHp(maquina, 99999);
                            DiminuiAtkDormir(maquina);
                        }
                        if(VerificaCavar(maquina)){
                            DanoCavar(maquina, pokeJogador);
                        }
                        randMaquina = rand() % 3;
                        AtaquePokemon = MovimentoPokemon(maquina, randMaquina);
                        AtaquePokemon(maquina, pokeJogador);
                        getchar();
                        printf("\n\n");
                        //chama o log
                    }
                    else{
                        printf("Maquina paralisada ou dormindo\n");
                    }
                }
                else{
                    break;
                }

                if(!*HpPokeJogador){
                    RemoveFirst(ListaJogador);
                    pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                    if(pokeJogador){
                        HpPokeJogador = ReturnHPatual(pokeJogador);
                    }
                    break;
                }
                if(!*HpMaquina){
                    break;
                }
            }
            else{
                break;
            }
            DiminuiAtkDormir(pokeJogador);
            DiminuiDormindo(maquina);
            DiminuiImune(maquina);
            DiminuiParalisado(maquina);
        }

    }
    return qtdVitorias;
}