#include <assert.h>
#include <stdio.h>
#include "framework/dynamic_array.h"
#include "framework/dynamic_string.h"


typedef enum {
    COMPONENT_NAME,
    COMPONENT_POSITION,
    COMPONENT_N,
} COMPONENT;

typedef struct {
  DynamicArray _components;
} Entity;

Entity entity_create(size_t max_components_n) {
    Entity result = {._components = array_new(sizeof(void *))};
    array_increase_capacity(&result._components, max_components_n);
    array_increase_length(&result._components, max_components_n);
    for (size_t i = 0; i < max_components_n; i++) {
        ARRAY_AT(void *, result._components, i) = NULL;
    }
    return result;
}

void entity_set_component(Entity e, size_t component_id, void *component) {
    *((void **) array_at(e._components, component_id)) = component;
}

void *entity_get_component(Entity e, size_t component_id) {
    return ARRAY_AT(void *, e._components, component_id);
}

typedef struct {
    String text;
} Name;

typedef struct {
    int x;
} Position;

void proto_system_update(Entity *e) {
    printf(
        "%s stands at X = %i\n",
        string_to_c(((Name *)entity_get_component(*e, COMPONENT_NAME))->text),
        ((Position *)entity_get_component(*e, COMPONENT_POSITION))->x
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

    Name *name = malloc(sizeof(Name));
    name->text = string_from("girvel");
    entity_set_component(e, COMPONENT_NAME, name);

    Position *position = malloc(sizeof(Position));
    position->x = 22;
    entity_set_component(e, COMPONENT_POSITION, position);
    printf("x is %i\n", ((Position *)entity_get_component(e, COMPONENT_POSITION))->x);

    proto_system_update(&e);

    return 0;
}
