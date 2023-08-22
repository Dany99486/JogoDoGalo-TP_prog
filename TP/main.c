
#include "main_header.h"

int main(int argc, char** argv)
{
    int opt,jogo_antes=0;
    Array *p = NULL;
    int n_p =9;

    pgame lista = NULL;

    char filename[] = "jogo.bin";


    jogo_antes=verifica_jogo_antes(filename,jogo_antes);



    printf("->");
    do{
        if(jogo_antes==0)
            opt=menu();
        else
            opt=modo_jogo_antes(filename);

        do{
            switch(opt){

                case MULTIPLAYER:
                    game(p,n_p,lista,filename,MULTIPLAYER,jogo_antes);
                    opt=menu();

                    break;

                case SINGLEPLAYER:
                    game(p,n_p,lista,filename,SINGLEPLAYER,jogo_antes);
                    opt=menu();

                    break;
                case GAMEOVER:

                    return 0;
                    break;
            }
        }while(opt<3);

    }while(opt != GAMEOVER);


    return 0;
}
