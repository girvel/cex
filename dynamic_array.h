#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    void *_start;
    size_t _type_size, _capacity, _length;
} DynamicArray;

DynamicArray array_allocate(size_t type_size, size_t capacity);
void *array_at(DynamicArray array, size_t index);
void array_free(DynamicArray *array);

#define ARRAY_AT(TYPE, ARRAY, INDEX) (*((TYPE *)array_at((ARRAY), (INDEX))))
