#include <ncurses.h>
#include <string.h>

#include "gap_buffer.h"
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
  char *content = gb_get_content(&e->buf);
  int contentlen = strlen(content);

  int x = 0;
  int y = 0;

  for(int i = 0; i < contentlen; i++) {
    char curchar = content[i];

    if(curchar == '\n') {
      y++;
      x = 0;
    } else {
      move(y, x);
      addch(curchar);
      x++;
    }
  }

  refresh();
  e->dirty = 0;
}

void term_update(Editor *e)
{
  int c = getch(); //term_get_input();

  switch(c) {
  case KEY_BACKSPACE:
    editor_backspace(e);
    break;

  case KEY_DOWN:
    editor_down(e);
    break;

  case KEY_UP:
    editor_up(e);
    break;

  case KEY_LEFT:
    editor_back(e);
    break;

  case KEY_RIGHT:
    editor_forward(e);
    break;
    
  default:
    editor_insert_char(e, c);
  }
  
  term_update_cursor(e);
}

void term_end()
{
  endwin();
}
