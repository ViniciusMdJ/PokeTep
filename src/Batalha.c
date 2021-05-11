#include "../include/Batalha.h"
#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"


int batalha(tJogador *player, FILE *arqLog){

    int qtdPokebola = ReturnqtdPokebola(player);
    List *ListaJogador = ReturnListaPoke(player);
    char *NomePlayer = ReturnNomeJogador(player);
    static int qtdPartida = 0;
    qtdPartida++;
    int qtdVitorias = 0, numBatalhas = 1, ultimaPokebola = 0, UltimoMew = 0, opJogador, randMaquina;
    float random, HpMax, aux;
    float *HpPokeJogador, *HpMaquina, i = 0; 
    //ele recebe o endereco de i para nao dar acesso indevido quando liberamos
    //a maquina e ja sabemos que o valor da vida da maquina é = 0
    HpMaquina = &i;
    
    fptrAtaque AtaquePokemon;

    tPokemon *maquina = NULL, *pokeJogador;
    pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
    HpPokeJogador = ReturnHPatual(pokeJogador);

    Clean();
    printf("A batalha comecou!\n\n");
    while(pokeJogador != NULL){
        if(*HpMaquina == 0){
            if(maquina != NULL){
                DestroyPokemon(maquina);
                free(maquina);
            }
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
            printf("%s vs %s\n\n", ReturnNome(pokeJogador), ReturnNome(maquina));
            getchar();
        }

        
        fprintf(arqLog, "%d.%d- %s vs %s\n", qtdPartida, numBatalhas, ReturnNome(pokeJogador), ReturnNome(maquina));

        while(1){
            Clean();

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
                        Clean();
                        if(opJogador == 5){
                            printf("Tentativa de fugir\n");
                            random = CriaAleatorio();
                            if(random <= (1.0/16.0)){
                                LogFugir(arqLog, 1);
                                HpMaquina = &i;
                                printf("Sucesso\n\n");
                                getchar();
                                break;
                            }
                            LogFugir(arqLog, 0);
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
                                    LogCaptura(arqLog, 1);
                                    printf("Sucesso\n\n");
                                    Capturar(ListaJogador, maquina);
                                    maquina = NULL;
                                    HpMaquina = &i;
                                    qtdPokebola--;
                                    qtdVitorias++;
                                    random = CriaAleatorio();
                                    if(random <= (ultimaPokebola/12.0)){
                                        qtdPokebola++;
                                        ultimaPokebola = 0;
                                    }
                                    else{
                                        ultimaPokebola++;
                                    }
                                    getchar();
                                    break;
                                }
                                else{
                                    LogCaptura(arqLog, 0);
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
                            LogAtaqueJogador(arqLog, pokeJogador, maquina, opJogador-1);
                        }

                        if((*HpPokeJogador) == 0){
                            printf("%s foi desmaiado!\n\n", ReturnNome(pokeJogador));
                            fprintf(arqLog, "\t%s perde!\n\n", NomePlayer);
                            numBatalhas++;
                            getchar();
                            RemoveFirst(ListaJogador);
                            pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                            ResetaStatus(maquina);
                            if(pokeJogador){
                                HpPokeJogador = ReturnHPatual(pokeJogador);
                                printf("Agora voce esta batalhando com %s\n\n", ReturnNome(pokeJogador));
                                getchar();
                            }
                            break;
                        }
                        if((*HpMaquina) == 0){
                            printf("%s vence!\n\n", NomePlayer);
                            fprintf(arqLog, "\t%s vence!\n\n", NomePlayer);
                            numBatalhas++;
                            qtdVitorias++;
                            random = CriaAleatorio();
                            if(random <= (ultimaPokebola/12.0)){
                                qtdPokebola++;
                                ultimaPokebola = 0;
                            }
                            else{
                                ultimaPokebola++;
                            }
                            HpMaquina = &i;
                            break;
                        }
                    }
                    else{
                        printf("O seu Pokemon esta imposibilitado de atacar(paralisado e/ou dormindo)\n\n");
                        getchar();
                    }
                }
                else{
                    //Vida do pokeJogador = 0
                    printf("%s foi desmaiado!\n\n", ReturnNome(pokeJogador));
                    fprintf(arqLog, "\t%s perde!\n\n", NomePlayer);
                    numBatalhas++;
                    getchar();
                    RemoveFirst(ListaJogador);
                    pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                    ResetaStatus(maquina);
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
                fprintf(arqLog, "\t%s perde!\n\n", NomePlayer);
                numBatalhas++;
                getchar();
                RemoveFirst(ListaJogador);
                pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                ResetaStatus(maquina);
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
                        LogAtaqueMaquina(arqLog, maquina, pokeJogador, randMaquina);
                    }
                    else{
                        printf("O Pokemon selvagem esta imposibilitado de atacar(paralisado e/ou dormindo)\n\n");
                        getchar();
                    }
                }
                else{
                    printf("%s vence!\n\n", NomePlayer);
                    fprintf(arqLog, "\t%s vence!\n\n", NomePlayer);
                    numBatalhas++;
                    qtdVitorias++;
                    random = CriaAleatorio();
                    if(random <= (ultimaPokebola/12.0)){
                        qtdPokebola++;
                        ultimaPokebola = 0;
                    }
                    else{
                        ultimaPokebola++;
                    }
                    HpMaquina = &i;
                    getchar();
                    break;
                }

                if((*HpPokeJogador) == 0){
                    printf("%s foi desmaiado!\n\n", ReturnNome(pokeJogador));
                    fprintf(arqLog, "\t%s perde!\n\n", NomePlayer);
                    numBatalhas++;
                    getchar();
                    RemoveFirst(ListaJogador);
                    pokeJogador = (tPokemon*) ReturnFirstPoke(ListaJogador);
                    ResetaStatus(maquina);
                    if(pokeJogador){
                        HpPokeJogador = ReturnHPatual(pokeJogador);
                        printf("Agora voce esta batalhando com %s\n\n", ReturnNome(pokeJogador));
                        getchar();
                    }
                    break;
                }
                if((*HpMaquina) == 0){
                    printf("%s vence!\n\n", NomePlayer);
                    fprintf(arqLog, "\t%s vence!\n\n", NomePlayer);
                    numBatalhas++;
                    qtdVitorias++;
                    random = CriaAleatorio();
                    if(random <= (ultimaPokebola/12.0)){
                        qtdPokebola++;
                        ultimaPokebola = 0;
                    }
                    else{
                        ultimaPokebola++;
                    }
                    HpMaquina = &i;
                    getchar();
                    break;
                }
            }
            else{
                //pokeJogador = NULL
                break;
            }

            DiminuiAtkDormir(pokeJogador);
            DiminuiDormindo(maquina);
            DiminuiImune(maquina);
            DiminuiParalisado(maquina);
        }

    }
    fprintf(arqLog, "\tFim do jogo %d %s sebreviveu %d batalhas\n\n", qtdPartida, NomePlayer, qtdVitorias);
    printf("A batalha terminou! %s conseguiu %d vitorias\n\n", NomePlayer, qtdVitorias);

    DestroyPokemon(maquina);
    free(maquina);
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
    printf("%s: %.0f%% HP ", pokeJogador, por100);
    queimando = Queimando(poke1);
    dormindo  = VerificaDormindo(poke1);
    paralisado = VerificaParalisado(poke1);
    PrintaStatus(paralisado, dormindo, queimando); 

    Hpmax = ReturnHPmax(poke2);
    Hpatual = ReturnHPatual(poke2);
    por100 = (*Hpatual/Hpmax) * 100;
    printf("%s: %.0f%% HP ", pokeMaquina, por100);
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

void LogAtaqueJogador(FILE *arqLog, tPokemon *poke1, tPokemon *poke2, int pos){
    float Hpmax, *Hpatual, por100;
    char *pokeJogador, *pokeMaquina, *nomeAtk;
    int dormindo, queimando, paralisado;

    pokeJogador = ReturnNome(poke1);
    pokeMaquina = ReturnNome(poke2);
    nomeAtk = NomedoAtk(poke1, pos);

    fprintf(arqLog, "\t%s usa %s\n", pokeJogador, nomeAtk);
    Hpmax = ReturnHPmax(poke1);
    Hpatual = ReturnHPatual(poke1);
    por100 = (*Hpatual/Hpmax) * 100;
    fprintf(arqLog, "\t%s: %.0f%% HP ", pokeJogador, por100);
    queimando = Queimando(poke1);
    dormindo  = VerificaDormindo(poke1);
    paralisado = VerificaParalisado(poke1);
    LogStatus(arqLog, paralisado, dormindo, queimando); 

    Hpmax = ReturnHPmax(poke2);
    Hpatual = ReturnHPatual(poke2);
    por100 = (*Hpatual/Hpmax) * 100;
    fprintf(arqLog, "\t%s: %.0f%% HP ", pokeMaquina, por100);
    queimando = Queimando(poke2);
    dormindo  = VerificaDormindo(poke2);
    paralisado = VerificaParalisado(poke2);
    LogStatus(arqLog, paralisado, dormindo, queimando);
    fprintf(arqLog, "\n");
}

void LogAtaqueMaquina(FILE *arqLog, tPokemon *poke1, tPokemon *poke2, int pos){
    float Hpmax, *Hpatual, por100;
    char *pokeJogador, *pokeMaquina, *nomeAtk;
    int dormindo, queimando, paralisado;

    pokeJogador = ReturnNome(poke2);
    pokeMaquina = ReturnNome(poke1);
    nomeAtk = NomedoAtk(poke1, pos);

    fprintf(arqLog, "\t%s usa %s\n", pokeMaquina, nomeAtk);
    Hpmax = ReturnHPmax(poke2);
    Hpatual = ReturnHPatual(poke2);
    por100 = (*Hpatual/Hpmax) * 100;
    fprintf(arqLog, "\t%s: %.0f%% HP ", pokeJogador, por100);

    queimando = Queimando(poke2);
    dormindo  = VerificaDormindo(poke2);
    paralisado = VerificaParalisado(poke2);
    LogStatus(arqLog, paralisado, dormindo, queimando);    
    

    Hpmax = ReturnHPmax(poke1);
    Hpatual = ReturnHPatual(poke1);
    por100 = (*Hpatual/Hpmax) * 100;
    fprintf(arqLog, "\t%s: %.0f%% HP ", pokeMaquina, por100);

    queimando = Queimando(poke1);
    dormindo  = VerificaDormindo(poke1);
    paralisado = VerificaParalisado(poke1);
    LogStatus(arqLog, paralisado, dormindo, queimando); 
    fprintf(arqLog, "\n");
}

void LogStatus(FILE *arqLog,int p, int d, int q){
    if(!p && !d && !q){fprintf(arqLog, "\n");}
    else if(p && !d && !q){fprintf(arqLog, "(paralisado)\n");}
    else if(!p && d && !q){fprintf(arqLog, "(dormindo)\n");}
    else if(!p && !d && q){fprintf(arqLog, "(queimando)\n");}
    else if(p && !d && q){fprintf(arqLog, "(paralisado, queimando)\n");}
    else if(p && d && !q){fprintf(arqLog, "(paralisado, dormindo)\n");}
    else if(!p && d && q){fprintf(arqLog, "(dormindo, queimando)\n");}
    else if(p && d && q){fprintf(arqLog, "(paralisado, dormindo, queimando)\n");}
}

void LogCaptura(FILE *arqLog, int tentativa){
    fprintf(arqLog, "\tTentativa de captura\n");
    if(tentativa){
        fprintf(arqLog, "\tSucesso\n\n");
    }
    else{
        fprintf(arqLog, "\tFracasso\n\n");
    }
}

void LogFugir(FILE *arqLog, int tentativa){
    fprintf(arqLog, "\tTentativa de Fuga\n");
    if(tentativa){
        fprintf(arqLog, "\tSucesso\n\n");
    }
    else{
        fprintf(arqLog, "\tFracasso\n\n");
    }
}