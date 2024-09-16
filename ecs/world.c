#include "world.h"
#include "system.h"


World world_create(int component_max_id) {
    return (World) {
        ._all_entities = array_new(sizeof(Entity *)),
        ._systems = array_new(sizeof(System *)),
        ._component_max_id = component_max_id,
    };
}

void world_free(World *world) {
    array_free(&world->_all_entities);
    array_free(&world->_systems);
}

Entity world_add_entity(World world);
void world_commit_entity(World *world, Entity *e);
void world_update();
