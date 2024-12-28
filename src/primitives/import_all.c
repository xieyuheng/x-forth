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

    // value

    define_primitive_2_fn(mod, "eq", x_eq);
    define_primitive_vm_fn(mod, "dup", x_dup);
    define_primitive_vm_fn(mod, "swap", x_swap);
    define_primitive_vm_fn(mod, "drop", x_drop);
    define_primitive_vm_fn(mod, "rot", x_rot);
    define_primitive_vm_fn(mod, "over", x_over);
    define_primitive_vm_fn(mod, "tuck", x_tuck);

    // testing

    define_primitive_vm_fn(mod, "ok", x_ok);

    // int

    // define_primitive_2_fn(mod, "add", x_add);
    // define_primitive_2_fn(mod, "sub", x_sub);
    // define_primitive_2_fn(mod, "mul", x_mul);
    // define_primitive_2_fn(mod, "div", x_div);
    // define_primitive_2_fn(mod, "mod", x_mod);
    // define_primitive_1_fn(mod, "int-to-float", x_int_to_float);

    // float

    // define_primitive_2_fn(mod, "fadd", x_fadd);
    // define_primitive_2_fn(mod, "fsub", x_fsub);
    // define_primitive_2_fn(mod, "fmul", x_fmul);
    // define_primitive_2_fn(mod, "fdiv", x_fdiv);
    // define_primitive_2_fn(mod, "fmod", x_fmod);
    // define_primitive_1_fn(mod, "float-to-int", x_float_to_int);
}
