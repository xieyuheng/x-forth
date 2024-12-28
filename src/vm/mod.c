#include "index.h"

mod_t *
mod_new(const char *src, const char *code) {
    mod_t *self = new(mod_t);
    self->src = src;
    self->code = code;
    self->def_hash = hash_new();
    return self;
}

void
mod_destroy(mod_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        mod_t *self = *self_pointer;
        hash_destroy(&self->def_hash);
        free(self);
        *self_pointer = NULL;
    }
}
