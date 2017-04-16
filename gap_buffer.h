#pragma strict
#include "vector.h"

// gap buffer data structure
typedef struct 
{
  Vector buf;

  int size; //buffer size
  int pre;  //pre gap array index
  int post; //post gap array index

} GapBuffer;

void gb_init(GapBuffer *gb);

void gb_step_forward(GapBuffer *gb);
void gb_step_backward(GapBuffer *gb);
void gb_move_by(GapBuffer *gb, int mov);

void gb_insert_char(GapBuffer *gb, char val);
void gb_insert_str(GapBuffer *gb, char *vals);
