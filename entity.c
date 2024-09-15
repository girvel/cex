#include "entity.h"


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
    // TODO disallow overwriting components
    *((void **) array_at(e._components, component_id)) = component;
}

void *entity_get_component(Entity e, size_t component_id) {
    return ARRAY_AT(void *, e._components, component_id);
}

