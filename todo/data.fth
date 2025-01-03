claim list-t type-t -> type-t end
define-data list-t element-t end
// generate list-t list-t/element-t

claim cons-list 'A list-t 'A -> 'A list-t end
define-data cons-list tail head end
// generate: cons-list cons-list/tail cons-list/head

claim null-list -> 'A list-t end
define-data null-list end
// generate: null-list

null-list 1 cons-list ( list )
list cons-list/head 1 eq ok
list cons-list/tail null-list eq ok

list free
