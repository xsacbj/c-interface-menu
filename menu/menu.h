#ifndef MENU_H
#define MENU_H

#define TRUE 1
#define FALSE 0

#define ARROW_UP 65
#define ARROW_DOWN 66
#define ENTER 10

typedef void (Function)(void); 

typedef struct __option__
{
  char* description;
  Function* function; 
}Option;

typedef struct __menu__
{
  Option* options;
  int max_option;
  int selected_option;
  int exit;
}Menu;


void createMenu(Menu *menu);

void createOptionMenu(char *description, Function *function, Menu *menu);

void menuLoop(Menu *menu);

int isRunning(Menu *menu);

void menuKeyImput(Menu *menu);

void exitMenu(Menu *menu);

void debug(char* log);

#endif
