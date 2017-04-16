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
  for(int i = 0; i < v->size; i++) {
    move(1, i);
    addch(vector_get(v, i));
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
