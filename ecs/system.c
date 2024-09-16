#include "system.h"
#include "../framework/array.h"


System system_create(Array required_components, void (*process)(Entity *)) {
    return (System) {
        .process = process,
        ._required_components = required_components,
        ._entities = array_new(sizeof(Entity *)),
    };
}

void system_free(System *system) {
    array_free(&system->_entities);
}

bool system_add(System *system, Entity *item) {
    for (size_t i = 0; i < array_get_length(system->_required_components); i++) {
        if (entity_get_component(*item, ARRAY_AT(int, system->_required_components, i)) == NULL) {
            return false;
        }
    }

    ARRAY_APPEND(Entity *, &system->_entities, item);
    return true;
}

void system_update(System system) {
    for (size_t i = 0; i < array_get_length(system._entities); i++) {
        system.process(ARRAY_AT(Entity *, system._entities, i));
    }
}
