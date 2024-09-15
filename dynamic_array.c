#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "dynamic_array.h"


DynamicArray array_new(size_t type_size) {
    return (DynamicArray) {
        ._start = NULL,
        ._type_size = type_size,
        ._capacity = 0,
        ._length = 0,
    };
}

void array_increase_capacity(DynamicArray *array, size_t delta_capacity) {
    array->_capacity = array->_capacity + delta_capacity;
    array->_start = realloc(array->_start, array->_capacity);
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

