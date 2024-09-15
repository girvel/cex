#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "dynamic_array.h"


DynamicArray array_allocate(size_t type_size, size_t capacity) {
    DynamicArray result;
    result._type_size = type_size;
    result._capacity = capacity;
    result._length = 0;

    result._start = calloc(capacity, type_size);
    return result;
}

void *array_at(DynamicArray array, size_t index) {
    assert(index < array._length);
    return array._start + array._type_size * index;
}

void array_free(DynamicArray *array) {
    free(array->_start);
    array->_start = NULL;
    array->_capacity = 0;
    array->_length = 0;
}

