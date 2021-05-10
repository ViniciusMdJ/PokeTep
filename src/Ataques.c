#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"

typedef tAtaque *(*fptrInicializaPoke)();

/*
    0 = Pikachu;
    1 = Charizard;
    2 = Blastoise;
    3 = Venusaur;
    4 = Steelix;
    5 = Mew; 
*/
fptrInicializaPoke Inicializadores[6] = {NULL};

typedef struct Ataque{
    fptrAtaque atk;
    char *nomeAtk;
}tAtaque;

typedef void (*fptrAtaque)(void *poke1, void *poke2);
/**
 *  0 = ChoquedoTrovao;
 *  1 = OndadeChoque;
 *  2 = Bater;
 *  3 = LancaChamas;
 *  4 = Dormir;
 *  5 = ArmadeAgua;
 *  6 = Proteger;
 *  7 = PodeSono;
 *  8 = BombadeSemente;
 *  9 = DoisGumes;
 *  10 = RabodeFerro;
 *  11 = Cavar;
 *  12 = AutoDestruir;
 *  13 = Metronomo;
 *  14 = DanoCavar;
*/
fptrAtaque AllAtks[15] = {NULL};




float Modificador(float mt, float relacao){
    float valor = mt * relacao;

    float aleat = CriaAleatorio();
    if(aleat <= (1.0/24.0)){
        //printf("CRITOU\n");
        valor *= 2;
    }
    //printf("MODIFICADOR %f\n", valor);

    return valor;    
}

float CaulculaDano(void *poke1, const float poder, float mt, void *poke2){
    float valor, ataque, defesa, relacao;

    relacao = VerificaRelacao(poke1, poke2);
    //printf("relacao %.2f\n", relacao);
    ataque = ReturnAtaque(poke1);
    defesa = ReturnDefesa(poke2);
    valor = ((14.0 * poder * ataque / defesa)/50.0 +2) * Modificador(mt, relacao);
    //printf("DANO %.2f\n", valor);

    return valor;
}

void ChoquedoTrovao(void *poke1, void *poke2){
    //printf("CHOQUE DO TROVAO\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const float poder = 40;
    static const int tipoAtak = eletrico;

    if(!VerificaImune(poke2)){
        int tipoPoke = ReturnTipo(poke1);

        float mt = 1;
        if(tipoAtak == tipoPoke){
            mt = 1.5;
        }
        float DCausado;
        DCausado = CaulculaDano(poke1, poder, mt, poke2);
        CausarDano(poke2, DCausado);
    }
    
    float aleatorio = CriaAleatorio();

    if(aleatorio <= 0.1){
        SetParalisado(poke2, 1);
        //printf("PARALISOU\n");
    }

}

void OndadeChoque(void *poke1, void *poke2){
    //printf("ONDA DE CHOQUE\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const int tipoAtak = eletrico;
    SetParalisado(poke2, 1);
}

void Bater(void *poke1, void *poke2){
    //printf("BATER\n");    
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const int tipoAtak = normal;
    static const float poder = 40;

    if(!VerificaImune(poke2)){
        int tipoPoke = ReturnTipo(poke1);
        
        float mt = 1;
        if(tipoAtak == tipoPoke){
            mt = 1.5;
        }

        float DCausado;
        DCausado = CaulculaDano(poke1, poder, mt, poke2);
        CausarDano(poke2, DCausado);
    }

}

void LancaChamas(void *poke1, void *poke2){
    //printf("LANCA CHAMAS\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const float poder = 90;
    static const int tipoAtak = fogo;

    if(!VerificaImune(poke2)){
        int tipoPoke = ReturnTipo(poke1);
        
        float mt = 1;
        if(tipoAtak == tipoPoke){
            mt = 1.5;
        }

        float DCausado;
        DCausado = CaulculaDano(poke1, poder, mt, poke2);
        CausarDano(poke2, DCausado);
    }

    float aleatorio = CriaAleatorio();
    if(aleatorio <= 0.1){
        Queimar(poke2);
    }
}

void Dormir(void *poke1, void *poke2){
    //printf("DORMIR\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const int tipoAtak = normal;
    SetAtkDormir(poke1, 3);//3 porque a gente quer
}

void ArmadeAgua(void *poke1, void *poke2){
    //printf("ARMA DE AGUA\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const float poder = 40;
    static const int tipoAtak = agua;

    if(!VerificaImune(poke2)){
        int tipoPoke = ReturnTipo(poke1);
        
        float mt = 1;
        if(tipoAtak == tipoPoke){
            mt = 1.5;
        }

        float DCausado;
        DCausado = CaulculaDano(poke1, poder, mt, poke2);
        CausarDano(poke2, DCausado);
    }
}

void Proteger(void *poke1, void *poke2){
    //printf("PROTEGER\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const int tipoAtak = normal;
    SetImune(poke1, 2);//porque a gente quer tbm
}

void PodeSono(void *poke1, void *poke2){
    //printf("PO DE SONO\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const int tipoAtak = planta;
    int randDormir = (rand() % 3) + 1;
    SetDormindo(poke2, randDormir);
}

void BombadeSemente(void *poke1, void *poke2){
    //printf("BOMABA DE SEMENTE\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const float poder = 80;
    static const int tipoAtak = planta;

    if(!VerificaImune(poke2)){
        int tipoPoke = ReturnTipo(poke1);
        
        float mt = 1;
        if(tipoAtak == tipoPoke){
            mt = 1.5;
        }

        float DCausado;
        DCausado = CaulculaDano(poke1, poder, mt, poke2);
        CausarDano(poke2, DCausado);
    }
}

void DoisGumes(void *poke1, void *poke2){
    //printf("DOIS GUMES\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 120;
    static const int tipoAtak = normal;
    int tipoPoke = ReturnTipo(poke1);
    
    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    if(!VerificaImune(poke2)){
    CausarDano(poke2, DCausado);
    }

    if(!VerificaImune(poke1)){
    CausarDano(poke1, (DCausado/3.0));
    }
}

void RabodeFerro(void *poke1, void *poke2){
    //printf("RABO DE FERRO\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 100;
    static const int tipoAtak = metal;

    if(!VerificaImune(poke2)){
        int tipoPoke = ReturnTipo(poke1);
        
        float mt = 1;
        if(tipoAtak == tipoPoke){
            mt = 1.5;
        }

        float DCausado;
        DCausado = CaulculaDano(poke1, poder, mt, poke2);
        CausarDano(poke2, DCausado);
    }
}

void Cavar(void *poke1, void *poke2){
    //printf("CAVAR\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const int tipoAtak = normal;
    SetImune(poke1, 2);
    Cavou(poke1);
}

void Metronomo(void *poke1, void *poke2){
    int atkRand;
    fptrAtaque atkpoke;

    atkRand = rand() % 13;
    atkpoke = AllAtks[atkRand];
    atkpoke(poke1, poke2);
}

void AutoDestruir(void *poke1, void *poke2){
    //printf("AUTO DESTRUIR\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 200;
    static const int tipoAtak = normal;

    if(!VerificaImune(poke2)){
        int tipoPoke = ReturnTipo(poke1);
        
        float mt = 1;
        if(tipoAtak == tipoPoke){
            mt = 1.5;
        }

        float DCausado;
        DCausado = CaulculaDano(poke1, poder, mt, poke2);
        CausarDano(poke2, DCausado);
    }

    CausarDano(poke1, 99999);
}

void DanoCavar(void *poke1, void *poke2){
    //printf("DANO DO CAVAR\n");
    //printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const int tipoAtak = normal;
    const float poder = 80;

    if(!VerificaImune(poke2)){
        int tipoPoke = ReturnTipo(poke1);
        
        float mt = 1;
        if(tipoAtak == tipoPoke){
            mt = 1.5;
        }

        float DCausado;
        DCausado = CaulculaDano(poke1, poder, mt, poke2);
        CausarDano(poke2, DCausado);
    }

    DiminuiCavar(poke1);
    printf("\n");
}

void inicializaFptrAtaques(){
    AllAtks[0] = ChoquedoTrovao;
    AllAtks[1] = OndadeChoque;
    AllAtks[2] = Bater;
    AllAtks[3] = LancaChamas;
    AllAtks[4] = Dormir;
    AllAtks[5] = ArmadeAgua;
    AllAtks[6] = Proteger;
    AllAtks[7] = PodeSono;
    AllAtks[8] = BombadeSemente;
    AllAtks[9] = DoisGumes;
    AllAtks[10] = RabodeFerro;
    AllAtks[11] = Cavar;
    AllAtks[12] = AutoDestruir;
    AllAtks[13] = Metronomo;
    AllAtks[14] = DanoCavar;
}

void InicializaFptrPokemons(){
    Inicializadores[0] = InicializaPikachu;
    Inicializadores[1] = InicializaCharizard;
    Inicializadores[2] = InicializaBlastoise;
    Inicializadores[3] = InicializaVenusaur;
    Inicializadores[4] = InicializaSteelix;
    Inicializadores[5] = InicializaMew; 
}

void DestroytAtaques(tAtaque *x){
    free(x[0].nomeAtk);
    free(x[1].nomeAtk);
    free(x[2].nomeAtk);
}

char *ReturnNomeAtk(tAtaque *x, int pos){
    return x[pos].nomeAtk;
}

fptrInicializaPoke ReturnInicializador(int pos){
    return Inicializadores[pos];
}

fptrAtaque ReturnMovimento(tAtaque *atak, int pos){
    fptrAtaque movimento = atak[pos].atk;
    return movimento;
}

tAtaque *InicializaPikachu(){
    tAtaque *x = malloc(sizeof(tAtaque) * 3);

    x[0].atk = AllAtks[0];
    x[0].nomeAtk = strdup("Choque do Trovao");
    x[1].atk = AllAtks[1];
    x[1].nomeAtk = strdup("Onda de Choque");
    x[2].atk = AllAtks[2];
    x[2].nomeAtk = strdup("Bater");
    return x;
}

tAtaque *InicializaCharizard(){
    tAtaque *x = malloc(sizeof(tAtaque) * 3);

    x[0].atk = AllAtks[3];
    x[0].nomeAtk = strdup("Lanca Chamas");
    x[1].atk = AllAtks[4];
    x[1].nomeAtk = strdup("Dormir");
    x[2].atk = AllAtks[2];
    x[2].nomeAtk = strdup("Bater");
    return x;
}

tAtaque *InicializaBlastoise(){
    tAtaque *x = malloc(sizeof(tAtaque) * 3);

    x[0].atk = AllAtks[5];
    x[0].nomeAtk = strdup("Arma de Agua");
    x[1].atk = AllAtks[6];
    x[1].nomeAtk = strdup("Proteger");
    x[2].atk = AllAtks[2];
    x[2].nomeAtk = strdup("Bater");
    return x;
}

tAtaque *InicializaVenusaur(){
    tAtaque *x = malloc(sizeof(tAtaque) * 3);

    x[0].atk = AllAtks[7];
    x[0].nomeAtk = strdup("Po de Sono");
    x[1].atk = AllAtks[8];
    x[1].nomeAtk = strdup("Bomba de Semente");
    x[2].atk = AllAtks[9];
    x[2].nomeAtk = strdup("Dois Gumes");
    return x;
}

tAtaque *InicializaSteelix(){
    tAtaque *x = malloc(sizeof(tAtaque) * 3);

    x[0].atk = AllAtks[10];
    x[0].nomeAtk = strdup("Rabo de Ferro");
    x[1].atk = AllAtks[4];
    x[1].nomeAtk = strdup("Dormir");
    x[2].atk = AllAtks[11];
    x[2].nomeAtk = strdup("Cavar");
    return x;
}

tAtaque *InicializaMew(){
    tAtaque *x = malloc(sizeof(tAtaque) * 3);

    x[0].atk = AllAtks[13];
    x[0].nomeAtk = strdup("Metronomo");
    x[1].atk = AllAtks[2];
    x[1].nomeAtk = strdup("Bater");
    x[2].atk = AllAtks[12];
    x[2].nomeAtk = strdup("Auto Destruir");
    return x;
}

