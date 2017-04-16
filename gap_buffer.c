//yukari would approve

#include "gap_buffer.h"
#include "vector.h"

void gb_init(GapBuffer *gb)
{
  gb->pre = 0;
  gb->post = 0;

  vector_init(gb->buf);
}
