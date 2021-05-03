#include "../include/Pokemon.h"
#include "../include/Ataques.h"

enum TipoP{eletrico, fogo, agua, planta, metal, psiquico};

typedef struct Pokemon {
    char* nome;
    int tipo;

    int dormindo;
    int queimando;
    int paralisado;

    fptrAtaque movimentos[3];
    float mts[3];

    float ataque;
    float defesa;
    float HPmax;
    float HPatual;
    tPokemon* prox;
    //- ponteiro de função de ataques
} tPokemon;


tPokemon* CriaPokemon(char* nome, int tipo, float ataque, float defesa, float HPmax){
    tPokemon* poke;

    poke = (tPokemon*)calloc(1, sizeof(tPokemon));

    poke->nome = nome;
    poke->tipo = tipo;
    poke->ataque = ataque;
    poke->defesa = defesa;
    poke->HPmax = HPmax;
    poke->HPatual = HPmax;
    poke->movimentos[0] = DoisGumes;
    poke->mts[0] = 1;
    poke->movimentos[1] = RabodeFerro;
    poke->mts[1] = 1;
    poke->movimentos[2] = AutoDestruir;
    poke->mts[2] = 1;
    poke->prox = NULL;

return poke;
}

void DestroyPokemon(tPokemon* Pokemon){
    for(Pokemon = Pokemon; Pokemon != NULL; Pokemon = Pokemon->prox){
        free(Pokemon->nome);
        free(Pokemon);    
    }
}
/* func ataq devolve int(uma para calc o dano e outra para aplicar) ou void(passar point alvo)
 * salvar pokes padrao vet
 * struct ataq? salvar os ataqs no tPokemon ou em um vetor
 * */

void Movimento_0(tPokemon *poke1, tPokemon *poke2){
    fptrAtaque x = poke1->movimentos[0];
    x(poke1, poke1->mts[0], poke2);
}

void Movimento_1(tPokemon *poke1, tPokemon *poke2){
    fptrAtaque x = poke1->movimentos[1];
    x(poke1, poke1->mts[1], poke2);
}

void Movimento_2(tPokemon *poke1, tPokemon *poke2){
    fptrAtaque x = poke1->movimentos[2];
    x(poke1, poke1->mts[2], poke2);
}

void CausarDano(tPokemon *poke, float dano){
    printf("VIDA ANTES %f\n", poke->HPatual);
    if(poke->HPatual >= dano){
        poke->HPatual -= dano;
    }
    else{
        poke->HPatual = 0;
    }
    printf("VIDA DEPOIS %f\n", poke->HPatual);
}

float VerificaRelacao(tPokemon *poke1, tPokemon *poke2){
    if(poke1->tipo == poke2->tipo){
        return 0.5;
    }

    if(poke1->tipo == eletrico){
        if(poke2->tipo == agua){
            return 2.0;
        }
        else if(poke1->tipo == planta){
            return 0.5;
        }
        else{
            return 1;
        }
    }

    if(poke1->tipo == planta){
        if(poke2->tipo == agua){
            return 2.0;
        }
        else if((poke2->tipo == fogo) || (poke2->tipo == metal)){
            return 0.5;
        }
        else{
            return 1;
        }
    }

    if(poke1->tipo == agua){
        if(poke2->tipo == fogo){
            return 2;
        }
        else if(poke2->tipo == planta){
            return 0.5;
        }
        else{
            return 1;
        }
    }

    if(poke1->tipo == fogo){
        if(poke2->tipo == agua){
            return 0.5;
        }
        else if((poke2->tipo == planta) || (poke2->tipo ==metal)){
            return 2;
        }
        else{
            return 1;
        }
    }

    if(poke1->tipo == psiquico){
        if(poke2->tipo == metal){
            return 0.5;
        }
        else{
            return 1;
        }
    }

    if(poke1->tipo == metal){
        if(poke2->tipo == fogo){
            return 0.5;
        }
        else if(poke2->tipo == agua){
            return 0.5;
        }
        else if(poke2->tipo == eletrico){
            return 0.5;
        }
        else{
            return 1;
        }
    }
}

