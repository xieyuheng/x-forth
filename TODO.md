# vm

[vm] mod_new
[vm] mod_destroy

[vm] primitive_t
[vm] primitive_def
[vm] def_t -- union

[vm] fix mod_new -- for def_t
[vm] fix mod_destroy -- for def_t

[vm] vm has mod
[vm] vm has token_list

[vm] vm_execute_token



[vm] test the outer interpreter

# vm

[vm] instruction_t -- call_instruction_t

- 读 POL 看看如何处理 if then else -- 也许不需要 instruction

[vm] function_t -- has a list of instructions

[vm] frame has function

[vm] fix frame_fetch_value

[vm] fix vm_step

[vm] function_def
