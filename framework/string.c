#include <string.h>
#include "string.h"

String string_from(char *base_c_string) {
    Array array = array_new(sizeof(char));
    size_t string_length = 0;
    while (base_c_string[string_length] != '\0') string_length++;
    array_extend(&array, string_length, base_c_string);
    return (String) {._array = array};
}

char *string_to_c(String string) {
    size_t length = array_get_length(string._array);
    char *result = malloc(sizeof(char) * (length + 1));
    memcpy(result, string._array._start, length);
    result[length] = '\0';
    return result;
}

void string_free(String *string) {
    array_free(&string->_array);
}
