#pragma once

struct vm_t {
    mod_t *mod;
    list_t *token_list;
    stack_t *value_stack;
    stack_t *return_stack;
    file_t *out;
    file_t *err;
};

vm_t *vm_new(mod_t *mod);
void vm_destroy(vm_t **self_pointer);
