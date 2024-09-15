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

int main() {
    DynamicArray array = array_create(sizeof(int), 10);
    array._length = 1;
    *((int *)array_at(array, 0)) = 32;
    printf("array[0] = %i\n", *((int *)array_at(array, 0)));
    return 0;
}
