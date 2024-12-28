#pragma once

void step_vm(vm_t *self);
void run_vm_until(vm_t *self, size_t base_length);
void run_vm(vm_t *self);
