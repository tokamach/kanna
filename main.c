#include <stdio.h>
#include <ncurses.h>

#include "terminal.h"
#include "vector.h"

int main(int argc, char **argv)
{
  Vector text;
  vector_init(&text);

  term_init();
  while(1)
  {
    if(term_dirty)
      term_draw(&text);
    term_update(&text);
  }

  term_end();
}
