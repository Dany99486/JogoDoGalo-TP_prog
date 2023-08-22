
#include "main_header.h"


int game(Array *p,int n_p,pgame lista,char file_name[],int ModoDeJogo,int jogo_antes){


    char mat_verifica[N][N]={"___","___","___"};
    int i,jogador=1,tab=4,n_jogadas=0,ganhou=0,tab_verifica;
    Array *aux =NULL;
    pgame list_aux;
    int flag=0;




    aux = realloc(p,sizeof(Array)* n_p);

    if(aux==NULL){
        printf("Ocorreu um erro na alocação de memória");
    }

    else{
        p=aux;
        for(i=0;i<=8;i++){
            p[i].point=criaMat(3,3);

        }
    }


    if(jogo_antes==1){
        lista=recupera_jogo(file_name,p,lista);

        p=recupera_array(p,lista);

        list_aux=lista;
        while(list_aux!=NULL){
            jogador = list_aux->jogador%2 + 1;
            n_jogadas=list_aux->num_jogada;
            tab=list_aux->pos;
            strcpy(mat_verifica,list_aux->mat_verifica);
            list_aux=list_aux->prox;

        }
        tab--;
    }


    board(p);
    do{







        if(flag==0)
            tab_verifica=tab;

            tab=escolhe_jogada(p[tab].point,jogador,tab,ModoDeJogo,&tab_verifica,&flag);

        if(flag==0){


            n_jogadas++;

            if(linha(p[tab_verifica].point)==1 || coluna(p[tab_verifica].point)==1 || diag(p[tab_verifica].point)==1 || preenchido(p[tab_verifica].point)==1){
                if(preenchido(p[tab_verifica].point)==1){
                    mat_verifica[tab_verifica/N][tab_verifica%N]='E';
                }
                else{
                    if(jogador==1){
                        mat_verifica[tab_verifica/N][tab_verifica%N]='X';
                    }
                    else{
                        mat_verifica[tab_verifica/N][tab_verifica%N]='O';
                    }
                }

            }

            lista=atualiza_lista(lista,file_name,mat_verifica,(tab_verifica+1),(tab+1),jogador,n_jogadas,ModoDeJogo);

            if(linha_verifica(mat_verifica)==1 || coluna_verifica(mat_verifica)==1 || diag_verifica(mat_verifica)==1 )
                ganhou = jogador;
            else
                jogador = jogador%2 + 1;
            if(jogador==1||(jogador==2 && ModoDeJogo==1)){
                board(p);

                if(n_jogadas>=10 && ganhou==0){
                    ver_jogadas(lista);
                }
            }

        }
        flag=0;

    }while(ganhou==0 && n_jogadas < N*N*N*N);

    remove(file_name);
    escreve_resultado(ganhou);
    escreve_lista_a_file(lista);
    free(p);
    liberta_lista(lista);

    return 0;
    }
