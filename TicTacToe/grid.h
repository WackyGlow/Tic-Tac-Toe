#ifndef GRID_H
#define GRID_H

#include <SDL.h>

#define GRID_SIZE 3
#define CELL_WIDTH (600 / GRID_SIZE)
#define CELL_HEIGHT (600 / GRID_SIZE)

// Function prototypes
void drawGrid(SDL_Renderer* renderer);
int getCellFromClick(int x, int y, int* row, int* col);
void renderBoard(SDL_Renderer* renderer);

#endif