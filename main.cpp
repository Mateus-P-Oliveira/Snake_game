#include <iostream>
#include <curses.h>
#include "render.h"


int main(){	
  bool inputReceived = false;
  //First Render of the game
  
  render(true);
  
  while(true){ 
    render(inputReceived);
  }	

  return 0;
}