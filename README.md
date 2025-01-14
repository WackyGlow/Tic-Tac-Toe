# Tic-Tac-Toe with SDL2

## Overview
This is a simple Tic-Tac-Toe game developed in **C** using **SDL2** for rendering. Players take turns placing their marks (`X` or `O`) on a 3x3 grid until one player wins or the game ends in a draw.

## Features
- 2-player gameplay.
- Interactive graphical grid using SDL2.
- Smooth rendering of `X` and `O` with color differentiation.
- Detects win and draw conditions.

## Requirements
- **SDL2 Library** (version 2.30.11 or compatible).
- A C compiler supporting SDL2 (e.g., GCC, Clang, or Visual Studio).

## Setup Instructions

### Prerequisites
1. Download and install SDL2 from [SDL2's official website](https://www.libsdl.org/download-2.0.php).
2. Ensure the SDL2 development library (headers and `.lib` files) is correctly linked in your project.
3. Copy the `SDL2.dll` file to your build directory (next to the executable).

### Building the Project
1. Clone the repository:
   ```bash
   git clone https://github.com/WackyGlow/Tic-Tac-Toe.git
   cd Tic-Tac-Toe
   ```
2. Open the project in your preferred IDE (e.g., Visual Studio).
3. Link the following SDL2 libraries:
   - `SDL2.lib`
   - `SDL2main.lib`
4. Build and run the project.

## How to Play
1. Run the game executable.
2. The grid is displayed in a 600x600 SDL2 window.
3. Players take turns clicking on the grid to place their marks (`X` and `O`).
4. The game ends when:
   - A player wins by placing three marks in a row (horizontally, vertically, or diagonally).
   - The board is full, resulting in a draw.
5. Restart the game by re-running the executable (restart feature coming soon!).

## Project Structure
- **`main.c`**: Handles game initialization and the main game loop.
- **`grid.c`/`grid.h`**: Manages rendering of the grid and board.
- **`game_logic.c`/`game_logic.h`**: Implements game logic (win/draw detection, player moves).
- **`SDL2.dll`**: Required runtime library for SDL2.

## Future Improvements
- Highlight winning lines.
- Add a restart button.
- Single-player mode with basic AI.
- Sound effects for moves and winning.
