#include <stdio.h>
#include <stdbool.h>
#include "board.h"

// Displays the current game board
void displayBoard(char board[SIZE][SIZE]) {
	printf("\n");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf(" %c ", board[i][j]);
			if (j < SIZE - 1) printf("|");
		}
		printf("\n");
		if (i < SIZE - 1) printf("---+---+---\n");
	}
	printf("\n");
}

// Checks if the current player has won
bool checkWin(char board[SIZE][SIZE], char player) {
	for (int i = 0; i < SIZE; i++) {

		// Check row and columns
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
	}

	// Check diagonals
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

	return false;
}

// Checks if the game is a draw
bool checkDraw(char board[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == ' ') return false;  // Empty cell found, not a draw
		}
	}
	return true;
}