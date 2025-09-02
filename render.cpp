#include "render.h"
#include <curses.h>
#include <vector>

void render(const std::vector<std::vector<char>>& grid) {
    // Limpa tela antes de redesenhar
    clear();

    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            mvaddch(y, x, grid[y][x]);
        }
    }

    refresh(); // Atualiza a tela
}

