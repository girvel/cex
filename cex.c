#include <assert.h>
#include <stdio.h>
#include "dynamic_array.h"

// typedef struct {
//   void* components[3];
// } Entity;

int main() {
    DynamicArray array = array_new(sizeof(int));
    array_increase_length(&array, 3);
    ARRAY_AT(int, array, 0) = 32;
    ARRAY_AT(int, array, 1) = 64;
    ARRAY_AT(int, array, 2) = 128;

    for (size_t i = 0; i < array_get_length(array); i++) {
        printf("array[%lu] = %i\n", i, ARRAY_AT(int, array, i));
    }

    printf(
        "array.length = %lu, array.capacity = %lu\n",
        array_get_length(array),
        array_get_capacity(array)
    );

    array_free(&array);

    return 0;
}
