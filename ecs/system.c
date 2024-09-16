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
    array_free(&system->_required_components);
}

bool system_add(System *system, Entity *item) {
    ARRAY_FOR(int, _, component_id, system->_required_components, {
        if (entity_get_component(*item, *component_id) == NULL) {
            return false;
        }
    })

    ARRAY_APPEND(Entity *, &system->_entities, item);
    return true;
}

void system_update(System system) {
    ARRAY_FOR(Entity *, i, e, system._entities, {
        system.process(*e);
    })
}
