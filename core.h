#pragma once

#include "vector.h"

typedef struct
{
  int dirty; //Should redraw?
  int cur_x; //Cursor X
  int cur_y; //Cursor Y

  int offset_x; //how to the side is scrolled
  int offset_y; //how down is scrolled

  Vector buf;
} Editor;

void editor_init(Editor *e);

//standard editor functions

//movement
void editor_forward(Editor *e);
void editor_back(Editor *e);
void editor_up(Editor *e);
void editor_down(Editor *e);

//insertion and deletion
void editor_insert_char(Editor *e, char c);
void editor_insert_str(Editor *e, char *s);
void editor_backspace(Editor *e);
