#include "index.h"

static bool
compile_generic_token(vm_t *vm, const token_t *token, function_t *function) {
    function_emit_call(function, vm->mod, token->string);
    return true;
}

void
compile_token(vm_t *vm, const token_t *token, function_t *function) {
    if (compile_generic_token(vm, token, function)) return;

    fprintf(stderr, "[compile_token] unknown token: %s\n", token->string);
}
