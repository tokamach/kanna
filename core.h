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
