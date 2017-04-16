#include <ncurses.h>
#include "vector.h"
#include "terminal.h"

void term_init()
{
  initscr();
  
  timeout(-1);
  cbreak();
  noecho();
  intrflush(stdscr, false);
  keypad(stdscr, true);
}

void term_draw(Vector *v)
{
  char curchar;
  int curline = 0;

  for(int i = 0; i < v->size; i++) {
    curchar = vector_get(v, i);
    if(curchar == '\n') {
      curline++;
    } else {
      move(curline, i);
      addch(curchar);
    }

  }

  refresh();
}

void term_update(Vector *v)
{
  int c = getch(); //term_get_input();

  vector_append(v, (char)c);
}

int term_get_input()
{
  int c = getch();
  return c;
}

void term_end()
{
  endwin();
}
