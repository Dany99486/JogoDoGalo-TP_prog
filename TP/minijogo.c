
#include "main_header.h"


void escreve_tab(char t[][N])
{
	int i, j;

	printf("\n\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
			printf(" %c ", t[i][j]);
		putchar('\n');
	}
}

void escreve_resultado(int ganhou)
{
	if(ganhou == 0)
		printf("\nEmpate\n\n");
	else
		printf("\nGanhou o jogador %d\n\n", ganhou);
}


int linha_verifica(char t[][N])
{
	int i, j;

	for(i=0; i<N; i++)
		if(t[i][0] != '_' && t[i][0] != 'E'){
			for(j=0; j<N-1 && t[i][j] == t[i][j+1]; j++)
				;
			if(j==N-1)
				return 1;
		}
	return 0;
}


int linha_grande(int *p)
{


	if(  ( linha(p[0])==1 || coluna(p[0])==1 || diag(p[0])==1 )  &&  ( linha(p[1])==1 || coluna(p[1])==1 || diag(p[1])==1 ) == ( linha(p[0])==1 || coluna(p[0])==1 || diag(p[0])==1 )  &&  ( linha(p[2])==1 || coluna(p[2])==1 || diag(p[2])==1 ) == ( linha(p[0])==1 || coluna(p[0])==1 || diag(p[0])==1 ) )
        return 1;
    else if( linha(p[3])==1  &&  linha(p[3])== linha(p[4])  &&  linha(p[4])==linha(p[5]) )
        return 1;
    else if( linha(p[6])==1  &&  linha(p[6])== linha(p[7])  &&  linha(p[7])==linha(p[8]) )
        return 1;

    return 0;

}



int linha(int *p)
{
	int i, j;

	for(i=0; i<N; i++)
		if(getPos(p,i,0) != '_'){
			for(j=0; j<3-1 && getPos(p,i,j) == getPos(p,i,j+1); j++)
				;
			if(j==N-1)
				return 1;
		}
	return 0;
}



int coluna_verifica(char t[][N])
{
		int i, j;

	for(j=0; j<N; j++)
		if(t[0][j] != '_'&&t[0][j] != 'E'){
			for(i=0; i<N-1 && t[i][j] == t[i+1][j]; i++)
				;
			if(i==N-1){
				return 1;
			}

		}
	return 0;
}



int coluna(int *p)
{
		int i, j;

	for(j=0; j<N; j++)
		if(getPos(p,0,j)!= '_'){
			for(i=0; i<N-1 && getPos(p,i,j) == getPos(p,i+1,j); i++)
				;
			if(i==N-1){
				return 1;
			}

		}
	return 0;
}

int coluna_grande(int *p)
{
	if( linha(p[0])==1  &&  linha(p[3])== linha(p[0])  &&  linha(p[6])==linha(p[0]) )
        return 1;
    else if( linha(p[1])==1  &&  linha(p[4])== linha(p[1])  &&  linha(p[7])==linha(p[1]) )
        return 1;
    else if( linha(p[2])==1  &&  linha(p[5])== linha(p[2])  &&  linha(p[8])==linha(p[2]) )
        return 1;

    return 0;
}



int diag_verifica(char t[][N])
{
		int i,j;

    if((t[0][0]!= '_' )&& t[0][0] != 'E'  && (t[0][N-1]!='_') && t[0][N-1] != 'E' ){
        for(i=0,j=0;i<N-1 && t[i][j]== t[i+1][j+1];i++,j++)
            ;
        if(i==N-1)
            return 1;

        for(i=0,j=N-1;i<N-1 && t[i][j]== t[i+1][j-1];i++,j--)
            ;
        if(i==N-1)
            return 1;

    }
    return 0;
}



int diag(int *p)
{
		int i,j;

    if(getPos(p,0,0)!= '_'){
        for(i=0,j=0;i<N-1 && getPos(p,i,j)== getPos(p,i+1,j+1);i++,j++)
            ;
        if(i==N-1)
            return 1;
    }

    if(getPos(p,0,N-1)!= '_'){
        for(i=0,j=N-1;i<N-1 && getPos(p,i,j)== getPos(p,i+1,j-1);i++,j--)
            ;
        if(i==N-1)
            return 1;

    }
    return 0;
}


int diag_grande(int *p)
{

	if( linha(p[0])==1  &&  linha(p[4])== linha(p[0])  &&  linha(p[8])==linha(p[0]) )
        return 1;
    if( linha(p[2])==1  &&  linha(p[4])== linha(p[2])  &&  linha(p[6])==linha(p[2]) )
        return 1;

    return 0;
}
int preenchido(int *p){

    for(int j=0;j<N;j++){
        for(int i=0;i<N;i++)
            if(getPos(p,i,j)=='_')
                return 0;
    }
    return 1;
}



int escolhe_jogada(int *p, int jogador,int tab,int ModoDeJogo,int *tab_verifica,int *flag)
{
	int pos;


    if(linha(p)==1 || coluna(p)==1 || diag(p)==1 || preenchido(p)==1){

        if(tab==8){

            *flag=1;
            *tab_verifica=0;
            return 0;
        }
        else{

            *flag=1;
            *tab_verifica++;
            return tab+1;
        }


    }


    if(jogador==2 && ModoDeJogo==2){

        pos=intUniformRnd(1,9);
        while(getPos(p,(pos-1)%N,(pos-1)/N) != '_'){
            if(pos==9)
                pos=1;
            else
                pos++;                }

        setPos(p,(pos-1)%N,(pos-1)/N,'O');
    }
    else{
        do{
            printf("\nE a vez do jogador %d no tabuleiro %d\n", jogador,tab+1);
            printf("Posição: ");
            scanf(" %d", &pos);
        }while(pos<1 || pos>N*N || getPos(p,(pos-1)%N,(pos-1)/N) != '_');
        if(jogador == 1)
			setPos(p,(pos-1)%N,(pos-1)/N,'X');
		else
			setPos(p,(pos-1)%N,(pos-1)/N,'O');
    }

    tab=pos-1;
    return tab;
}





void inicializa_tab(int *p)
{
    int i,j;

	for(i=0; i<N*N; i++)
		for(j=0; j<N*N; j++)
			*((p+i)+j)= '_';
}





