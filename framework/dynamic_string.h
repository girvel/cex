#pragma once

#include "dynamic_array.h"


typedef struct {
    DynamicArray _array;
} String;

String string_from(char *base_c_string);
char *string_to_c(String string);
void string_free(String *string);
