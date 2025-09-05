#include <curses.h>
#include <unistd.h> // usleep
#include <vector>
#include "snakePlayer.h"
#include "render.h"
#include <cstdlib>
#include <ctime>

using namespace std;
#define MY_KEY_UP 450
#define MY_KEY_DOWN 456
#define MY_KEY_LEFT 452
#define MY_KEY_RIGHT 454

std::pair<int,int> food;

// Gera comida aleatória em posição livre
std::pair<int,int> spawnFood(const Snake& player) {
    while (true) {
        int y = rand() % 20;
        int x = rand() % 80;

        // garantir que não cai dentro da cobra
        bool insideSnake = false;
        for (auto [sy, sx] : player.getBody()) {
            if (sy == y && sx == x) {
                insideSnake = true;
                break;
            }
        }
        if (!insideSnake) {
            return {y, x};
        }
    }
}




int main()
{
    srand(time(0));
    // --- Inicialização do curses ---
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);  // Mudar depois
    curs_set(0);

    nodelay(stdscr, TRUE); // não trava no getch()

    int height = 20, width = 80;

    // cria grid inicial
    vector<vector<char>> grid(height, vector<char>(width, ' '));

    // paredes
    for (int x = 0; x < width; x++)
    {
        grid[0][x] = '#';
        grid[height - 1][x] = '#';
    }
    for (int y = 0; y < height; y++)
    {
        grid[y][0] = '#'; 
        grid[y][width - 1] = '#';
    }

    // --- Cria a cobra ---
    Snake player(height / 2, width / 2);

    food = spawnFood(player);

    // direção inicial
    int dy = 0, dx = 0;

    // --- Loop principal ---
    while (player.isAlive())
    {
        // --- Input ---
        int ch = getch();

        if (ch != ERR)
        {
            switch (ch)
            {
            case MY_KEY_UP:
                dy = -1;
                dx = 0;
                break;
            case MY_KEY_DOWN:
                dy = 1;
                dx = 0;
                break;
            case MY_KEY_LEFT:
                dy = 0;
                dx = -1;
                break;
            case MY_KEY_RIGHT:
                dy = 0;
                dx = 1;
                break;
            case 'q':
                endwin();
                return 0;
            }
        }

        // --- Update ---
        auto head = player.getHead();
        bool grow = (head == food);
        player.move(dy, dx, grow);

         if (grow) {
            auto oldFood = food;
            food = spawnFood(player);
            grid[oldFood.first][oldFood.second] = ' '; // apaga 'X' antiga
            food = spawnFood(player);
        }
        // checa colisão com paredes
        //auto head = player.getHead();
        if (grid[head.first][head.second] == '#')
        {
            break; // morreu
        }

        

        grid[food.first][food.second] = 'X';
        // --- Render ---
        render(grid, player);

        // delay (100ms)
        usleep(100000);
    }

    // --- Fim do jogo ---
    clear();
    mvprintw(height / 2, (width / 2) - 5, "GAME OVER!");
    refresh();
    nodelay(stdscr, FALSE);
    getch();

    endwin();
    return 0;
}
