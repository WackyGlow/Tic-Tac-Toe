#include "grid.h"
#include "game_logic.h"

void drawGrid(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White grid lines
    for (int i = 1; i < GRID_SIZE; ++i) {
        SDL_RenderDrawLine(renderer, i * CELL_WIDTH, 0, i * CELL_WIDTH, 600);
        SDL_RenderDrawLine(renderer, 0, i * CELL_HEIGHT, 600, i * CELL_HEIGHT);
    }

    SDL_RenderPresent(renderer); // Render the grid
}

int getCellFromClick(int x, int y, int* row, int* col) {
    if (x < 0 || x >= 600 || y < 0 || y >= 600) return 0; // Invalid click
    *row = y / CELL_HEIGHT;
    *col = x / CELL_WIDTH;
    return 1;
}

void renderBoard(SDL_Renderer* renderer) {
    // Loop through the board and render X and O
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            if (board[row][col] == 'X') {
                // Render X (two crossing lines)
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red
                int x1 = col * CELL_WIDTH + 10;
                int y1 = row * CELL_HEIGHT + 10;
                int x2 = (col + 1) * CELL_WIDTH - 10;
                int y2 = (row + 1) * CELL_HEIGHT - 10;
                SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
                SDL_RenderDrawLine(renderer, x1, y2, x2, y1);
            }
            else if (board[row][col] == 'O') {
                // Render O (circle)
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); // Blue
                int centerX = col * CELL_WIDTH + CELL_WIDTH / 2;
                int centerY = row * CELL_HEIGHT + CELL_HEIGHT / 2;
                int radius = CELL_WIDTH / 3;
                for (int w = 0; w < radius * 2; w++) {
                    for (int h = 0; h < radius * 2; h++) {
                        int dx = radius - w;
                        int dy = radius - h;
                        if ((dx * dx + dy * dy) <= (radius * radius) &&
                            (dx * dx + dy * dy) >= ((radius - 2) * (radius - 2))) {
                            SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
                            SDL_RenderDrawPoint(renderer, centerX - dx, centerY - dy);
                        }
                    }
                }
            }
        }
    }
    SDL_RenderPresent(renderer); // Ensure the rendering is updated on screen
}