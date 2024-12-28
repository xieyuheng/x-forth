# vm

primitives/x_int
primitives/x_float
primitives/x_bool
primitives/x_stack
primitives/x_testing -- x_ok

[vm] instruction_t -- call_instruction_t
- 读 POL 看看如何处理 if then else -- 也许不需要 instruction
[vm] function_t -- has a list of instructions
[vm] frame has function
[vm] fix frame_fetch_value
[vm] fix vm_step
[vm] function_def

[vm] vm_execute_token

[vm] test the outer interpreter
