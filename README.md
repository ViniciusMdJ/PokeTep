# PokeTep

**Feito por [Jean Calos Vieira Machado](https://github.com/caje-vi) e [Vinicius Moraes de Jesus](https://github.com/ViniciusMdJ)**


### Ataques.h
Biblioteca dedica ao ponteiro de função e funções referentes aos ataques dos pokemons, calculo de dano, struct de ataques.

### Jogador.h
Biblioteca dedicada a manipular o struct tJogador.

### Menus.h
Biblioteca onde se localizam as funções correspondentes aos menus do jogo.
    
### Pontuacao.h
Biblioteca responsável por armazenar as funcoes dedicadas a ler e salvar o arquivo de Pontuações.

### Batalha.h
Biblioteca utilizada para salvar os logs e realizar as as ações de batalha.
    
### Lista.h
Biblioteca dedicada a criar e manipular o struct Lista, contendo as funcoes de salvar, iniciar, buscar, inserir e imprimir.

### Pokemon.h
Biblioteca encarregada de alterar, retornar e checar os status do struct tPokemon.
Para criar o código de acordo com os pedidos foram utilizados os seguintes status dentro do struct tPokemon:    
Dormindo: Status referente ao Pokemon não poder atacar por estar dormindo.  
Queimando: Status referente ao dano levado a cada turno por estar queimando.    
Paralisado: Status referente ao Pokemon não poder atacar por estar Paralisado.  
AtkDormir: Status referente ao Pokemon ter utilizado do ataque dormir, logo não pode atacar e recuperará sua vida por completo no final de 2 turno. 
Imune: Status referente aos ataques proteger e cavar, o Pokemon não pode ser alvo caso ativo.   
Cavar: Status que dá imunidade e posterga o dano causado por um turno.  

### Utilidades.h
Biblioteca responsável por criar os valores aleatorios, limpar o terminal e verificar se um valor está entre outros dois.
