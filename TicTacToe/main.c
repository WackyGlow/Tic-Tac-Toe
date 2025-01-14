#include <SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include "grid.h"
#include "game_logic.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Tic-Tac-Toe",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);
    if (!window) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    char currentPlayer = 'X';
    bool running = true;

    // Main game loop
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int row, col;
                if (getCellFromClick(event.button.x, event.button.y, &row, &col)) {
                    if (handleMove(row, col, currentPlayer)) {
                        printf("Player %c wins!\n", currentPlayer);
                        running = false;
                    }
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }

        drawGrid(renderer);
        renderBoard(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}