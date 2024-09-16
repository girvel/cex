#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "array.h"
#include "common.h"


Array array_new(size_t type_size) {
    return (Array) {
        ._start = NULL,
        ._type_size = type_size,
        ._capacity = 0,
        ._length = 0,
    };
}

Array array_own(size_t type_size, size_t memory_size, void *base) {
    return (Array) {
        ._start = base,
        ._type_size = type_size,
        ._capacity = memory_size,
        ._length = memory_size,
    };
}

Array array(size_t type_size, size_t memory_size, void *base) {
    Array result = array_new(type_size);
    array_extend(&result, memory_size, base);
    return result;
}

void array_increase_capacity(Array *array, size_t delta_capacity) {
    array->_capacity += delta_capacity;
    array->_start = realloc(array->_start, array->_capacity * array->_type_size);
}

void array_increase_length(Array *array, size_t delta_length) {
    array->_length += delta_length;
    if (array->_length <= array->_capacity) return;

    size_t delta_capacity = MAX(4, array->_capacity);
    while (array->_length > array->_capacity + delta_capacity) {
        delta_capacity *= 2;
    }
    array_increase_capacity(array, delta_capacity);
}

void *array_at(Array array, size_t index) {
    assert(index < array._length);
    return array._start + array._type_size * index;
}

size_t array_get_capacity(Array array) {
    return array._capacity;
}

size_t array_get_length(Array array) {
    return array._length;
}

void array_extend(Array *array, size_t extension_length, void *extension) {
    size_t base_index = array->_length;
    array_increase_length(array, extension_length);
    memcpy(array_at(*array, base_index), extension, extension_length * array->_type_size);
}

void array_free(Array *array) {
    free(array->_start);
    array->_start = NULL;
    array->_capacity = 0;
    array->_length = 0;
}
