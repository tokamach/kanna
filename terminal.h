#pragma once

#include <ncurses.h>

#include "vector.h"
#include "core.h"

void term_begin();
void term_update_cursor(Editor *e);
void term_draw(Editor *e);
void term_update(Editor *e);
void term_end();
