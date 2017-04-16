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
  int curchar;

  int i = 0;
  int x = 0;
  int y = 0;

  while(i < v->size) {
    curchar = vector_get(v, i);

    if(curchar == '\n') {
      y++;
      x = 0;
      move(y,x);
    } else {
      move(y, x);
      addch(curchar);
      x += 1;
    }

    i += 1;
  }

  refresh();
}

void term_update(Vector *v)
{
  int c = getch(); //term_get_input();

  if(c == KEY_BACKSPACE) {
    vector_pop(v);
  } else {
    vector_append(v, c);
  }
  //clear();
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
