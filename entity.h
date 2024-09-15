#pragma once

#include "framework/dynamic_array.h"


typedef struct {
  DynamicArray _components;
} Entity;

Entity entity_create(size_t max_components_n);
void entity_set_component(Entity e, size_t component_id, void *component);
void *entity_get_component(Entity e, size_t component_id);
