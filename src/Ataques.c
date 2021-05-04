#include "../include/Ataques.h"
#include "../include/Pokemon.h"
#include "../include/Utilidades.h"


typedef void (*fptrAtaque)(void *poke1, float mt, void *poke2);
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
fptrAtaque AllAtks[14] = {NULL};

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

void ChoquedoTrovao(void *poke1, float mt, void *poke2){
    printf("CHOQUE DO TROVAO\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 40;
    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
    float aleatorio = CriaAleatorio();
    if(aleatorio <= 0.1){
        //chama a funcao para paralizar poke2
        printf("PARALISOU\n");
    }

}

void OndadeChoque(void *poke1, float mt, void *poke2){
    //chama a funcao para paralisar o poke2 1 turno
}

void Bater(void *poke1, float mt, void *poke2){
    printf("BATER\n");    
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 40;
    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);

}

void LancaChamas(void *poke1, float mt, void *poke2){
    printf("LANCA CHAMAS\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 90;
    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
    float aleatorio = CriaAleatorio();
    if(aleatorio <= 0.1){
        //chama a funcao de queimar
    }
}

void Dormir(void *poke1, float mt, void *poke2){}

void ArmadeAgua(void *poke1, float mt, void *poke2){
    printf("ARMA DE AGUA\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 40;
    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
}

void Proteger(void *poke1, float mt, void *poke2){}

void PodeSono(void *poke1, float mt, void *poke2){}

void BombadeSemente(void *poke1, float mt, void *poke2){
    printf("BOMABA DE SEMENTE\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 80;
    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
}

void DoisGumes(void *poke1, float mt, void *poke2){
    printf("AUTO DESTRUIR\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 120;
    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
    CausarDano(poke1, (DCausado/3));
}

void RabodeFerro(void *poke1, float mt, void *poke2){
    printf("RABO DE FERRO\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 100;
    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
}

void Cavar(void *poke1, float mt, void *poke2){}

void Metronomo(void *poke1, float mt, void *poke2){}

void AutoDestruir(void *poke1, float mt, void *poke2){
    printf("AUTO DESTRUIR\n");
    printf("%s ataca %s\n", ReturnNome(poke1), ReturnNome(poke2));
    const float poder = 200;
    float DCausado;
    DCausado = CaulculaDano(poke1, poder, mt, poke2);
    CausarDano(poke2, DCausado);
    CausarDano(poke1, 99999);
}

void iniciualizaVetor(){
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
    AllAtks[12] = Metronomo;
    AllAtks[13] = AutoDestruir;
}

fptrAtaque ReturnFuncao(int pos){
    return AllAtks[pos];
}

// tAtaque inicializaChoquedoTrovao(float mt){
//     tAtaque atk;
//     atk.atk = ChoquedoTrovao;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaOndadeChoque(float mt){
//     tAtaque atk;
//     atk.atk = OndadeChoque;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaBater(float mt){
//     tAtaque atk;
//     atk.atk = Bater;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaLancaChamas(float mt){
//     tAtaque atk;
//     atk.atk = LancaChamas;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaDormir(float mt){
//     tAtaque atk;
//     atk.atk = Dormir;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaArmadeAgua(float mt){
//     tAtaque atk;
//     atk.atk = ArmadeAgua;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaProteger(float mt){
//     tAtaque atk;
//     atk.atk = Proteger;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaPodeSono(float mt){
//     tAtaque atk;
//     atk.atk = PodeSono;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaBombadeSemente(float mt){
//     tAtaque atk;
//     atk.atk = BombadeSemente;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaDoisGumes(float mt){
//     tAtaque atk;
//     atk.atk = DoisGumes;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaRabodeFerro(float mt){
//     tAtaque atk;
//     atk.atk = RabodeFerro;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaCavar(float mt){
//     tAtaque atk;
//     atk.atk = Cavar;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaMetronomo(float mt){
//     tAtaque atk;
//     atk.atk = Metronomo;
//     atk.mt = mt;
//     return atk;
// }

// tAtaque inicializaAutoDestruir(float mt){
//     tAtaque atk;
//     atk.atk = AutoDestruir;
//     atk.mt = mt;
//     return atk;
// }