#include <ncurses.h>
#include "vector.h"
#include "terminal.h"

void term_init()
{
  initscr();
  
  timeout(5);
  cbreak();
  noecho();
  intrflush(stdscr, false);
  keypad(stdscr, true);
}

void term_draw(Vector *v)
{
  refresh();
  for(int i = 0; i < v->size; i++) {
    move(1, i);
    addch(vector_get(v, i));
  }
}

void term_update()
{
  
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
