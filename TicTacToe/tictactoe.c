#include <stdio.h>
#include <stdbool.h>
#include "board.h"
#include "player.h"

int main() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '},
                               {' ', ' ', ' '},
                               {' ', ' ', ' '} };

    char currentPlayer = 'X';

    printf("Welcome to Tic-Tac-Toe!\n");

    while (true) {
        displayBoard(board);
        playerMove(board, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}