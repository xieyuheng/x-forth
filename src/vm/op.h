#pragma once

// abbreviation of "operation" (not "opcode")
struct op_t { op_kind_t kind; };

struct call_op_t {
    op_kind_t kind;
    const def_t *def;
};

call_op_t *call_op_new(const def_t *def);
void call_op_destroy(call_op_t **self_pointer);

void op_destroy(op_t **self_pointer);

void op_print(const op_t *self, file_t *file);
