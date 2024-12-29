#include "index.h"

void x_define_function(vm_t *vm) {
    token_t *token = list_shift(vm->token_list);
    function_t *function = function_new();
    define_function(vm->mod, token->string, function);
    token_destroy(&token);

    while (true) {
        assert(list_length(vm->token_list) > 0);
        token_t *token = list_shift(vm->token_list);
        if (string_equal(token->string, "end")) {
            token_destroy(&token);
            function_build(function);
            return;
        }

        //
    }
}
