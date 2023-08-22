#ifndef MINIJOGO_H
#define MINIJOGO_H

#define N 3



int MiniJogo();

void inicializa_tab(int *p);

int escolhe_jogada(int *p, int jogador,int tab,int ModoDeJogo,int *tab_verifica,int *flag);

int diag(int *p);
int diag_grande(int *p);

int coluna(int *p);
int coluna_grande(int *p);

int linha(int *p);
int linha_grande(int *p);

int preenchido(int *p);

void escreve_resultado(int ganhou);

void escreve_tab(char t[][N]);




#endif
