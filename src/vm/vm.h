#pragma once

struct vm_t {
    mod_t *mod;
    stack_t *value_stack;
    stack_t *return_stack;
    file_t *out;
    file_t *err;
};

vm_t *vm_new(mod_t *mod);
void vm_destroy(vm_t **self_pointer);

void vm_step(vm_t *self);
void vm_run_until(vm_t *self, size_t base_length);
void vm_run(vm_t *self);
