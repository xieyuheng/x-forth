#include "index.h"

const primitive_def_t *
def_as_primitive_def(const def_t *def) {
    assert(def);
    assert(def->kind == PRIMITIVE_DEF);
    return def->as_primitive_def;
}

// const function_def_t *
// def_as_function_def(const def_t *def) {
//     assert(def);
//     assert(def->kind == FUNCTION_DEF);
//     return def->as_function_def;
// }

def_t *
def_from_primitive_def(primitive_def_t *primitive_def) {
    def_t *self = new(def_t);
    self->kind = PRIMITIVE_DEF;
    self->as_primitive_def = primitive_def;
    return self;
}

// def_t *
// def_from_function_def(function_def_t *function_def) {
//     def_t *self = new(def_t);
//     self->kind = FUNCTION_DEF;
//     self->as_function_def = function_def;
//     return self;
// }

void
def_destroy(def_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        def_t *self = *self_pointer;

        switch (self->kind) {
        case PRIMITIVE_DEF: {
            primitive_def_destroy(&self->as_primitive_def);
            break;
        }

        // case FUNCTION_DEF: {
        //     function_def_destroy(&self->as_function_def);
        //     break;
        // }
        }

        free(self);
        *self_pointer = NULL;
    }
}

const char *
def_name(const def_t *def) {
    switch (def->kind) {
    case PRIMITIVE_DEF: {
        return def->as_primitive_def->name;
    }

    // case FUNCTION_DEF: {
    //     return def->as_function_def->name;
    // }
    }

    assert(false);
}

const char *
def_kind_name(def_kind_t kind) {
    switch (kind) {
    case PRIMITIVE_DEF: {
        return "primitive";
    }

    // case FUNCTION_DEF: {
    //     return "function";
    // }
    }

    assert(false);
}

void
def_print(const def_t *def, file_t *file) {
    switch (def->kind) {
    case PRIMITIVE_DEF: {
        fprintf(file, "%s", def->as_primitive_def->name);
        return;
    }

    // case FUNCTION_DEF: {
    //     fprintf(file, "= %s ", def->as_function_def->name);
    //     function_print(def->as_function_def->function, file);
    //     return;
    // }
    }

    assert(false);
}
