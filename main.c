#include <stdio.h>
#include <ncurses.h>

#include "core.h"
#include "terminal.h"

int main(int argc, char **argv)
{
  Editor editor;
  editor_init(&editor);

  term_begin();
  while(1)
  {
    if(editor.dirty)
      term_draw(&editor);
    term_update(&editor);
  }

  term_end();
}
