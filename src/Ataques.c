#include "../include/Ataques.h"

float Modificador(float mt, float chance, float relacao){
    float valor = mt * relacao;

    float random = chance/(float)(RAND_MAX);
    if(random <= (1.0/24.0)){
        valor * 2;
    }

    return valor;    
}

float Dano(tPokemon *atacante, int poder, float mt, float chance, tPokemon *defensor){
    float valor, ataque, defesa, relacao;
    //chamar a funcao q retorna a relacao
    //chamar a funcao q retorna atk
    //chamar a funcao q retorna def
    vlaor = ((14.0 * ataque * defesa)/50.0 +2) * Modificador(mt, chance, relacao);

}