#include "index.h"

static bool
execute_int_token(vm_t *vm, const token_t *token) {
    if (token->kind != INT_TOKEN) return false;
    if (!string_is_xint(token->string)) return false;

    value_t value = xint(string_parse_xint(token->string));
    stack_push(vm->value_stack, value);
    return true;
}

static bool
execute_float_token(vm_t *vm, const token_t *token) {
    if (token->kind != FLOAT_TOKEN) return false;
    if (!string_is_double(token->string)) return false;

    value_t value = xfloat(string_parse_double(token->string));
    stack_push(vm->value_stack, value);
    return true;
}

static bool
execute_generic_token(vm_t *vm, const token_t *token) {
    if (token->kind != GENERIC_TOKEN)
        return false;

    function_t *function = function_new();
    compile_token(vm, token, function);
    function_build(function);

    size_t base_length = stack_length(vm->return_stack);
    stack_push(vm->return_stack, frame_new(function));
    run_vm_until(vm, base_length);

    function_destroy(&function);
    return true;
}

void
execute_token(vm_t *vm, const token_t *token) {
    if (execute_int_token(vm, token)) return;
    if (execute_float_token(vm, token)) return;
    if (execute_generic_token(vm, token)) return;

    fprintf(stderr, "[execute_token] unknown token: %s\n", token->string);
}
