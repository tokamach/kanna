//yukari would approve

#pragma once

#define GB_INITIAL_SIZE 50
#define GB_GROW_SIZE 50

// gap buffer data structure
typedef struct 
{
  char *data;

  //int size; //buffer size
  int start;
  int end;

  int gap_start;
  int gap_end;

  int cursor;

} GapBuffer;

void gb_init(GapBuffer *gb);
void gb_free(GapBuffer *gb);

void gb_move_gap(GapBuffer *gb);
void gb_resize_buffer(GapBuffer *gb);

char* gb_get_content(GapBuffer *gb);

//move cursor
void gb_move_by(GapBuffer *gb, signed int mov);

void gb_insert_char(GapBuffer *gb, char val);
void gb_insert_str(GapBuffer *gb, char *vals);
void gb_delete(GapBuffer *gb);
