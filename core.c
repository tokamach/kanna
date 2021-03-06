#include <string.h>

#include "core.h"
#include "gap_buffer.h"
#include "vector.h"

void editor_init(Editor *e)
{
  e->dirty = 1;
  e->cur_x = 0;
  e->cur_y = 0;

  e->offset_x = 0;
  e->offset_y = 0;

  e->prev_index = 0;

  gb_init(&e->buf);
  vector_init(&e->line_lengths);
}

//util 
void update_line_lengths(Editor *e)
{
  int curline = 0;
  int linesize = 0;
  char *content = gb_get_content(&e->buf);
  int content_length = strlen(content);

  int i = 0;
  do {
    if((content[i] == '\n') || (content_length - 1 == 0)) {
      vector_set(&e->line_lengths, curline, (char)linesize);
      linesize = 0;
      curline++;
    } else {
      linesize++;
    }

    i++;
  } while(--content_length > 0);
}

int at_start_of_line(Editor *e)
{
  if(e->cur_x <= 0)
    return 1;
  else
    return 0; 
}

int at_end_of_line(Editor *e)
{
  if(e->cur_x == vector_get(&e->line_lengths, e->cur_y))
    return 1;
  else
    return 0;
}

// see how far through the file you are
// translates x and y into a single array index
int get_index_in_file(Editor *e)
{
  int acc = 0;

  for(int i = 0; i < e->cur_y - 1; i++) {
    acc += vector_get(&e->line_lengths, i);
  }

  acc += e->cur_x;

  return acc;
}

//movement functions
void editor_forward(Editor *e)
{
  if(!at_end_of_line(e)) {
    e->cur_x++;
  }
}

void editor_back(Editor *e)
{
  if(!at_start_of_line(e))
    e->cur_x--;
}

void editor_up(Editor *e)
{
  if(e->cur_y > 0) {
    e->cur_y--;
    int upperx = vector_get(&e->line_lengths, e->cur_y);
    if(upperx < e->cur_x)
      e->cur_x = upperx;
  }
}

void editor_down(Editor *e)
{
  if((e->cur_y < e->line_lengths.size)) {
    e->cur_y++;
    int lowerx = vector_get(&e->line_lengths, e->cur_y);
    if(lowerx < e->cur_x)
      e->cur_x = lowerx;
  }
}

//insertion and deletion
void editor_insert_char(Editor *e, char c)
{
  //recalculate index
  int new_index = get_index_in_file(e);
  int diff = new_index - e->prev_index;
  gb_move_by(&e->buf, diff);
  e->prev_index = new_index;

  gb_insert_char(&e->buf, c);

  if(c == '\n') {
    e->cur_y++;
    e->cur_x = 0;
  } else {
    e->cur_x++;
  }
//editor_forward(e);

  e->dirty = 1;
  update_line_lengths(e);
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
  update_line_lengths(e);
}
