#include "system.h"
#include "../framework/array.h"


System system_create(void (*process)(Entity *)) {
    return (System) {
        .process = process,
        ._entities = array_new(sizeof(Entity *)),
    };
}

void system_free(System *system) {
    array_free(&system->_entities);
}

bool system_add(System *system, Entity *item) {
    ARRAY_APPEND(Entity *, &system->_entities, item);
    return true;
}

void system_update(System system) {
    for (size_t i = 0; i < array_get_length(system._entities); i++) {
        system.process(ARRAY_AT(Entity *, system._entities, i));
    }
}
