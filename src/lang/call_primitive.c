#include "index.h"

void
call_primitive(vm_t *vm, const primitive_def_t *def) {
    (void) def->fn_kind;
    def->primitive_vm_fn(vm);
    return;
}
