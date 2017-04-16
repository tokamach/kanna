#pragma once

#include <ncurses.h>

#include "vector.h"

typedef struct
{
  int dirty; //Should redraw?
  int cur_x; //Cursor X
  int cur_y; //Cursor Y

} Terminal;

void term_init(Terminal *t);
void term_begin();
void term_update_cursor(Terminal *t);
void term_draw(Terminal *t, Vector *v);
void term_update(Terminal *t, Vector *v);
void term_end();
