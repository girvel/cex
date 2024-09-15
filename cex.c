#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// typedef struct {
//   void* components[3];
// } Entity;

typedef struct {
    void *_start;
    size_t _type_size, _capacity, _length;
} DynamicArray;

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

int main() {
    DynamicArray array = array_create(sizeof(int), 10);
    array._length = 2;
    ARRAY_AT(int, array, 0) = 32;
    ARRAY_AT(int, array, 1) = 64;

    for (size_t i = 0; i < array._length; i++) {
        printf("array[%lu] = %i\n", i, ARRAY_AT(int, array, i));
    }

    return 0;
}
