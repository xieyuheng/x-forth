# vm

[vm] op_t -- abbreviation of "operation" (not "opcode")

[vm] call_op_t
[vm] literal_op_t

[vm] function_t -- has an array of operation
[vm] frame has function
[vm] fix frame_fetch_value
[vm] fix vm_step
[vm] function_def

primitives/x_int
primitives/x_float
primitives/x_bool
primitives/x_stack
primitives/x_testing -- x_ok

define_primitive_1
define_primitive_2
define_primitive_3

[vm] vm_execute_token

[vm] test the outer interpreter

# value

[value] xobject use use global address as kind
