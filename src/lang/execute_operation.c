#include "index.h"

void
execute_operation(vm_t *vm, frame_t *frame, op_t *unknown_op) {
    (void) frame;

    switch (unknown_op->kind) {
    case LITERAL_OP: {
        literal_op_t *op = (literal_op_t *) unknown_op;
        stack_push(vm->value_stack, op->value);
        return;
    }

    case CALL_OP: {
        call_op_t *op = (call_op_t *) unknown_op;
        call(vm, op->def);
        return;
    }
    }

    assert(false && "[execute] unknown opcode");
}
