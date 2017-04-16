#include <ncurses.h>

#include "vector.h"
#include "core.h"
#include "terminal.h"

void term_begin()
{
  initscr();
  
  timeout(-1);
  cbreak();
  noecho();
  intrflush(stdscr, false);
  keypad(stdscr, true);
}

void term_update_cursor(Editor *e)
{
  move(e->cur_y, e->cur_x);
  refresh();
}

void term_draw(Editor *e)
{
  int curchar;

  int i = 0;
  int x = 0;
  int y = 0;

  clear();

  while(i < e->buf.size) {
    curchar = vector_get(&e->buf, i);

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
  e->dirty = 0;
}

void term_update(Editor *e)
{
  int c = getch(); //term_get_input();

  switch(c) {
  case KEY_BACKSPACE:
    vector_pop(&e->buf);
    e->dirty = 1;
    break;

  case KEY_DOWN:
    e->cur_y++;
    break;

  case KEY_UP:
    e->cur_y--;
    break;

  case KEY_LEFT:
    e->cur_x--;
    break;

  case KEY_RIGHT:
    e->cur_x++;
    break;
    
  default:
    vector_append(&e->buf, c);
    e->dirty = 1;
  }
  
  term_update_cursor(e);
}

void term_end()
{
  endwin();
}
