#pragma once

typedef enum {
    CALL_OP,
    LITERAL_OP,
} op_kind_t;

typedef struct mod_t mod_t;
typedef struct frame_t frame_t;
typedef struct primitive_def_t primitive_def_t;
typedef struct def_t def_t;
typedef struct op_t op_t;
typedef struct call_op_t call_op_t;
typedef struct literal_op_t literal_op_t;
typedef struct vm_t vm_t;
