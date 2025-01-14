#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#define GRID_SIZE 3

extern char board[GRID_SIZE][GRID_SIZE];

// Function prototypes
int handleMove(int row, int col, char player);
int checkWin(char player);

#endif