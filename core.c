#include "core.h"

void editor_init(Editor *e)
{
  e->dirty = 1;
  e->cur_x = 0;
  e->cur_y = 0;

  e->offset_x = 0;
  e->offset_y = 0;

  vector_init(&e->buf);
}
