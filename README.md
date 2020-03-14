# C-Interface-Menu

this tiny project implements an iterative menu interface inside the terminal

```
→ Start

  Settings

  Exit
```

after downloading the project, at its root, run the compando below to compile the menu example:

```
In linux → gcc -o menu.out getch/getch.c menu/menu.c main.c
In Win   → gcc -o menu.out menu/menu.c main.c
```

and to test, just:

```
./menu.out
```
use os use the arrows `↑` and `↓` to navigate through the menu

