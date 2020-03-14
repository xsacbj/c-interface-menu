#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

#ifdef __linux__
#include "../getch/getch.h" // Biblioteca para linux
#endif

void debug(char* log){
  printf("%s\n", log);
}

void createMenu(Menu *menu){

  if(menu == NULL){
    debug("Menu not Created");
    return;
  }

  menu->options = NULL;
  menu->max_option = 0;
  menu->selected_option = -1;
  menu->exit = FALSE;

}

void createOptionMenu(char *description, Function *function, Menu *menu){
  Option *new_option, *new_options;

  if(menu == NULL){
    debug("Please create a Menu");
    return;
  }
  if(description == NULL){
    debug("Option with no description");
    return;
  }

  new_option = malloc(sizeof(Option));
  new_option->description = description;
  new_option->function = function;

  new_options = malloc(sizeof(Option) * (menu->max_option + 1));

  for(int index=0; index<menu->max_option; index++){
    new_options[index] = menu->options[index];
  }

  new_options[menu->max_option] = *new_option;

  menu->options = new_options;
  menu->max_option++;

}

int isRunning(Menu *menu){
  if(menu->exit){
    return FALSE;
  }
  return TRUE;
}

void exitMenu(Menu *menu){
  menu->exit = TRUE;
}

void clear(){
    system("clear||cls");
}

void menuKeyImput(Menu *menu){
  char key = getch();
  switch(key){
    case ARROW_UP: // Arrow up ↑
      menu->selected_option--;
      if(menu->selected_option<0){
        menu->selected_option = menu->max_option-1;
      }
      break;
    case ARROW_DOWN: // Arrow Down ↓
      menu->selected_option++;
      if(menu->selected_option>=menu->max_option){
        menu->selected_option = 0;
      }
      break;
    case ENTER: // ↲ Enter
      clear();
      menu->options[menu->selected_option].function();
      break;
  }
  
}

void menuLoop(Menu *menu){

  clear();

  if(menu->selected_option == -1) menu->selected_option = 0;

  while(isRunning(menu)){
    for(int index=0; index<menu->max_option; index++){
      printf("%s %s\n", 
            menu->selected_option==index?"→":" ",
            menu->options[index].description);
    }

    menuKeyImput(menu);

    clear();

  }

}
