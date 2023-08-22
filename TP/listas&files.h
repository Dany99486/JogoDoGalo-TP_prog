#ifndef LISTAS&FILES_H
#define LISTAS&FILES_H


#define N 3

typedef struct estruturas Array;
struct estruturas{
    int point;
} ;

typedef struct jogo game_list, *pgame;
typedef struct jogo
{
    pgame prox;
    int tab;
    int pos;
    int jogador;
    int num_jogada;
    int ModoDeJogo;
    char mat_verifica[12];
};

pgame atualiza_lista(pgame lista,char file_name[],char mat_verifica[],int tab_plus,int pos,int jogador,int n_jogadas,int ModoDeJogo);
void ver_jogadas(pgame lista);
void liberta_lista(pgame lista);





void remove_file(char file_name[]);
int get_size(char file_name[]);
int modo_jogo_antes(char file_name[]);
int verifica_jogo_antes(char file_name[],int jogo_antes);
pgame recupera_jogo(char file_name[],Array *p,pgame lista);
pgame recupera_lista(pgame lista,FILE *file);
Array* recupera_array(Array *p,pgame lista);
void escreve_lista_a_file(pgame lista);




#endif

