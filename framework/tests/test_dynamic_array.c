#include <stdio.h>
#include <assert.h>
#include "../dynamic_array.h"

void test_basic_use_case() {
    printf("Basic use case...");
    int *first_base = (int[]) {1, 2, 3};
    DynamicArray array = array_new(sizeof(int));
    array_extend(&array, 3, first_base);
    for (size_t i = 0; i < 3; i++) {
        assert(first_base[i] == ARRAY_AT(int, array, i));
    }
    printf("\tSUCCESS\n");
}

int main() {
    printf("\n-- Testing dynamic arrays --\n");
    test_basic_use_case();
}
