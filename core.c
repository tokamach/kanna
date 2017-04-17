#include <string.h>

#include "core.h"
#include "gap_buffer.h"

void editor_init(Editor *e)
{
  e->dirty = 1;
  e->cur_x = 0;
  e->cur_y = 0;

  e->offset_x = 0;
  e->offset_y = 0;

  gb_init(&e->buf);
}

//movement functions
void editor_forward(Editor *e)
{
  gb_move_by(&e->buf, 1);
}

void editor_back(Editor *e)
{
  gb_move_by(&e->buf, -1);
}

void editor_up(Editor *e)
{
  if(e->cur_y > 0)
    e->cur_y--;
}

void editor_down(Editor *e)
{
  e->cur_y++;
}

//insertion and deletion
void editor_insert_char(Editor *e, char c)
{
  gb_insert_char(&e->buf, c);
  e->dirty = 1;
}

void editor_insert_str(Editor *e, char *s)
{
  gb_insert_str(&e->buf, s);
  e->dirty = 1;
}

void editor_backspace(Editor *e)
{
  gb_delete(&e->buf);
  e->dirty = 1;
}
