#include "../include/Pokemon.h"
#include "../include/Ataques.h"
#include "../include/Lista.h"
#include "../include/Menus.h"


typedef struct pokemon {
    char* nome;
    int tipo;

    int dormindo;
    int queimando;
    int paralisado;

    tAtaque *Movimentos;

    float ataque;
    float defesa;
    float HPmax;
    float HPatual;
} tPokemon;


tPokemon ListaPoke(int i){
    tPokemon Poke;
    fptrInicializaPoke funcao = ReturnInicializador(i);
    if(i == 0){
        Poke.nome = strdup("Picachu");
        Poke.tipo = eletrico;
        Poke.ataque = 110;
        Poke.defesa = 100;
        Poke.HPmax = 200;
        Poke.HPatual = Poke.HPmax;
        Poke.Movimentos = funcao();
    }
    else if(i == 1){
        Poke.nome = strdup("Charizard");
        Poke.tipo = fogo;
        Poke.ataque = 160;
        Poke.defesa = 150;
        Poke.HPmax = 260;
        Poke.HPatual = Poke.HPmax;
        Poke.Movimentos = funcao();
    }
    else if(i == 2){
        Poke.nome = strdup("Blastoise");
        Poke.tipo = agua;
        Poke.ataque = 180;
        Poke.defesa = 200;
        Poke.HPmax = 280;
        Poke.HPatual = Poke.HPmax;
        Poke.Movimentos = funcao();
    }
    else if(i == 3){
        Poke.nome = strdup("Venusaur");
        Poke.tipo = planta;
        Poke.ataque = 160;
        Poke.defesa = 160;
        Poke.HPmax = 300;
        Poke.HPatual = Poke.HPmax;
        Poke.Movimentos = funcao();
    }
    else if(i == 4){
        Poke.nome = strdup("Steelix");
        Poke.tipo = metal;
        Poke.ataque = 170;
        Poke.defesa = 400;
        Poke.HPmax = 280;
        Poke.HPatual = Poke.HPmax;
        Poke.Movimentos = funcao();
    }
    else if(i == 5){
        Poke.nome = strdup("Mew");
        Poke.tipo = psiquico;
        Poke.ataque = 200;
        Poke.defesa = 200;
        Poke.HPmax = 320;
        Poke.HPatual = Poke.HPmax;
        Poke.Movimentos = funcao();
    }

    Poke.dormindo = -1;
    Poke.paralisado = -1;
    Poke.queimando = -1;
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

    escolhidos = InitLista(sizeof(tPokemon), DestroyPokemon);
    tPokemon *retirado;
    int opcao;
    
    for(i=0; i<3; i++){
        opcao = MenuEscolha(iniciais);
        retirado = (tPokemon*)BuscaRetorna(iniciais, opcao);
        InserirUlt(escolhidos, retirado);
        free(retirado);
    }

    DestroyLista(iniciais);

    return escolhidos;
}

void DestroyPokemon(void* Pokemon){
    tPokemon *x = (tPokemon*)Pokemon;
    DestroytAtaques(x->Movimentos);
    free(x->Movimentos);
    free(x->nome);
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
    static float relacoes[6][6] = {{0.5,0.5,2,1,1,2},
                                   {2,0.5,0.5,1,1,1},
                                   {0.5,2,0.5,1,1,0.5},
                                   {1,2,0.5,0.5,1,1},
                                   {1,1,1,1,0.5,0.5},
                                   {0.5,0.5,1,0.5,1,0.5}};
    
    int tipoPoke1 = poke1->tipo;
    int tipoPoke2 = poke2->tipo;

    float relacao = relacoes[tipoPoke1][tipoPoke2];

    return relacao;
}
