#include <assert.h>
#include <stdio.h>
#include "dynamic_array.h"

// typedef struct {
//   void* components[3];
// } Entity;

int main() {
    DynamicArray array = array_allocate(sizeof(int), 10);
    array._length = 2;
    ARRAY_AT(int, array, 0) = 32;
    ARRAY_AT(int, array, 1) = 64;

    for (size_t i = 0; i < array._length; i++) {
        printf("array[%lu] = %i\n", i, ARRAY_AT(int, array, i));
    }

    array_free(&array);
    printf("%i\n", ARRAY_AT(int, array, 1));

    return 0;
}
