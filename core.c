#include <string.h>

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

//movement functions
void editor_forward(Editor *e)
{
  e->cur_x++;
}

void editor_back(Editor *e)
{
  if(e->cur_x > 0)
    e->cur_x--;
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
  vector_append(&e->buf, c);
  e->dirty = 1;
}

void editor_insert_str(Editor *e, char *s)
{
  for (int i = 0; i < strlen(s); i++) {
    editor_insert_char(e, s[i]);
  }
  e->dirty = 1;
}

void editor_backspace(Editor *e)
{
  vector_pop(&e->buf);
  e->dirty = 1;
}
