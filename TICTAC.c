#include <stdio.h>

#define BOARD_SIZE 3

void printBoard(char boardTable[3][3]){
    printf("%c|%c|%c \n",boardTable[0][0],boardTable[0][1],boardTable[0][2]);
    printf("----- \n");
    printf("%c|%c|%c \n",boardTable[1][0],boardTable[1][1],boardTable[1][2]);
    printf("----- \n");
    printf("%c|%c|%c \n", boardTable[2][0], boardTable[2][1], boardTable[2][2]);
}
char makePlay(int player, int coordx, int coordy, char boardTable[3][3]){

    if (player == 1) {

        if (boardTable[coordy-1][coordx-1] == 'X' || boardTable[coordy-1][coordx-1] == 'O') {
            printf("This space is already occupied \n");
            return 'N';
        }
        
        boardTable[coordy-1][coordx-1] = 'X';
        return boardTable[3][3];
    }else {

        if (boardTable[coordy-1][coordx-1] == 'X' || boardTable[coordy-1][coordx-1] == 'O') {
            printf("This space is already occupied \n");
            return 'N';
        }

        boardTable[coordy-1][coordx-1] = 'O';
        return boardTable[3][3];
    }
    
}

void setCoords (int player, int *coordx, int *coordy) {
    char character;
    if (player == 0) {
        character = 'X';
    } else {
        character = 'O';
    }
    do {
        printf("Player %d: set coordinates for your %c \n", player + 1, character);
        printf("Coordinate X (1-%d):\n", BOARD_SIZE);
        if (scanf("%d", coordx) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }
        printf("Coordinate Y (1-%d):\n", BOARD_SIZE);
        if (scanf("%d", coordy) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear the input buffer
            continue;
        }

        if (*coordx < 1 || *coordx > BOARD_SIZE || *coordy < 1 || *coordy > BOARD_SIZE) {
            printf("Invalid coordinates. Use numbers between 1 and %d.\n", BOARD_SIZE);
        }
    } while (*coordx < 1 || *coordx > BOARD_SIZE || *coordy < 1 || *coordy > BOARD_SIZE);
}

int tictacWin(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return 1;
    }
    return 0;
}

int main()
{
    int player = 0;
    int coordx = '0';
    int coordy = '0';
    char board[3][3]= {
        {'-','-','-'},
        {'-','-','-'},
        {'-','-','-'}
    };
    printBoard(board);
    for (int i = 0; i < 8; i++) {

        do {
            setCoords(player,&coordx, &coordy);
            board[3][3] = makePlay(player + 1 ,coordx, coordy, board);
        } while (board[3][3] == 'N');
        
        printBoard(board);
        if (tictacWin(board) == 1)
        {
            printf("Yay Player 1 won!");
            return 0;
        }else if(tictacWin(board) == 2) {
            printf("Yay Player 2 won!");
            return 0;
        }
         
        player = (player + 1) % 2;

    }
    return 0;
}