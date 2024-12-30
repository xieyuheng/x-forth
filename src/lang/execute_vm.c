#include "index.h"

void
execute_vm(vm_t *vm) {
    while (!list_is_empty(vm->token_list)) {
        token_t *token = list_shift(vm->token_list);
        execute_token(vm, token);
    }
}
