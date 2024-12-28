#pragma once

struct vm_t {
    mod_t *mod;
    list_t *token_list;
    stack_t *value_stack;
    stack_t *return_stack;
};

vm_t *vm_new(mod_t *mod);
void vm_destroy(vm_t **self_pointer);

void vm_print_return_stack(const vm_t *self, file_t *file);
void vm_print_value_stack(const vm_t *self, file_t *file);
void vm_print(const vm_t *self, file_t *file);
