#include <assert.h>
#include <stdio.h>
#include "framework/array.h"
#include "framework/string.h"
#include "ecs/entity.h"
#include "ecs/system.h"
#include "components.h"


void report_system_process(Entity *e) {
    position *p = position_get(*e);
    String postfix = (
        p == NULL
        ? string_from("does not have a position")
        : STRING_FORMAT("stands at X = %i", p->x)
    );

    printf(
        "%s %s\n",
        string_to_c(name_get(*e)->text),
        string_to_c(postfix)
    );

    string_free(&postfix);
}


int main() {
    Array array = array_new(sizeof(int));
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

    Entity e1 = entity_create(COMPONENT_N);
    name_set(e1, string_from("girvel"));
    position_set(e1, 22);

    Entity e2 = entity_create(COMPONENT_N);
    name_set(e2, string_from("some guy"));
    position_set(e2, 0);

    Entity e3 = entity_create(COMPONENT_N);
    name_set(e3, string_from("guy without a position"));

    Entity e4 = entity_create(COMPONENT_N);

    Array required_components = array_new(sizeof(int));
    array_increase_capacity(&required_components, 1);
    array_extend(&required_components, 1, (int[]) {COMPONENT_NAME});

    System report_system = system_create(required_components, report_system_process);
    system_add(&report_system, &e1);
    system_add(&report_system, &e2);
    system_add(&report_system, &e3);
    system_add(&report_system, &e4);
    system_update(report_system);

    entity_free(&e1);

    return 0;
}
