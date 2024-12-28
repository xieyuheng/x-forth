#pragma once

void execute_operation(vm_t *self, frame_t *frame, op_t *op);
void execute_token(vm_t *vm, const token_t *token);
void execute_vm(vm_t *vm);
