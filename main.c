#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"

#ifdef __linux__
#include "getch/getch.h" // Biblioteca para linux
#endif


Menu menu;

void doNothing(void){
  printf("Press any key to back");
  getch();
}

void exiting(void){
  exitMenu(&menu);
}

int main(){

  createMenu(&menu);

  createOptionMenu("Start",&doNothing, &menu);
  createOptionMenu("Settings",&doNothing, &menu);
  createOptionMenu("Exit", &exiting, &menu);

  menuLoop(&menu);

  return 0;
}
