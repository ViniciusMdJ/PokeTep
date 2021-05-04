#include "../include/Pokemon.h"
#include "../include/Ataques.h"
#include "../include/Lista.h"
#include "../include/Menus.h"

enum TipoP{eletrico, fogo, agua, planta, metal, psiquico};

typedef struct pokemon {
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
    //- ponteiro de função de ataques
} tPokemon;


tPokemon ListaPoke(int i){
    tPokemon Poke;
    if(i == 0){
        Poke.nome = strdup("Picachu");
        Poke.tipo = eletrico;
        Poke.ataque = 110;
        Poke.defesa = 100;
        Poke.HPmax = 200;
    }
    else if(i == 1){
        Poke.nome = strdup("Charizard");
        Poke.tipo = fogo;
        Poke.ataque = 160;
        Poke.defesa = 150;
        Poke.HPmax = 260;
    }
    else if(i == 2){
        Poke.nome = strdup("Blastoise");
        Poke.tipo = agua;
        Poke.ataque = 180;
        Poke.defesa = 200;
        Poke.HPmax = 280;
    }
    else if(i == 3){
        Poke.nome = strdup("Venusaur");
        Poke.tipo = planta;
        Poke.ataque = 160;
        Poke.defesa = 160;
        Poke.HPmax = 300;
    }
    else if(i == 4){
        Poke.nome = strdup("Steelix");
        Poke.tipo = metal;
        Poke.ataque = 170;
        Poke.defesa = 400;
        Poke.HPmax = 280;
    }
    else if(i == 5){
        Poke.nome = strdup("Mew");
        Poke.tipo = psiquico;
        Poke.ataque = 200;
        Poke.defesa = 200;
        Poke.HPmax = 320;
    }
return Poke;
}
char* ReturnNome(tPokemon* Poke){
    return Poke->nome;
}
float ReturnAtaque(tPokemon* Poke){
    return Poke->ataque;
}
float ReturnDefesa(tPokemon* Poke){
    return Poke->defesa;
}
float ReturnHPmax(tPokemon* Poke){
    return Poke->HPmax;
}
float* ReturnHPatual(tPokemon* Poke){
    return &Poke->HPatual;
}
int ReturnTipo(tPokemon* Poke){
    return Poke->tipo;
}

List* InitIniciais(){
    List *iniciais, *escolhidos;
    tPokemon poke;
    iniciais = InitLista(sizeof(tPokemon), DestroyPokemon);
    int i;
    for(i=0; i<6; i++){
        poke = ListaPoke(i);
        InserirUlt(iniciais, &poke);
    }
    ImprimeLista(iniciais);
    printf("\n\n");
    escolhidos = InitLista(sizeof(tPokemon), DestroyPokemon);
    tPokemon *retirado;
    int opcao;
    
    for(i=0; i<3; i++){
        opcao = MenuEscolha(iniciais);
        retirado = (tPokemon*)BuscaRetorna(iniciais, opcao);
        InserirUlt(escolhidos, retirado);
        free(retirado);
    }
    
    
    


    ImprimeLista(iniciais);
    DestroyLista(iniciais);

    return escolhidos;
}

void DestroyPokemon(void* Pokemon){
    tPokemon *x = (tPokemon*)Pokemon;
    free(x->nome);
}

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
return 1;
}
