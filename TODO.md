remove vm_test

# lang

[lang] setup lang/

[lang] move execute to lang

ambr vm_step step_vm
ambr vm_run_until run_vm_until
ambr vm_run run_vm

[lang] move step and run to lang

# vm

[vm] define_primitive_vm_fn
[vm] define_primitive_0_fn
[vm] define_primitive_1_fn
[vm] define_primitive_2_fn
[vm] define_primitive_3_fn
[vm] define_primitive_4_fn

# lang

[lang] rename execute to execute_operation
[lang] fix execute_operation
[lang] execute_token

[lang] test the outer interpreter

# primitives

primitives/x_int
primitives/x_float
primitives/x_bool
primitives/x_stack
primitives/x_testing -- x_ok

# vm

[vm] op_print -- fix for literal

# value

[value] xobject use use global address as kind
