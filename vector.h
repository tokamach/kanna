#pragma once
#define VECTOR_INITIAL_CAPACITY 50

typedef struct
{
  int size;
  int capacity;
  char* data;
} Vector;

void vector_init(Vector *vector);
void vector_append(Vector *vector, char val);
void vector_pop(Vector *vector);
char vector_get(Vector *vector, int pos);
void vector_set(Vector *vector, int pos, char val);
void vector_double_capacity_if_full(Vector *vector);
void vector_free(Vector *vector);
