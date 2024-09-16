#pragma once

#include "array.h"


typedef struct {
    Array _array;
} String;

String string_from(char *base_c_string);
char *string_to_c(String string);
void string_free(String *string);

#define STRING_FORMAT(FORMAT, ...) ({ \
    const char *format = (FORMAT); \
    int length = snprintf(NULL, 0, format, __VA_ARGS__); \
    char *str = malloc(length + 1); \
    snprintf(str, length + 1, format, __VA_ARGS__); \
    String result = string_from(str); \
    free(str); \
    result; \
})
