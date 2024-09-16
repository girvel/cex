#pragma once

#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    void *_start;
    size_t _type_size, _capacity, _length;
} Array;

Array array_new(size_t type_size);
void array_increase_capacity(Array *array, size_t delta_capacity);
void array_increase_length(Array *array, size_t delta_length);

void *array_at(Array array, size_t index);
size_t array_get_capacity(Array array);
size_t array_get_length(Array array);

void array_extend(Array *array, size_t extension_length, void *extension);

void array_free(Array *array);

#define ARRAY_AT(TYPE, ARRAY, INDEX) (*((TYPE *)array_at((ARRAY), (INDEX))))

#define ARRAY_APPEND(TYPE, ARRAY, ITEM) {\
    Array *array = (ARRAY); \
    size_t i = array_get_length(*array); \
    array_increase_length(array, 1); \
    ARRAY_AT(TYPE, *array, i) = ITEM; \
}

