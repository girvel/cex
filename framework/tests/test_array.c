#include <stdio.h>
#include <assert.h>
#include "../array.h"


void test_array_basic_use_case() {
    printf("Array basic use case");
    int *first_base = (int[]) {1, 2, 3};
    Array array = array_new(sizeof(int));
    array_extend(&array, 3, first_base);
    for (size_t i = 0; i < 3; i++) {
        assert(first_base[i] == ARRAY_AT(int, array, i));
    }
    printf("\tSUCCESS\n");
}
