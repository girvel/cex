#include "components.h"


// TODO autogenerate these with like
// DEFINE_COMPONENT(COMPONENT_NAME, Name, String text;)
Name *name_get(Entity e) {
    return entity_get_component(e, COMPONENT_NAME);
}

void name_set(Entity e, String text) {
    Name *result = malloc(sizeof(Name));
    result->text = text;
    entity_set_component(e, COMPONENT_NAME, result);
}

Position *position_get(Entity e) {
    return entity_get_component(e, COMPONENT_POSITION);
}

void position_set(Entity e, int x) {
    Position *result = malloc(sizeof(Position));
    result->x = x;
    entity_set_component(e, COMPONENT_POSITION, result);
}
