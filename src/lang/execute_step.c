#include "index.h"

static bool
execute_int_token(vm_t *vm) {
    token_t *token = list_first(vm->token_list);
    if (token->kind != INT_TOKEN) return false;
    if (!string_is_xint(token->string)) return false;
    (void) list_shift(vm->token_list);

    value_t value = xint(string_parse_xint(token->string));
    stack_push(vm->value_stack, value);
    token_destroy(&token);
    return true;
}

static bool
execute_float_token(vm_t *vm) {
    token_t *token = list_first(vm->token_list);
    if (token->kind != FLOAT_TOKEN) return false;
    if (!string_is_double(token->string)) return false;
    (void) list_shift(vm->token_list);

    value_t value = xfloat(string_parse_double(token->string));
    stack_push(vm->value_stack, value);
    token_destroy(&token);
    return true;
}

static bool
execute_generic_token(vm_t *vm) {
    token_t *token = list_first(vm->token_list);
    if (token->kind != GENERIC_TOKEN) return false;
    (void) list_shift(vm->token_list);

    function_t *function = function_new();
    function_ctx_t *ctx = function_ctx_new();
    compile_step(vm, token, function, ctx);
    function_build(function);

    size_t base_length = stack_length(vm->return_stack);
    stack_push(vm->return_stack, frame_new(function));
    run_vm_until(vm, base_length);

    function_ctx_destroy(&ctx);
    function_destroy(&function);
    return true;
}

void
execute_step(vm_t *vm) {
    if (execute_int_token(vm) ||
        execute_float_token(vm) ||
        execute_generic_token(vm))
    {
        return;
    }

    token_t *token = list_first(vm->token_list);
    fprintf(stderr, "[execute_step] unknown token: %s\n", token->string);
}
