
#include "main_header.h"

pgame atualiza_lista(pgame lista,char file_name[],char mat_verifica[9],int tab_plus,int pos,int jogador,int n_jogadas,int ModoDeJogo){
    pgame atualizacao,aux;

    atualizacao = malloc(sizeof(game_list));
    if(atualizacao == NULL)
    {   printf("Erro na alocacao de memoria\n");
        return lista;}

    FILE *file;
    file = fopen(file_name, "ab");
    if(file==NULL)
        printf("Erro na abertura do ficheiro");



    atualizacao->tab = tab_plus;
    atualizacao->pos = pos;
    atualizacao->jogador = jogador;
    atualizacao->num_jogada = n_jogadas;

    atualizacao->ModoDeJogo=ModoDeJogo;
    mat_verifica[9]='\0';
    strcpy(atualizacao->mat_verifica,mat_verifica);
    atualizacao->prox = NULL;

    fseek(file,0,SEEK_END);
    fwrite(atualizacao,sizeof(game_list),1,file);

    fclose(file);





    if(lista==NULL){
        lista=atualizacao;

    }
    else{
        aux=lista;
        while(aux->prox!=NULL){
            aux=aux->prox;
        }
        if(aux->prox==NULL){
            aux->prox=atualizacao;
        }
    }



    return lista;
}

void ver_jogadas(pgame lista){
    pgame aux;
    aux=lista;
    int ult_jogada;
    char menu_antes;

    printf("\nDeseja ver as dez jogadas anteriores?(S/N)\n->");
    scanf(" %c",&menu_antes);



    if(menu_antes=='s'||menu_antes=='S'){

        while(aux->prox!=NULL){
            aux=aux->prox;
        }

        ult_jogada=aux->num_jogada;



        printf("----- Jogadas Anteriores ------------------------------------\n");
        for(int i=ult_jogada-9;i<=ult_jogada;i++){
            aux=lista;

            while(aux->num_jogada!=i){
                aux=aux->prox;
            }
            printf("O jogador %d efetuou a jogada %d, no tabuleiro %d\n",aux->jogador,aux->pos,aux->tab);
        }
        printf("-------------------------------------------------------------\n\n");

    }

}
void liberta_lista(pgame lista)
{
    pgame aux;
    while(lista != NULL)
    {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}







void remove_file(char file_name[]){

    int ret;
    ret =remove(file_name);

   if(ret == 0) {
      printf("File deleted successfully");
   } else {
      printf("Error: unable to delete the file");
   }
}

int get_size(char file_name[])
{
    FILE *file = fopen(file_name, "rb");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}
int modo_jogo_antes(char file_name[]){

    pgame atualizacao;

    FILE *file=fopen(file_name,"rb");
    if(file == NULL)
        return 0;

    fread(atualizacao,sizeof(game_list),1,file);

    return atualizacao->ModoDeJogo;
    fclose(file);

}


int verifica_jogo_antes(char file_name[],int jogo_antes){

    char recup;
    int ret;



    if(get_size(file_name) != 0){
        printf("Deseja continuar o jogo anterior?(S/N) \n-->");
        scanf("%c",&recup);
        if(recup=='S'||recup=='s'){

            return 1;

        }
        else{
            ret =remove(file_name);
            if(ret != 0)
                printf("Error: unable to delete the file");

        }


    }

}

pgame recupera_lista(pgame lista,FILE *file){

    pgame atualizacao,aux;
    atualizacao = malloc(sizeof(game_list));
    if(atualizacao == NULL)
    {   printf("Erro na alocacao de memoria\n");
        return lista;}


    fread(atualizacao,sizeof(game_list),1,file);

    if(lista==NULL){

        lista=atualizacao;

    }
    else{

        aux=lista;
        while(aux->prox!=NULL){

            aux=aux->prox;

        }
        if(aux->prox==NULL){

            aux->prox=atualizacao;

        }
    }

    return lista;


}

Array* recupera_array(Array *p,pgame lista){

    pgame aux;
    aux=lista;


    while(aux!= NULL){



        if(aux->jogador==1)
            setPos(p[aux->tab-1].point,(aux->pos-1)%N,(aux->pos-1)/N,'X');
        else
            setPos(p[aux->tab-1].point,(aux->pos-1)%N,(aux->pos-1)/N,'O');

        aux=aux->prox;

    }
    return p;
}

pgame recupera_jogo(char file_name[],Array *p,pgame lista){
    FILE *file;
    file = fopen(file_name, "rb");

    if(file == NULL)
        printf("Erro a abrir ficheiro");


    fseek(file,0,SEEK_END);
    long fileSize = ftell(file);
    fseek(file,0,SEEK_SET);
    int num_entradas = (int)(fileSize/sizeof(game_list));
    for(int i=0;i<num_entradas;i++){
        fseek(file,sizeof(game_list)*i,SEEK_SET);
        lista=recupera_lista(lista,file);


    }


    fclose(file);
    return lista;
}





void escreve_lista_a_file(pgame lista){
    char name[15];
    char bin[]=".bin";
    pgame aux;
    FILE *file;
    aux=lista;
    if(file == NULL)
        return 0;

    printf("Coloque o seu primeiro nome\n->");
    scanf("%s",name);
    strcat(name,bin);

    file = fopen(name, "ab");
    while(aux!=NULL){

        fseek(file,0,SEEK_END);
        fwrite(aux,sizeof(game_list),1,file);
        aux=aux->prox;
    }

    fclose(file);
}


