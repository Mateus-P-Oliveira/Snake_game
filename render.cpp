#include "render.h"
#include <curses.h>

void render(const std::vector<std::vector<char>>& grid, const Snake& player) {
    clear();

    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[y].size(); x++) {
            mvaddch(y, x, grid[y][x]);
        }
    }

    for (auto [y, x] : player.getBody()) {
        mvaddch(y, x, 'O');
    }

    refresh();
}