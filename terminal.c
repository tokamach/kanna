#include <ncurses.h>
#include <stdlib.h>

#include "vector.h"
#include "terminal.h"

void term_init(Terminal *t)
{
  t->dirty = 1;
  t->cur_x = 0;
  t->cur_y = 0;
}

void term_begin()
{
  initscr();
  
  timeout(-1);
  cbreak();
  noecho();
  intrflush(stdscr, false);
  keypad(stdscr, true);
}

void term_update_cursor(Terminal *t)
{
  move(t->cur_y, t->cur_x);
  refresh();
}

void term_draw(Terminal *t, Vector *v)
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
  t->dirty = 0;
}

void term_update(Terminal *t, Vector *v)
{
  int c = getch(); //term_get_input();

  switch(c) {
  case KEY_BACKSPACE:
    vector_pop(v);
    t->dirty = 1;
    break;

  case KEY_DOWN:
    t->cur_y++;
    break;

  case KEY_UP:
    t->cur_y--;
    break;

  case KEY_LEFT:
    t->cur_x--;
    break;

  case KEY_RIGHT:
    t->cur_x++;
    break;
    
  default:
    vector_append(v, c);
    t->dirty = 1;
  }
  
  term_update_cursor(t);
  //clear();
}

void term_end()
{
  endwin();
}
