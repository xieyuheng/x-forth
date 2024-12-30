#pragma once

void compile_step(vm_t *vm, token_t *token, function_t *function, function_ctx_t *ctx);
function_t *compile_function(vm_t *vm);
