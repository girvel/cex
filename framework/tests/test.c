#include <stdio.h>
#include "test_array.c"
#include "test_string.c"


int main() {
    printf("\n-- Running tests --\n");
    test_array_basic_use_case();
    test_string_format();
}
