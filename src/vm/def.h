#pragma once

typedef enum {
    PRIMITIVE_DEF,
    FUNCTION_DEF,
} def_kind_t;

struct def_t {
    def_kind_t kind;
    union {
        primitive_def_t *as_primitive_def;
        function_def_t *as_function_def;
    };
};

const primitive_def_t *def_as_primitive_def(const def_t *def);
const function_def_t *def_as_function_def(const def_t *def);

def_t *def_from_primitive_def(primitive_def_t *primitive_def);
def_t *def_from_function_def(function_def_t *function_def);

void def_destroy(def_t **self_pointer);

const char *def_name(const def_t *self);
const char *def_kind_name(def_kind_t kind);

void def_print(const def_t *self, file_t *file);
