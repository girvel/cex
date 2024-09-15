#include "components.h"


COMPONENT_GETTER(COMPONENT_NAME, name);

void _name_dispose(name *name) {
    string_free(&name->text);
}

void name_set(Entity e, String text) {
    name *result = malloc(sizeof(name));
    result->_deallocator = &_name_dispose;
    result->text = text;
    entity_set_component(e, COMPONENT_NAME, result);
}

COMPONENT_GETTER(COMPONENT_POSITION, position);

void position_set(Entity e, int x) {
    position *result = malloc(sizeof(position));
    result->_deallocator = NULL;
    result->x = x;
    entity_set_component(e, COMPONENT_POSITION, result);
}
