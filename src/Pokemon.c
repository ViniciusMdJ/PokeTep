#include "../include/Menus.h"
#include "../include/Lista.h"
#include "../include/Utilidades.h"
#include "../include/Pontuacao.h"
#include "../include/Jogador.h"
#include "../include/Ataques.h"
#include "../include/Pokemon.h"

typedef struct pokemon {
    char* nome;
    int tipo;

    int dormindo;//     0 = padrao, 0 > dormindo    
    int queimando;//    0 = padrao, 1 = queimando
    int paralisado;//   0 = padrao, 0 > paralisado
    int atkDormir;//    -1 = padrao, 0 = recupera HP, 0 > Dormindo
    int imune;//        0 = padrao, 0 > nao toma dano
    int cavar;//        0 = padrao, 1 = da o dano

    tAtaque *Movimentos;

    float ataque;
    float defesa;
    float HPmax;
    float HPatual;
} tPokemon;


tPokemon *ListaPoke(int i){
    tPokemon *Poke;
    Poke = malloc(sizeof(tPokemon));
    fptrInicializaPoke funcao = ReturnInicializador(i);
    if(i == 0){
        Poke->tipo = eletrico;
        Poke->ataque = 110;
        Poke->defesa = 100;
        Poke->nome = strdup("Picachu");
        Poke->HPmax = 200;
        Poke->HPatual = Poke->HPmax;
        Poke->Movimentos = funcao();
    }
    else if(i == 1){
        Poke->nome = strdup("Charizard");
        Poke->tipo = fogo;
        Poke->ataque = 160;
        Poke->defesa = 150;
        Poke->HPmax = 260;
        Poke->HPatual = Poke->HPmax;
        Poke->Movimentos = funcao();
    }
    else if(i == 2){
        Poke->nome = strdup("Blastoise");
        Poke->tipo = agua;
        Poke->ataque = 180;
        Poke->defesa = 200;
        Poke->HPmax = 280;
        Poke->HPatual = Poke->HPmax;
        Poke->Movimentos = funcao();
    }
    else if(i == 3){
        Poke->nome = strdup("Venusaur");
        Poke->tipo = planta;
        Poke->ataque = 160;
        Poke->defesa = 160;
        Poke->HPmax = 300;
        Poke->HPatual = Poke->HPmax;
        Poke->Movimentos = funcao();
    }
    else if(i == 4){
        Poke->nome = strdup("Steelix");
        Poke->tipo = metal;
        Poke->ataque = 170;
        Poke->defesa = 400;
        Poke->HPmax = 280;
        Poke->HPatual = Poke->HPmax;
        Poke->Movimentos = funcao();
    }
    else if(i == 5){
        Poke->nome = strdup("Mew");
        Poke->tipo = psiquico;
        Poke->ataque = 200;
        Poke->defesa = 200;
        Poke->HPmax = 320;
        Poke->HPatual = Poke->HPmax;
        Poke->Movimentos = funcao();
    }

    Poke->dormindo = 0;
    Poke->paralisado = 0;
    Poke->queimando = 0;
    Poke->atkDormir = -1;
    Poke->imune = 0;
    Poke->cavar = 0;

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
    tPokemon *poke;
    iniciais = InitLista(sizeof(tPokemon), DestroyPokemon);
    int i;
    for(i=0; i<6; i++){
        poke = ListaPoke(i);
        InserirUlt(iniciais, poke);
        free(poke);
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

fptrAtaque MovimentoPokemon(tPokemon *poke, int pos){
    fptrAtaque movimento = ReturnMovimento(poke->Movimentos, pos);
    return movimento;
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

void ResetaStatus(tPokemon *poke){
    poke->dormindo = 0;
    poke->paralisado = 0;
    poke->queimando = 0;
    poke->atkDormir = -1;
    poke->imune = 0;
    poke->cavar = 0;
}

void AumenteHp(tPokemon *poke, float qtd){
    poke->HPatual += qtd;
    if(poke->HPatual > poke->HPmax){
        poke->HPatual = poke->HPmax;
    }
}

char *NomedoAtk(tPokemon *poke, int pos){
    return ReturnNomeAtk(poke->Movimentos, pos);
}

int PodeAtacar(tPokemon *poke){
    if((poke->paralisado == 0) && (poke->dormindo == 0) && (poke->atkDormir <= 0)){
        return 1;
    }
    return 0;
}

int Queimando(tPokemon *poke){
    if(poke->queimando){
        return 1;
    }
    return 0;
}

void DiminuiDormindo(tPokemon *x){
    if(x->dormindo > 0){
        x->dormindo--;
    }
}

void DiminuiParalisado(tPokemon *x){
    if(x->paralisado > 0){
        x->paralisado--;
    }
}

void DiminuiImune(tPokemon *x){
    if(x->imune > 0){
        x->imune--;
    }
}

void DiminuiAtkDormir(tPokemon *x){
    if(x->atkDormir > -1){
        x->atkDormir--;
    }
}

void DiminuiCavar(tPokemon *poke){
    if(poke->cavar > 0){
        poke->cavar--;
    }
}

void Queimar(tPokemon *x){
    if(x->tipo != fogo){
        x->queimando = 1;
    }
}

void SetDormindo(tPokemon *poke, int x){
    if(poke->dormindo < x){
        poke->dormindo = x;
    }
}

void SetParalisado(tPokemon *poke, int x){
    if(poke->paralisado < x){
        poke->paralisado = x;
    }
}

void SetImune(tPokemon *poke, int x){
    if(poke->imune < x){
        poke->imune = x;
    }
}

void SetAtkDormir(tPokemon *poke, int x){
    if(poke->atkDormir < x){
        poke->atkDormir = x;
    }
}

int VerificaAtkDormir(tPokemon *x){
    if(x->atkDormir == 0){
        return 1;
    }
    return 0;
}

int VerificaCavar(tPokemon *x){
    if(x->cavar == 1){
        return 1;
    }
    return 0;
}

int VerificaImune(tPokemon *x){
    if(x->imune > 0){
        return 1;
    }
    return 0;
}

void Cavou(tPokemon *x){
    x->cavar = 1;
}