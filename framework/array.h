#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include "macro.h"


typedef struct {
    void *_start;
    size_t _type_size, _capacity, _length;
} Array;

Array array_new(size_t type_size);
Array array_own(size_t type_size, size_t memory_size, void *base);
Array array_from(size_t type_size, size_t memory_size, void *base);

void array_increase_capacity(Array *array, size_t delta_capacity);
void array_increase_length(Array *array, size_t delta_length);

void *array_at(Array array, size_t index);
size_t array_get_capacity(Array array);
size_t array_get_length(Array array);

void array_extend(Array *array, size_t extension_length, void *extension);

void array_free(Array *array);

#define ARRAY(TYPE, ...) array_from(sizeof(TYPE), VARIADIC_LENGTH(__VA_ARGS__), (TYPE[]) {__VA_ARGS__})

#define ARRAY_AT(TYPE, ARRAY, INDEX) (*((TYPE *)array_at((ARRAY), (INDEX))))

#define ARRAY_APPEND(TYPE, ARRAY, ITEM) { \
    Array *this_array = (ARRAY); \
    size_t i = array_get_length(*this_array); \
    array_increase_length(this_array, 1); \
    ARRAY_AT(TYPE, *this_array, i) = ITEM; \
}

#define ARRAY_FOR(TYPE, INDEX_VAR, ELEMENT_VAR, ARRAY, ITERATION) { \
    Array this_array = (ARRAY); \
    for (size_t INDEX_VAR = 0; INDEX_VAR < array_get_length(this_array); INDEX_VAR++) { \
        TYPE *ELEMENT_VAR = array_at(this_array, INDEX_VAR); \
        ITERATION \
    } \
}
