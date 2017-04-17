//yukari would approve

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "gap_buffer.h"
#include "vector.h"

void gb_init(GapBuffer *gb)
{
  gb->start = 0;
  gb->end = GB_INITIAL_SIZE - 1;

  gb->gap_start = 0;
  gb->gap_end = GB_INITIAL_SIZE - 1;

  gb->cursor = 0;

  gb->data = malloc(sizeof(char) * GB_INITIAL_SIZE);
}

//util
void gb_move_gap(GapBuffer *gb)
{
  if(gb->cursor == gb->gap_start)
    return;

  char *src;
  int length;

  int gap_size = gb->gap_end - gb->gap_start;

  // gap is ahead of cursor
  if(gb->cursor <= gb->gap_start) {
    src = gb->data + gb->cursor;
    length = gb->gap_start - gb->cursor;

    memmove(gb->data + gb->cursor + gap_size+1, src, sizeof(char) * length);

    gb->gap_start -= length;
    gb->gap_end -= length;
  }

  // gap is behind cursor
  else if (gb->cursor >= gb->gap_end) {
    src = gb->data + gb->gap_end + 1;

    length = gb->cursor - gb->gap_end;

    memmove(gb->data + gb->gap_start, src, sizeof(char) * length);
    
    gb->gap_end += length;
    gb->gap_start += length;
    gb->cursor = gb->gap_start;
  }

  //cursor is inside or outside gap, fuck
  else {
    printf("cursor is inside or outside gap, BAD");
    exit(1);
  }
}

void gb_resize_buffer(GapBuffer *gb)
{
  int new_size = (gb->end + 1) + GB_GROW_SIZE;
  int size = gb->end - gb->gap_end;

  char *newdata = realloc(gb->data, sizeof(char) * new_size);
  gb->data = newdata;
  
  char *src = gb->data + gb->gap_end + 1;
  char *dest = gb->data + new_size - size;

  memmove(dest, src, sizeof(char) * size);

  gb->end = new_size - 1;
  gb->gap_end = gb->end - size;
}

// this isn't gonna work
char* gb_get_content(GapBuffer *gb)
{
  int gap_size = gb->gap_end - gb->gap_start;
  char *ret = malloc(sizeof(char) * (gb->end - gap_size));

  memcpy(ret, gb->data, sizeof(char) * gb->gap_start);
  memcpy(ret + gb->gap_start, gb->data + gb->gap_end + 1, sizeof(char) * (gb->end - gb->gap_end));

  return ret;
}

void gb_move_by(GapBuffer *gb, signed int mov)
{
  int old_cur = gb->cursor;
  int gap_size = gb->gap_end - gb->gap_start;

  gb->cursor += mov;

  // cursor crossed gap threshold, while moving left
  if (old_cur > gb->gap_end && gb->cursor < gb->gap_end)
    gb->cursor -= gap_size;
  // cursor crossed gap threshold, while moving right
  else if (old_cur <= gb->gap_start && gb->cursor > gb->gap_start)
    gb->cursor += gap_size;

  //check if cursor did an illegal move
  if(gb->cursor < 0 || gb->cursor > gb->end) {
    // should error handle
    printf("illegal move");
    gb->cursor = old_cur;
  }
}

void gb_insert_char(GapBuffer *gb, char val)
{
  if(gb->cursor != gb->gap_start)
    gb_move_gap(gb);

  if(gb->gap_start == gb->gap_end)
    gb_resize_buffer(gb);

  if(gb->gap_start >= gb->gap_end) {
    printf("insert failed, buffer too small");
    exit(1);
  }

  gb->data[gb->cursor] = val;
  gb->gap_start++;
  gb_move_by(gb, 1);
}

void gb_insert_str(GapBuffer *gb, char *vals)
{
  gb_move_gap(gb);

  int length = strlen(vals);

  while(length > (gb->gap_end - gb->gap_start))
    gb_resize_buffer(gb);

  do {
    gb_insert_char(gb, *vals++);
  } while (--length > 0);
}

void gb_delete(GapBuffer *gb)
{
  gb_move_gap(gb);

  if(gb->gap_start != 0) {
    gb->gap_start--;
    gb_move_by(gb, -1);
  }
}

void gb_free(GapBuffer *gb)
{
  free(gb->data);
}
