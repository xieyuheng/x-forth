define-datatype list-t type-t -- type-t where
  case cons 'A list-t 'A -- 'A list-t end
  case nil -- 'A list-t end
end

claim match 'A list-t -- 'A list-t 'A | nop end

claim list-lenght 'A list-t -- int-t end
define list-lenght
  match
    0 co-swap
    drop list-lenght 1 add
  merge
end
