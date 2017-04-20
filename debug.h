#pragma once

#include <ncurses.h>

#include "core.h"

void debug_print(Editor *e)
{
  int mx, my = 0;
  getmaxyx(stdscr, my, mx);
  mvprintw(0, mx - 9, "xsize: %d", mx);
  mvprintw(1, mx - 8, "curx: %d", e->cur_x);
  mvprintw(2, mx - 8, "cury: %d", e->cur_y);
  mvprintw(3, mx - 8, "prev: %d", e->prev_index);
}
