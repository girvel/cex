#pragma once

#include "array.h"


typedef struct {
    Array _array;
} String;

String string_from(char *base_c_string);
char *string_to_c(String string);
void string_free(String *string);
