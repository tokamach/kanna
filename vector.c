#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void vector_init(Vector *vector)
{
  vector->size = 0;
  vector->capacity = VECTOR_INITIAL_CAPACITY;

  vector->data = malloc(sizeof(int) * vector->capacity);
}

void vector_append(Vector *vector, char val)
{
  vector_double_capacity_if_full(vector);

  vector->data[vector->size++] = val;
}

char vector_get(Vector *vector, int pos)
{
  if(pos >= vector->size || pos < 0)
  {
    //shit
    printf("[ERROR] Vector index %i out of bounds for vector of size %i",
	   pos, vector->size);
    exit(1);
  }

  return vector->data[pos];
}

void vector_set(Vector *vector, int pos, char val)
{
  while(pos >= vector->size) {
    vector_append(vector, 0);
  }

  vector->data[pos] = val;
}

void vector_double_capacity_if_full(Vector *vector)
{
  if(vector->size >= vector->capacity) {
    vector->capacity *= 2;
    vector->data = realloc(vector->data, sizeof(int) * vector->capacity);
  }
}

void vector_free(Vector *vector)
{
  free(vector->data);
}
