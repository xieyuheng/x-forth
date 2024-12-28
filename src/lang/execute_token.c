#include "index.h"

void
execute_token(vm_t *vm, const token_t *token) {
    char *name = token->string;
    const def_t *def = mod_find_def(vm->mod, name);
    if (def == NULL) {
        fprintf(vm->err, "[execute_token] undefined name: %s\n", name);
        exit(1);
    }

    function_t *function = function_new();
    function_add_op(function, (op_t *) call_op_new(def));
    function_build(function);

    size_t base_length = stack_length(vm->return_stack);
    stack_push(vm->return_stack, frame_new(function));
    run_vm_until(vm, base_length);

    function_destroy(&function);
}
