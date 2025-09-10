#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include "snakePlayer.h"

// Renderiza grid + cobra na tela
void render(const std::vector<std::vector<char>> &grid, const Snake &player);

#endif
