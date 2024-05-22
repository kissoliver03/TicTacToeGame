#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char PLAYER = 'X';
const char COMPUTER = 'O';
char tablahelyek[3][3];
char Winner = ' ';


void reset();
void printtabla();
void printWinner();
void playerMove();
void computerMove();
int checkFreeSpaces();
char checkWinner();




int main(){
    char choice = 'Y';
    char answer;

    do {
        printf("You are X!\n");
        reset();
        while (checkFreeSpaces() != 0 && Winner == ' ') {
            printtabla();
            playerMove();
            Winner = checkWinner();
            if (Winner != ' ') {                   //van nyertesunk (player)
                printtabla();
                printWinner();
            }
            else {
                computerMove();
                Winner = checkWinner();
                if (Winner != ' ') {                   //van nyertesünk (computer)
                    printtabla();
                    printWinner();
                }
            }
        }
        do {
            printf("Do you want to play again? (Y/N)\n");
            scanf("%s", &choice);
        }
        while(choice != 'Y' && choice != 'N');
        answer = choice;
        if(answer == 'N'){
            return 0;
        }
    }
    while(answer == 'Y');
}





void printtabla(){
    printf(" %c | %c | %c", tablahelyek[0][0], tablahelyek[0][1], tablahelyek[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", tablahelyek[1][0], tablahelyek[1][1], tablahelyek[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c\n", tablahelyek[2][0], tablahelyek[2][1], tablahelyek[2][2]);
    printf("               \n");
    printf("               \n");
}

void reset(){
    int i;
    int j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            tablahelyek[i][j] = ' ';
        }
    }
    Winner = ' ';
}

char checkWinner() {
    //check rows
    int i;
    for (i = 0; i < 3; i++) {
            if (tablahelyek[i][0] == tablahelyek[i][1] && tablahelyek[i][1] == tablahelyek[i][2] &&
                tablahelyek[i][0] == tablahelyek[i][2]) {
                return tablahelyek[i][0];
            }
    }

    //check columns
    int j;
    for (j = 0; j < 3; j++) {
            if (tablahelyek[0][j] == tablahelyek[1][j] && tablahelyek[1][j] == tablahelyek[2][j] &&
                tablahelyek[2][j] == tablahelyek[0][j]) {
                return tablahelyek[0][j];
            }
    }

    //check diagonals

        if ((tablahelyek[0][0] == tablahelyek[1][1] && tablahelyek[0][0] == tablahelyek[2][2] &&
             tablahelyek[1][1] == tablahelyek[2][2]) ||
            tablahelyek[0][2] == tablahelyek[1][1] && tablahelyek[0][2] == tablahelyek[2][0] &&
            tablahelyek[1][1] == tablahelyek[2][0]) {
            return tablahelyek[1][1];
        }
    return ' ';
}


void printWinner() {
    if (Winner == PLAYER) {
            printf("YOU WIN\n");
    } else if (Winner == COMPUTER) {
        printf("YOU LOST!\n");
    } else {
            printf("IT'S A DRAW!\n");
    }
}

void playerMove(){
    int x;
    int y;

    do{
        printf("\nWhere do you want to move? (1-3)\nRow=");
        scanf("%d", &x);
        x--;
        printf("Columns=");
        scanf("%d", &y);
        y--;

        if(tablahelyek[x][y] != ' '){
            printf("INVALID MOVE!");
        }
        else{
            tablahelyek[x][y] = PLAYER;
            break;
        }
    }
    while(tablahelyek[x][y] != ' ');


}

void computerMove(){
    srand(time(NULL));
    int randomx, randomy;

    if(checkFreeSpaces() > 0) {
        do {
            randomx = rand() % 3;
            randomy = rand() % 3;


        } while (tablahelyek[randomx][randomy] != ' ');

        tablahelyek[randomx][randomy] = COMPUTER;
    }
    else{
        printWinner();
    }
}

int checkFreeSpaces(){
    int freeSpace = 9;
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(tablahelyek[i][j] != ' '){
                freeSpace--;
            }
        }
    }
    return(freeSpace);
}