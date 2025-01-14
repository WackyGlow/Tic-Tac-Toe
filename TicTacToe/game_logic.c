#include "game_logic.h"

char board[GRID_SIZE][GRID_SIZE] = { {' ', ' ', ' '},
                                     {' ', ' ', ' '},
                                     {' ', ' ', ' '} };

int handleMove(int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return checkWin(player);
    }
    return 0;
}

int checkWin(char player) {
    for (int i = 0; i < GRID_SIZE; i++) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    return (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player);
}