//yukari would approve

#include "gap_buffer.h"
#include "vector.h"

void gb_init(GapBuffer *gb)
{
  gb->pre = 0;
  gb->post = 0;

  vector_init(gb->buf);
}

void gb_step_forward(GapBuffer *gb)
{
  
}

void gb_step_backward(GapBuffer *gb)
{

}

void gb_move_by(GapBuffer *gb, int mov)
{

}

void gb_insert_char(GapBuffer *gb, char val)
{

}

void gb_insert_str(GapBuffer *gb, char *vals)
{

}
