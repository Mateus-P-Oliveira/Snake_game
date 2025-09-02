#include <curses.h>
#include "render.h"
#include <vector>
using namespace std;

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    // Cria grid 20x10 inicial
    vector<vector<char>> grid(10, vector<char>(20, ' '));

    // Adiciona paredes
    for (int x = 0; x < 20; x++) {
        grid[0][x] = '#';
        grid[9][x] = '#';
    }
    for (int y = 0; y < 10; y++) {
        grid[y][0] = '#';
        grid[y][19] = '#';
    }

    // Coloca comida e cobra
    grid[5][10] = 'X';   // comida
    grid[5][5] = 'O';    // cobra

    // Desenha
    render(grid);

    getch();  // espera tecla
    endwin();
    return 0;
}
