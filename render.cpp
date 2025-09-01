#include "render.h"
#include <iostream>
#include <curses.h>


void render(bool inputReceived) {
    if(inputReceived == true){
        //std::cout << "Desenhando frame..." << std::endl;
        for (int i = 5; i < 5+2; i++) {
            mvaddch(5, i, ' ' | A_REVERSE);
        }
    }
    

}
