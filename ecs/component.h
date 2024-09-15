#pragma onc

// TODO CONCAT
#define COMPONENT_DEFINE(NAME, FIELDS) \
    typedef struct { \
        void *_deallocator; \
        FIELDS \
    } NAME;

#define COMPONENT_GETTER(ID, NAME) \
    NAME *NAME##_get(Entity e) { \
        return (NAME *)entity_get_component(e, (ID)); \
    }
