#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "../string.h"


void test_string_format() {
    printf("STRING_FORMAT");

    String result = STRING_FORMAT("Hello, %s! The answer is %i.", "world", 42);
    assert(memcmp(result._array._start, "Hello, world! The answer is 42.", 31) == 0);
    string_free(&result);

    printf("\tSUCCESS\n");
}
