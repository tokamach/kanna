#include <ncurses.h>
#include "terminal.h"

void term_init()
{
  initscr();
  
  timeout(1);
  cbreak();
  noecho();
  intrflush(stdscr, false);
  keypad(stdscr, true);
}

void term_end()
{
  endwin();
}
