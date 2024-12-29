[lang] compile_int_token
[lang] compile_float_token

# local variable

[lang] compile_function -- setup function_ctx_t
[lang] compile_token -- take function_ctx_t
use `( ... )` for local variable

# object

[value] object_spec_t -- xobject use global address of object_spec_t as kind
[value] object_spec_t -- has name
[value] object_spec_t -- has optional description

# global variable

[value] xvar_t -- should be an xobject

[value] x_define_variable

xvar_get(variable)
xvar_set(variable, value)

# string

xstring -- as xobject

"..." for string

# function

function_t as xobject

use `{ ... }` for function

# struct

```
define-struct node-t
  name { is-string }
  next { type node-t eq }
end
```
