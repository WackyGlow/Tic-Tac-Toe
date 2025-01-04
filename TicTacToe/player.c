#include <stdio.h>
#include <stdbool.h>
#include "player.h"

// Handles player input and updates the board
void playerMove(char board[SIZE][SIZE], char player) {
	int row, col;

	while (true) {
		printf("Player %c, enter your move (row and column): ", player);
		scanf_s("%d %d", &row, &col);

		// Validate input
		if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
			board[row][col] = player;
			break;  // Exit the loop on a valid move
		}
		else {
			printf("Invalid move. Try again.\n");
		}
	}
}