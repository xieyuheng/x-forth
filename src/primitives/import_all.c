#include "index.h"

void
import_all(mod_t *mod) {
    // null
    define_constant(mod, "null", xnull);

    // bool
    define_constant(mod, "false", xfalse);
    define_constant(mod, "true", xtrue);
    define_primitive_1_fn(mod, "not", xbool_not);
    define_primitive_2_fn(mod, "and", xbool_and);
    define_primitive_2_fn(mod, "or", xbool_or);

    // testing
    define_primitive_vm_fn(mod, "ok", x_ok);
}
