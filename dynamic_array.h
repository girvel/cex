#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    void *_start;
    size_t _type_size, _capacity, _length;
} DynamicArray;

DynamicArray array_new(size_t type_size);
void array_increase_capacity(DynamicArray *array, size_t delta_capacity);
void array_increase_length(DynamicArray *array, size_t delta_length);

void *array_at(DynamicArray array, size_t index);
size_t array_get_capacity(DynamicArray array);
size_t array_get_length(DynamicArray array);

void array_extend(DynamicArray *array, size_t extension_length, void *extension);

void array_free(DynamicArray *array);

#define ARRAY_AT(TYPE, ARRAY, INDEX) (*((TYPE *)array_at((ARRAY), (INDEX))))
