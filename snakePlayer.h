#ifndef SNAKEPLAYER.H
#define SNAKEPLAYER.H

class Snake{
private:
    int food;
    bool life;
public:
    void eatFood(); //Responsable for eating food
    bool isAlive(bool impacat); //Test for the impact of the Snake on itself and the borders    
}




#endif
