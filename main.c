#include <stdio.h>
#include <stdlib.h>
#include "getch/getch.h"
#include "menu/menu.h"


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
