#include <stdio.h>
#include <ncurses.h>

#include "terminal.h"
#include "vector.h"

int main(int argc, char **argv)
{
  Vector text;
  vector_init(&text);

  Terminal term;
  term_init(&term);

  term_begin();
  while(1)
  {
    if(term.dirty)
      term_draw(&term, &text);

    term_update(&term, &text);
  }

  term_end();
}
