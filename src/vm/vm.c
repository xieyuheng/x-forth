#include "index.h"

static list_t *
lex_code(const char *code) {
    lexer_t *lexer = lexer_new();
    lexer->enable_int = true;
    lexer->enable_float = true;
    lexer->enable_string = true;
    lexer->line_comment = "--";
    lexer->string = code;
    lexer_run(lexer);

    list_t *token_list = lexer->token_list;
    lexer_destroy(&lexer);
    return token_list;
}

vm_t *
vm_new(mod_t *mod) {
    vm_t *self = new(vm_t);
    self->mod = mod;
    self->token_list = lex_code(mod->code);
    self->value_stack = stack_new();
    self->return_stack = stack_new_with((destroy_fn_t *) frame_destroy);
    self->out = stdout;
    self->err = stderr;
    return self;
}

void
vm_destroy(vm_t **self_pointer) {
    assert(self_pointer);
    if (*self_pointer) {
        vm_t *self = *self_pointer;
        // vm does not own mod
        list_destroy(&self->token_list);
        stack_destroy(&self->value_stack);
        stack_destroy(&self->return_stack);
        free(self);
        *self_pointer = NULL;
    }
}
