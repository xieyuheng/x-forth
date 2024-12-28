#include "index.h"

void
import_all(mod_t *mod) {
    // null
    define_constant(mod, "null", xnull);

    // bool
    define_constant(mod, "false", xfalse);
    define_constant(mod, "true", xtrue);
}
