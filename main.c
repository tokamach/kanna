#include <stdio.h>
#include <ncurses.h>

#include "terminal.h"
#include "vector.h"

int main(int argc, char **argv)
{
  Vector text;
  vector_init(&text);
  vector_append(&text, 'H');
  vector_append(&text, 'e');
  vector_append(&text, 'l');
  vector_append(&text, 'l');
  vector_append(&text, 'o');
  vector_append(&text, '\n');

  term_init();
  while(1)
  {
    term_draw(&text);
    term_update();
  }

  term_end();
}
