[primitives] x_define_function -- consume token_list from vm

# object

[value] object_spec_t -- xobject use global address of object_spec_t as kind
[value] object_spec_t -- has name
[value] object_spec_t -- has optional description

# global variable

[value] xvar_t -- should be an xobject

[value] x_define_variable

xvar_get(variable)
xvar_set(variable, value)

# local variable

use `( ... )` for local variable

# string

"..." for string

# function

use `{ ... }` for function

# struct

```
define-struct node-t
  name { is-string }
  next { type node-t eq }
end
```
