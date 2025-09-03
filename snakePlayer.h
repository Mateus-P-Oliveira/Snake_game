#ifndef SNAKEPLAYER_H
#define SNAKEPLAYER_H

#include <deque>
#include <utility> // std::pair

class Snake {
private:
    std::deque<std::pair<int,int>> body; // corpo da cobra (lista de posições)
    bool alive;
    int food;

public:
    Snake(int startY, int startX);

    void move(int dy, int dx);       // move a cobra na direção
    void grow();                     // aumenta de tamanho
    bool isAlive() const;            // retorna estado da cobra
    std::pair<int,int> getHead() const; // posição da cabeça
    const std::deque<std::pair<int,int>>& getBody() const; // acesso ao corpo
};

#endif
