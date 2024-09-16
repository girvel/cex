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
    {
        Array demo = ARRAY(int, 32, 64, 128);
        array_extend(&demo, 3, (int[]) {32, 64, 128});

        ARRAY_FOR(int, i, e, demo, {
            printf("array[%lu] = %i\n", i, *e);
        })

        printf(
            "array.length = %lu, array.capacity = %lu\n",
            array_get_length(demo),
            array_get_capacity(demo)
        );

        array_free(&demo);
    }

    {
        String s = string_from("Hello, world!");
        printf("Old string is '%s'\n", string_to_c(s));

        string_free(&s);
        printf("New string is '%s'\n", string_to_c(s));
    }

    Entity e1 = entity_create(COMPONENT_MAX_ID);
    name_set(e1, string_from("girvel"));
    position_set(e1, 22);

    Entity e2 = entity_create(COMPONENT_MAX_ID);
    name_set(e2, string_from("some guy"));
    position_set(e2, 0);

    Entity e3 = entity_create(COMPONENT_MAX_ID);
    name_set(e3, string_from("guy without a position"));

    Entity e4 = entity_create(COMPONENT_MAX_ID);

    System report_system = system_create(
        ARRAY(int, COMPONENT_NAME),
        report_system_process
    );

    system_add(&report_system, &e1);
    system_add(&report_system, &e2);
    system_add(&report_system, &e3);
    system_add(&report_system, &e4);

    system_update(report_system);
    system_update(report_system);

    entity_free(&e1);
    entity_free(&e2);
    entity_free(&e3);
    entity_free(&e4);
    
    system_free(&report_system);

    return 0;
}
