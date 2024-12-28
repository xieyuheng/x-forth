[lang] execute_token -- handle literal int and float

primitives/int -- add sub mul div mod
primitives/float -- fadd fsub fmul fdiv fmod

primitives/int -- int-to-float
primitives/float -- float-to-int

primitives/testing -- ok -- call vm_print

# vm

[vm] op_print -- fix for literal

# value

[value] xobject use use global address as kind
