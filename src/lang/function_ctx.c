#include "index.h"

function_ctx_t *
function_ctx_new(void) {
    function_ctx_t *self = new(function_ctx_t);
    self->local_index_hash = hash_new_of_string_key();
    return self;
}
