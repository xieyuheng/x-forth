#include "index.h"

void
execute_operation(vm_t *vm, frame_t *frame, op_t *unknown_op) {
    switch (unknown_op->kind) {
    case LITERAL_OP: {
        literal_op_t *op = (literal_op_t *) unknown_op;
        stack_push(vm->value_stack, op->value);
        return;
    }

    case CALL_OP: {
        (void) frame;
        // size_t address = to_address(frame_fetch_value(frame, vm->ram));

        // // handle tail-call here.
        // if (frame_is_at_tail(frame, vm->ram)) {
        //     frame_destroy(&frame);
        // } else {
        //     stack_push(vm->return_stack, frame);
        // }

        // stack_push(vm->return_stack, frame_new(address));
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
