#include "index.h"

frame_t *
frame_new(size_t address) {
    frame_t *self = new(frame_t);
    self->address = address;
    return self;
}

void
frame_destroy(frame_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        frame_t *self = *self_pointer;
        free(self);
        *self_pointer = NULL;
    }
}

value_t
frame_fetch_value(frame_t *self) {
    (void) self; 
    
    return NULL;
}

uint8_t
frame_fetch_byte(frame_t *self) {
    (void) self;
    return 0;
}
