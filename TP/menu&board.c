#include "main_header.h"

void board(int *p){

    printf("Tic Tac Toe \n");
    printf("\n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[0],0,0),getPos(p[0],1,0),getPos(p[0],2,0),  getPos(p[1],0,0),getPos(p[1],1,0),getPos(p[1],2,0), getPos(p[2],0,0),getPos(p[2],1,0),getPos(p[2],2,0) );
    printf(" ---|---|---  |  ---|---|---  |  ---|---|--- \n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[0],0,1),getPos(p[0],1,1),getPos(p[0],2,1),  getPos(p[1],0,1),getPos(p[1],1,1),getPos(p[1],2,1), getPos(p[2],0,1),getPos(p[2],1,1),getPos(p[2],2,1) );
    printf(" ---|---|---  |  ---|---|---  |  ---|---|--- \n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[0],0,2),getPos(p[0],1,2),getPos(p[0],2,2),  getPos(p[1],0,2),getPos(p[1],1,2),getPos(p[1],2,2), getPos(p[2],0,2),getPos(p[2],1,2),getPos(p[2],2,2) );
    printf("              |               |              \n");
    printf("--------------|---------------|--------------\n");
    printf("              |               |              \n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[3],0,0),getPos(p[3],1,0),getPos(p[3],2,0),  getPos(p[4],0,0),getPos(p[4],1,0),getPos(p[4],2,0), getPos(p[5],0,0),getPos(p[5],1,0),getPos(p[5],2,0) );
    printf(" ---|---|---  |  ---|---|---  |  ---|---|--- \n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[3],0,1),getPos(p[3],1,1),getPos(p[3],2,1),  getPos(p[4],0,1),getPos(p[4],1,1),getPos(p[4],2,1), getPos(p[5],0,1),getPos(p[5],1,1),getPos(p[5],2,1) );
    printf(" ---|---|---  |  ---|---|---  |  ---|---|--- \n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[3],0,2),getPos(p[3],1,2),getPos(p[3],2,2),  getPos(p[4],0,2),getPos(p[4],1,2),getPos(p[4],2,2), getPos(p[5],0,2),getPos(p[5],1,2),getPos(p[5],2,2) );
    printf("              |               |              \n");
    printf("--------------|---------------|--------------\n");
    printf("              |               |              \n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[6],0,0),getPos(p[6],1,0),getPos(p[6],2,0),  getPos(p[7],0,0),getPos(p[7],1,0),getPos(p[7],2,0), getPos(p[8],0,0),getPos(p[8],1,0),getPos(p[8],2,0) );
    printf(" ---|---|---  |  ---|---|---  |  ---|---|--- \n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[6],0,1),getPos(p[6],1,1),getPos(p[6],2,1),  getPos(p[7],0,1),getPos(p[7],1,1),getPos(p[7],2,1), getPos(p[8],0,1),getPos(p[8],1,1),getPos(p[8],2,1) );
    printf(" ---|---|---  |  ---|---|---  |  ---|---|--- \n");
    printf("  %c | %c | %c   |   %c | %c | %c   |   %c | %c | %c  \n",getPos(p[6],0,2),getPos(p[6],1,2),getPos(p[6],2,2),  getPos(p[7],0,2),getPos(p[7],1,2),getPos(p[7],2,2), getPos(p[8],0,2),getPos(p[8],1,2),getPos(p[8],2,2) );
}
int menu(){
    int opt;

    printf("Escolha o modo de jogo:\n");
    printf(" 1-Multiplayer \n");
    printf(" 2-Singleplayer \n");
    puts(" 3-Exit \n");
    printf("->");
    scanf("%d",&opt);

    return opt;
}


