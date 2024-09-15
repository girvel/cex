#include <stdlib.h>
#include <assert.h>
#include "dynamic_array.h"


DynamicArray array_create(size_t type_size, size_t capacity) {
    DynamicArray result;
    result._type_size = type_size;
    result._capacity = capacity;
    result._length = 0;

    result._start = malloc(type_size * capacity);
    return result;
}

void *array_at(DynamicArray array, size_t index) {
    assert(index < array._length);
    return array._start + array._type_size * index;
}

#define ARRAY_AT(TYPE, ARRAY, INDEX) *((TYPE *)array_at((ARRAY), (INDEX)))

