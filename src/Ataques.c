#include "../include/Ataques.h"
#include "../include/Pokemon.h"
#include "../include/Utilidades.h"

typedef void (*fptrAtaque)(void *poke1, int pos, void *poke2);

typedef struct Ataque{
    fptrAtaque atk;
    float mt;
}tAtaque;

float Modificador(float mt, float relacao){
    float valor = mt * relacao;

    float aleat = CriaAleatorio();
    if(aleat <= (1.0/24.0)){
        valor *= 2;
    }

    return valor;    
}

float Dano(void *poke1, int pos, void *poke2){
    float valor, ataque, defesa, relacao, mt;
    //chamar a funcao q retorna a relacao
    //chamar a funcao q retorna atk
    //chamar a funcao q retorna def
    valor = ((14.0 * ataque * defesa)/50.0 +2) * Modificador(mt, relacao);
    return valor;

}

void ChoquedoTrovao(void *poke1, int pos, void *poke2){}

void OndadeChoque(void *poke1, int pos, void *poke2){}

void Bater(void *poke1, int pos, void *poke2){

}

void LancaChamas(void *poke1, int pos, void *poke2){}

void Dormir(void *poke1, int pos, void *poke2){}

void ArmadeAgua(void *poke1, int pos, void *poke2){}

void Proteger(void *poke1, int pos, void *poke2){}

void PodeSono(void *poke1, int pos, void *poke2){}

void BombadeSemente(void *poke1, int pos, void *poke2){}

void DoisGumes(void *poke1, int pos, void *poke2){}

void RabodeFerro(void *poke1, int pos, void *poke2){}

void Cavar(void *poke1, int pos, void *poke2){}

void Metronomo(void *poke1, int pos, void *poke2){}

void AutoDestruir(void *poke1, int pos, void *poke2){}

tAtaque inicializaChoquedoTrovao(float mt){
    tAtaque atk;
    atk.atk = ChoquedoTrovao;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaOndadeChoque(float mt){
    tAtaque atk;
    atk.atk = OndadeChoque;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaBater(float mt){
    tAtaque atk;
    atk.atk = Bater;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaLancaChamas(float mt){
    tAtaque atk;
    atk.atk = LancaChamas;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaDormir(float mt){
    tAtaque atk;
    atk.atk = Dormir;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaArmadeAgua(float mt){
    tAtaque atk;
    atk.atk = ArmadeAgua;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaProteger(float mt){
    tAtaque atk;
    atk.atk = Proteger;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaPodeSono(float mt){
    tAtaque atk;
    atk.atk = PodeSono;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaBombadeSemente(float mt){
    tAtaque atk;
    atk.atk = BombadeSemente;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaDoisGumes(float mt){
    tAtaque atk;
    atk.atk = DoisGumes;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaRabodeFerro(float mt){
    tAtaque atk;
    atk.atk = RabodeFerro;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaCavar(float mt){
    tAtaque atk;
    atk.atk = Cavar;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaMetronomo(float mt){
    tAtaque atk;
    atk.atk = Metronomo;
    atk.mt = mt;
    return atk;
}

tAtaque inicializaAutoDestruir(float mt){
    tAtaque atk;
    atk.atk = AutoDestruir;
    atk.mt = mt;
    return atk;
}