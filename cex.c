#include <assert.h>
#include <stdio.h>
#include "framework/dynamic_array.h"
#include "framework/dynamic_string.h"

// typedef struct {
//   void* components[3];
// } Entity;

int main() {
    DynamicArray array = array_new(sizeof(int));
    array_extend(&array, 3, (int[]) {32, 64, 128});

    for (size_t i = 0; i < array_get_length(array); i++) {
        printf("array[%lu] = %i\n", i, ARRAY_AT(int, array, i));
    }

    printf(
        "array.length = %lu, array.capacity = %lu\n",
        array_get_length(array),
        array_get_capacity(array)
    );

    array_free(&array);

    String s = string_from("Hello, world!");
    printf("Old string is '%s'\n", string_to_c(s));

    string_free(&s);
    printf("New string is '%s'\n", string_to_c(s));

    return 0;
}
