#pragma once

#include <ncurses.h>

#include "vector.h"

void term_init();
void term_draw(Vector *v);
void term_update();
int  term_get_input();
void term_end();
