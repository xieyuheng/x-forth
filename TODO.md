# primitives

primitives/testing -- ok

primitives/bool -- and or not

primitives/value -- eq

primitives/stack -- dup swap drop rot over tuck

primitives/int -- add sub mul div mod
primitives/float -- fadd fsub fmul fdiv fmod

primitives/int -- int-to-float
primitives/float -- float-to-int

# lang

[lang] execute_token -- handle literal int and float

# vm

[vm] op_print -- fix for literal

# value

[value] xobject use use global address as kind
