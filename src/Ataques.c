#include "../include/Ataques.h"
#include "../include/Pokemon.h"
#include "../include/Utilidades.h"

typedef tAtaque *(*fptrInicializaPoke)();

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
 *  12 = Metronomo;
 *  13 = AutoDestruir;
*/

typedef struct Ataque{
    fptrAtaque atk;
    char *nomeAtk;
}tAtaque;

fptrAtaque AllAtks[14] = {NULL};

fptrInicializaPoke Inicializadores[6] = {NULL};

float Modificador(float mt, float relacao){
    float valor = mt * relacao;

    float aleat = CriaAleatorio();
    if(aleat <= (1.0/24.0)){
        printf("CRITOU\n");
        valor *= 2;
    }
    printf("MODIFICADOR %f\n", valor);

    return valor;    
}

float CaulculaDano(void *poke1, const float poder, float mt, void *poke2){
    //falta criar a funcao para retornar a relacao
    float valor, ataque, defesa, relacao;

    relacao = VerificaRelacao(poke1, poke2);
    ataque = ReturnAtaque(poke1);
    defesa = ReturnDefesa(poke2);
    valor = ((14.0 * poder * ataque / defesa)/50.0 +2) * Modificador(mt, relacao);
    printf("DANO %f\n", valor);

    return valor;
}

void ChoquedoTrovao(void *poke1, void *poke2){
    printf("CHOQUE DO TROVAO\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const float poder = 40;
    static const int tipoAtak = eletrico;
    int tipoPoke = ReturnTipo(poke1);

    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
    float aleatorio = CriaAleatorio();
    if(aleatorio <= 0.1){
        //chama a funcao para paralizar poke2
        printf("PARALISOU\n");
    }

}

void OndadeChoque(void *poke1, void *poke2){
    static const int tipoAtak = eletrico;
    //chama a funcao para paralisar o poke2 1 turno
}

void Bater(void *poke1, void *poke2){
    printf("BATER\n");    
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    static const int tipoAtak =normal;
    const float poder = 40;
    int tipoPoke = ReturnTipo(poke1);
    
    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);

}

void LancaChamas(void *poke1, void *poke2){
    printf("LANCA CHAMAS\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 90;
    static const int tipoAtak = fogo;
    int tipoPoke = ReturnTipo(poke1);
    
    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
    float aleatorio = CriaAleatorio();
    if(aleatorio <= 0.1){
        //chama a funcao de queimar
    }
}

void Dormir(void *poke1, void *poke2){}

void ArmadeAgua(void *poke1, void *poke2){
    printf("ARMA DE AGUA\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 40;
    static const int tipoAtak = agua;
    int tipoPoke = ReturnTipo(poke1);
    
    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
}

void Proteger(void *poke1, void *poke2){}

void PodeSono(void *poke1, void *poke2){}

void BombadeSemente(void *poke1, void *poke2){
    printf("BOMABA DE SEMENTE\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 80;
    static const int tipoAtak = planta;
    int tipoPoke = ReturnTipo(poke1);
    
    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
}

void DoisGumes(void *poke1, void *poke2){
    printf("AUTO DESTRUIR\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 120;
    static const int tipoAtak = planta;
    int tipoPoke = ReturnTipo(poke1);
    
    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
    CausarDano(poke1, (DCausado/3));
}

void RabodeFerro(void *poke1, void *poke2){
    printf("RABO DE FERRO\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 100;
    static const int tipoAtak = metal;
    int tipoPoke = ReturnTipo(poke1);
    
    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
}

void Cavar(void *poke1, void *poke2){}

void Metronomo(void *poke1, void *poke2){}

void AutoDestruir(void *poke1, void *poke2){
    printf("AUTO DESTRUIR\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 200;
    static const int tipoAtak = psiquico;
    int tipoPoke = ReturnTipo(poke1);
    
    float mt = 1;
    if(tipoAtak == tipoPoke){
        mt = 1.5;
    }

    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
    CausarDano(poke1, 99999);
}

void iniciualizaFptrAtaque(){
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
    free(x->nomeAtk);
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

