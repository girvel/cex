#include <stdlib.h>


typedef struct {
    void *_start;
    size_t _type_size, _capacity, _length;
} DynamicArray;

DynamicArray array_create(size_t type_size, size_t capacity);

void *array_at(DynamicArray array, size_t index);

#define ARRAY_AT(TYPE, ARRAY, INDEX) *((TYPE *)array_at((ARRAY), (INDEX)))
