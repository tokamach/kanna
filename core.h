#pragma once

#include "gap_buffer.h"
#include "vector.h"

typedef struct
{
  int dirty; //Should redraw?
  int cur_x; //Cursor X
  int cur_y; //Cursor Y

  int offset_x; //how to the side is scrolled
  int offset_y; //how down is scrolled

  int prev_index;

  GapBuffer buf;
  Vector line_lengths; // vector of the length of each line

} Editor;

void editor_init(Editor *e);

//movement
void editor_forward(Editor *e);
void editor_back(Editor *e);
void editor_up(Editor *e);
void editor_down(Editor *e);

//insertion and deletion
void editor_insert_char(Editor *e, char c);
void editor_insert_str(Editor *e, char *s);
void editor_backspace(Editor *e);

