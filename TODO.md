# object

[value] object_spec_t -- xobject use global address of object_spec_t as kind
[value] object_spec_t -- has name
[value] object_spec_t -- has optional description

# string

xstring -- as xobject

"..." for string

# function

function_t as xobject

use `{ ... }` for function

# record

learn from jai about how to handle type with parameters

a record is implemented as a hash table

- with `!` as onwership mark
- [problem] should we use `.` or `:`?

```
define-record node-t
  .name! string-t
  .next node-t
end

node .name
```

# global variable

[value] xvar_t -- should be an xobject

[value] x_define_variable

xvar_get(variable)
xvar_set(variable, value)
