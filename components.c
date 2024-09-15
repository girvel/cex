#include "components.h"


Name *name_create(String text) {
    Name *result = malloc(sizeof(Name));
    result->text = text;
    return result;
}

// TODO autogenerate these with like
// DEFINE_COMPONENT(COMPONENT_NAME, Name, String text;)
Name *name_get(Entity e) {
    return entity_get_component(e, COMPONENT_NAME);
}

Position *position_create(int x) {
    Position *position = malloc(sizeof(Position));
    position->x = x;
    return position;
}

Position *position_get(Entity e) {
    return entity_get_component(e, COMPONENT_POSITION);
}
