#include "index.h"

struct frame_t {
    size_t function_counter;
    const function_t *function;
};


frame_t *
frame_new(const function_t *function) {
    frame_t *self = new(frame_t);
    self->function_counter = 0;
    self->function = function;
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

bool
frame_is_finished(const frame_t *self) {
    return self->function_counter == function_length(self->function);
}

op_t *
frame_fetch_op(frame_t *self) {
    op_t *op = function_get_op(self->function, self->function_counter);
    self->function_counter++;
    return op;
}

void
frame_print(const frame_t *self, file_t *file) {
    fprintf(file, "<frame>\n");

    fprintf(file, "<function>\n");
    function_print_with_function_counter(self->function, file, self->function_counter);
    fprintf(file, "</function>\n");

    fprintf(file, "</frame>\n");
}
