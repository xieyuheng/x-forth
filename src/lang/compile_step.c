#include "index.h"

static bool
compile_int(vm_t *vm, function_t *function, function_ctx_t *ctx) {
    (void) ctx;

    token_t *token = list_first(vm->token_list);
    if (token->kind != INT_TOKEN) return false;
    if (!string_is_xint(token->string)) return false;
    (void) list_shift(vm->token_list);

    value_t value = xint(string_parse_xint(token->string));
    function_add_op(function, (op_t *) literal_op_new(value));
    token_destroy(&token);
    return true;
}

static bool
compile_float(vm_t *vm, function_t *function, function_ctx_t *ctx) {
    (void) ctx;

    token_t *token = list_first(vm->token_list);
    if (token->kind != FLOAT_TOKEN) return false;
    if (!string_is_double(token->string)) return false;
    (void) list_shift(vm->token_list);

    value_t value = xfloat(string_parse_double(token->string));
    function_add_op(function, (op_t *) literal_op_new(value));
    token_destroy(&token);
    return true;
}

static bool
compile_generic(vm_t *vm, function_t *function, function_ctx_t *ctx) {
    (void) ctx;

    token_t *token = list_first(vm->token_list);
    const def_t *def = mod_find_def(vm->mod, token->string);
    if (def == NULL) {
        fprintf(stderr, "[function_emit_call] undefined name: %s\n", token->string);
        exit(1);
    }

    (void) list_shift(vm->token_list);
    function_add_op(function, (op_t *) call_op_new(def));
    token_destroy(&token);
    return true;
}

void
compile_step(vm_t *vm, function_t *function, function_ctx_t *ctx) {
    if (compile_int(vm, function, ctx)) return;
    if (compile_float(vm, function, ctx)) return;
    if (compile_generic(vm, function, ctx)) return;

    token_t *token = list_first(vm->token_list);
    fprintf(stderr, "[compile_step] unknown token: %s\n", token->string);
}
