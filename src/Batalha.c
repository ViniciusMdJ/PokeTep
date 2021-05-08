#include "../include/Batalha.h"
#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"


int batalha(tJogador *player){
    int qtdPokebola = ReturnqtdPokebola(player);
    List *ListaJogador = ReturnListaPoke(player);
    char *NomePlayer = ReturnNomeJogador(player);
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

    
    printf("A batalha comecou!\n\n");
    while(pokeJogador != NULL){
        if(*HpMaquina == 0){
            random = CriaAleatorio();
            if(random <= (UltimoMew/128.0)){
                printf("Um Mew selvagem apareceu!\n\n");

                maquina = ListaPoke(5);
                HpMaquina = ReturnHPatual(maquina);
                UltimoMew = 0;
                ResetaStatus(pokeJogador);
                AumenteHp(pokeJogador, 10);
            }
            else{
            
                maquina = ListaPoke((rand() % 5));
                HpMaquina = ReturnHPatual(maquina);
                UltimoMew++;
                ResetaStatus(pokeJogador);
                AumenteHp(pokeJogador, 10);

                printf("Um %s selvagem apareceu!\n\n", ReturnNome(maquina));
            }
        }
        
        while(1){

            //ataque do Jogador
            if(pokeJogador){//pokemon do jogador nao for nulo
                
                if(VerificaCavar(pokeJogador)){
                   DanoCavar(pokeJogador, maquina);
                }

                if(Queimando(pokeJogador)){
                    HpMax = ReturnHPmax(pokeJogador);
                    CausarDano(pokeJogador, (HpMax/16.0));
                }

                if((*HpPokeJogador) > 0){
                    if(PodeAtacar(pokeJogador)){
                        opJogador = MenuBatalha(pokeJogador, qtdPokebola);
                        if(opJogador == 5){
                            printf("Tentativa de fugir\n");
                            random = CriaAleatorio();
                            if(random <= (1.0/16.0)){
                                HpMaquina = &i;
                                printf("Sucesso\n\n");
                                getchar();
                                DestroyPokemon(maquina);
                                free(maquina);
                                break;
                            }
                            printf("Fracasso\n\n");
                            getchar();
                        }

                        else if(opJogador == 4){
                            if(qtdPokebola){
                                printf("Tentativa de captura\n");
                                HpMax = ReturnHPmax(maquina);
                                aux = (HpMax/ (*HpMaquina)) / 20;
                                random = CriaAleatorio();
                                if(random <= aux){
                                    printf("Sucesso\n\n");
                                    Capturar(ListaJogador, maquina);
                                    maquina = NULL;
                                    HpMaquina = &i;
                                    qtdPokebola--;
                                    qtdVitorias++;
                                    getchar();
                                    break;
                                }
                                else{
                                    printf("Fracasso\n\n");
                                    qtdPokebola--;
                                    getchar();
                                }                                
                            }
                        }

                        else{
                            if(VerificaAtkDormir(pokeJogador)){
                                AumenteHp(pokeJogador, 99999);
                                DiminuiAtkDormir(pokeJogador);
                            }
                            
                            AtaquePokemon = MovimentoPokemon(pokeJogador, opJogador-1);
                            AtaquePokemon(pokeJogador, maquina);
                            DadosAtaqueJogador(pokeJogador, maquina, opJogador-1);
                        }

                        if((*HpPokeJogador) == 0){
                            RemoveFirst(ListaJogador);
                            pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                            if(pokeJogador){
                                HpPokeJogador = ReturnHPatual(pokeJogador);
                            }
                            break;
                        }
                        if((*HpMaquina) == 0){
                            printf("%s vence!\n\n", NomePlayer);
                            qtdVitorias++;
                            DestroyPokemon(maquina);
                            free(maquina);
                            HpMaquina = &i;
                            break;
                        }
                    }
                    else{
                        printf("Jogador paralisado ou dormindo\n\n");
                    }
                }
                else{
                    //Vida do pokeJogador = 0
                    printf("%s foi desmaiado!\n\n", ReturnNome(pokeJogador));
                    getchar();
                    RemoveFirst(ListaJogador);
                    pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                    if(pokeJogador){
                        HpPokeJogador = ReturnHPatual(pokeJogador);
                        printf("Agora voce esta batalhando com %s\n\n", ReturnNome(pokeJogador));
                        getchar();
                    }
                    break;
                }
            }
            else{
                //pokeJogador= NULL
                break;
            }

            if((*HpPokeJogador) == 0){
                printf("%s foi desmaiado!\n\n", ReturnNome(pokeJogador));
                getchar();
                RemoveFirst(ListaJogador);
                pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                if(pokeJogador){
                    HpPokeJogador = ReturnHPatual(pokeJogador);
                    printf("Agora voce esta batalhando com %s\n\n", ReturnNome(pokeJogador));
                    getchar();
                }
                break;
            }

            DiminuiAtkDormir(maquina);
            DiminuiDormindo(pokeJogador);
            DiminuiImune(pokeJogador);
            DiminuiParalisado(pokeJogador);

            //ataque da maquina
            if(pokeJogador){//pokemon do jogador nao for nulo
                
                if(VerificaCavar(maquina)){
                    DanoCavar(maquina, pokeJogador);
                }

                if(Queimando(maquina)){
                    HpMax = ReturnHPmax(maquina);
                    CausarDano(maquina, (HpMax/16.0));
                }
                if((*HpMaquina) > 0){
                    if(PodeAtacar(maquina)){
                        if(VerificaAtkDormir(maquina)){
                            AumenteHp(maquina, 99999);
                            DiminuiAtkDormir(maquina);
                        }
                    
                        randMaquina = rand() % 3;
                        AtaquePokemon = MovimentoPokemon(maquina, randMaquina);
                        AtaquePokemon(maquina, pokeJogador);
                        DadosAtaqueMaquina(maquina, pokeJogador, randMaquina);
                        //getchar();
                        //printf("\n\n");
                        //chama o log
                    }
                    else{
                        printf("Maquina paralisada ou dormindo\n\n");
                        getchar();
                    }
                }
                else{
                    printf("%s vence!\n\n", NomePlayer);
                    qtdVitorias++;
                    DestroyPokemon(maquina);
                    free(maquina);
                    HpMaquina = &i;
                    getchar();
                    break;
                }

                if((*HpPokeJogador) == 0){
                    printf("%s foi desmaiado!\n\n", ReturnNome(pokeJogador));
                    getchar();
                    RemoveFirst(ListaJogador);
                    pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                    if(pokeJogador){
                        HpPokeJogador = ReturnHPatual(pokeJogador);
                        printf("Agora voce esta batalhando com %s\n\n", ReturnNome(pokeJogador));
                        getchar();
                    }
                    break;
                }
                if((*HpMaquina) == 0){
                    printf("%s vence!\n\n", NomePlayer);
                    qtdVitorias++;
                    DestroyPokemon(maquina);
                    free(maquina);
                    HpMaquina = &i;
                    getchar();
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
    DestroyPokemon(maquina);
    free(maquina);
    printf("A batalha terminou! %s conseguiu %d vitorias\n\n", NomePlayer, qtdVitorias);
    getchar();
    return qtdVitorias;
}

void DadosAtaqueJogador(tPokemon *poke1, tPokemon *poke2, int pos){
    float Hpmax, *Hpatual, por100;
    char *pokeJogador, *pokeMaquina, *nomeAtk;
    int dormindo, queimando, paralisado;

    pokeJogador = ReturnNome(poke1);
    pokeMaquina = ReturnNome(poke2);
    nomeAtk = NomedoAtk(poke1, pos);

    printf("%s usa %s\n", pokeJogador, nomeAtk);
    Hpmax = ReturnHPmax(poke1);
    Hpatual = ReturnHPatual(poke1);
    por100 = (*Hpatual/Hpmax) * 100;
    printf("%s: %.0f%% HP", pokeJogador, por100);
    queimando = Queimando(poke1);
    dormindo  = VerificaDormindo(poke1);
    paralisado = VerificaParalisado(poke1);
    PrintaStatus(paralisado, dormindo, queimando); 

    Hpmax = ReturnHPmax(poke2);
    Hpatual = ReturnHPatual(poke2);
    por100 = (*Hpatual/Hpmax) * 100;
    printf("%s: %.0f%% HP", pokeMaquina, por100);
    queimando = Queimando(poke2);
    dormindo  = VerificaDormindo(poke2);
    paralisado = VerificaParalisado(poke2);
    PrintaStatus(paralisado, dormindo, queimando);
    printf("\n");
    getchar();
}

void DadosAtaqueMaquina(tPokemon *poke1, tPokemon *poke2, int pos){
    float Hpmax, *Hpatual, por100;
    char *pokeJogador, *pokeMaquina, *nomeAtk;
    int dormindo, queimando, paralisado;

    pokeJogador = ReturnNome(poke2);
    pokeMaquina = ReturnNome(poke1);
    nomeAtk = NomedoAtk(poke1, pos);

    printf("%s usa %s\n", pokeMaquina, nomeAtk);
    Hpmax = ReturnHPmax(poke2);
    Hpatual = ReturnHPatual(poke2);
    por100 = (*Hpatual/Hpmax) * 100;
    printf("%s: %.0f%% HP ", pokeJogador, por100);

    queimando = Queimando(poke2);
    dormindo  = VerificaDormindo(poke2);
    paralisado = VerificaParalisado(poke2);
    PrintaStatus(paralisado, dormindo, queimando);    
    

    Hpmax = ReturnHPmax(poke1);
    Hpatual = ReturnHPatual(poke1);
    por100 = (*Hpatual/Hpmax) * 100;
    printf("%s: %.0f%% HP ", pokeMaquina, por100);

    queimando = Queimando(poke1);
    dormindo  = VerificaDormindo(poke1);
    paralisado = VerificaParalisado(poke1);
    PrintaStatus(paralisado, dormindo, queimando); 
    printf("\n"); 
    getchar();
}

void PrintaStatus(int p, int d, int q){
    if(!p && !d && !q){printf("\n");}
    else if(p && !d && !q){printf("(paralisado)\n");}
    else if(!p && d && !q){printf("(dormindo)\n");}
    else if(!p && !d && q){printf("(queimando)\n");}
    else if(p && !d && q){printf("(paralisado, queimando)\n");}
    else if(p && d && !q){printf("(paralisado, dormindo)\n");}
    else if(!p && d && q){printf("(dormindo, queimando)\n");}
    else if(p && d && q){printf("(paralisado, dormindo, queimando)\n");}
}