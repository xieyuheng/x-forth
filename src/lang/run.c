#include "index.h"

void
step_vm(vm_t *self) {
    if (stack_is_empty(self->return_stack)) return;

    frame_t *frame = stack_pop(self->return_stack);
    if (frame_is_finished(frame)) return;

    op_t *op = frame_fetch_op(frame);
    // proper tail-call = do not push finished frame.
    bool finished = frame_is_finished(frame);
    if (!finished) stack_push(self->return_stack, frame);
    execute(self, frame, op);
    if (finished) frame_destroy(&frame);
}

void
run_vm_until(vm_t *self, size_t base_length) {
    while (stack_length(self->return_stack) > base_length) {
        step_vm(self);
    }
}

void
run_vm(vm_t *self) {
    while (!stack_is_empty(self->return_stack)) {
        step_vm(self);
    }
}
