change comment to //

# object

[value] object_spec_t -- xobject use global address of object_spec_t as kind
[value] object_spec_t -- has name
[value] object_spec_t -- has optional description

# string

xstring_t -- has text and is_static -- static string will not be free-ed

xstring_new
xstring_destroy

xstring_free
xstring_copy -- simple dup if the string is_static

xstring_append -- consume arguments by calling xstring_free

xstring_get -- (- string-t int-t -> string-t -) does NOT consume string

- handle utf8

[primitive] print -- handle string

[lang] execute_string -- handle STRING_TOKEN
[lang] compile_string -- handle STRING_TOKEN

# char

xchar
xstring_get_char -- does NOT consume string

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
