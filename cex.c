#include <assert.h>
#include <stdio.h>
#include "framework/dynamic_array.h"
#include "framework/dynamic_string.h"
#include "entity.h"
#include "components.h"


void proto_system_update(Entity *e) {
    printf(
        "%s stands at X = %i\n",
        string_to_c(name_get(*e)->text),
        position_get(*e)->x
    );
}


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

    Entity e = entity_create(COMPONENT_N);

    // consider even shorter syntax
    entity_set_component(e, COMPONENT_NAME, name_create(string_from("girvel")));
    entity_set_component(e, COMPONENT_POSITION, position_create(22));
    printf("x is %i\n", position_get(e)->x);

    proto_system_update(&e);

    return 0;
}
