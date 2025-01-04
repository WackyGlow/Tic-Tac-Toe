#ifndef BOARD_H
#define BOARD_H

#define SIZE 3 // Size of the Tic-Tac-Toe board

// Function declarations
void displayBoard(char board[SIZE][SIZE]);
bool checkWin(char board[SIZE][SIZE], char player);
bool checkDraw(char board[SIZE][SIZE]);

#endif