#include "snakePlayer.h"

Snake::Snake(int startY, int startX)
{
    body.push_back({startY, startX}); // começa com 1 célula
    alive = true;
    food = 0;
}

void Snake::move(int dy, int dx, bool grow)
{
    if (!alive)
        return;

    // nova posição da cabeça
    auto head = body.front();
    auto newHead = std::make_pair(head.first + dy, head.second + dx);
    // int newY = head.first + dy;
    // int newX = head.second + dx;

    //   checa colisão com o próprio corpo
    for (size_t i = 1; i < body.size(); i++)
    {
        if (body[i] == newHead)
        {
            alive = false; // morreu
            return;
        }
    }

    body.insert(body.begin(), newHead); // adiciona cabeça

        // remove cauda (se não comeu)
    if (!grow)
    {
        body.pop_back(); // remove cauda se não crescer
    }
}

void Snake::grow()
{
    food++;
    // duplicar último segmento (cresce 1 unidade)
    body.push_back(body.back());
}

bool Snake::isAlive() const
{
    return alive;
}

std::pair<int, int> Snake::getHead() const
{
    return body.front();
}

const std::deque<std::pair<int, int>> &Snake::getBody() const
{
    return body;
}
