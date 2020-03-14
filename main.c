#include <stdio.h>
#include <stdlib.h>
#include "menu/menu.h"

#ifdef __linux__
#include "getch/getch.h" // Biblioteca para linux
#endif


Menu menu;

void hello(void){
  printf("Hello World");
  getch();
}

void exiting(void){
  exitMenu(&menu);
}

int main(){

  createMenu(&menu);

  createOptionMenu("Print Hello World",&hello, &menu);
  createOptionMenu("Print Hello World",&hello, &menu);
  createOptionMenu("Print Hello World",&hello, &menu);
  createOptionMenu("Exit Menu", &exiting, &menu);

  menuLoop(&menu);

  return 0;
}
