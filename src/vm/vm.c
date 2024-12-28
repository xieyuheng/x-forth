#include "index.h"

vm_t *
vm_new(size_t ram_size) {
    vm_t *self = new(vm_t);
    self->ram = ram_new(ram_size);
    self->value_stack = stack_new();
    self->return_stack = stack_new_with((destroy_fn_t *) frame_destroy);
    return self;
}

void
vm_destroy(vm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        vm_t *self = *self_pointer;
        stack_destroy(&self->value_stack);
        stack_destroy(&self->return_stack);
        ram_destroy(&self->ram);
        free(self);
        *self_pointer = NULL;
    }
}

void
vm_step(vm_t *self) {
    if (stack_is_empty(self->return_stack))
        return;

    frame_t *frame = stack_pop(self->return_stack);
    // if (frame_is_at_tail(frame, self->ram))
    //     return;
    
    execute(self, frame);
}

void
vm_run_until(vm_t *self, size_t base_length) {
    while (stack_length(self->return_stack) > base_length) {
        vm_step(self);
    }
}

void
vm_run(vm_t *self) {
    while (!stack_is_empty(self->return_stack)) {
        vm_step(self);
    }
}

void
vm_emu(const blob_t *blob) {
    vm_t *self = vm_new(blob_size(blob));
    blob_copy_into(blob, self->ram->bytes);
    stack_push(self->return_stack, frame_new(0));
    vm_run(self);
    vm_destroy(&self);
}
