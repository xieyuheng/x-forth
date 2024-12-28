#include "index.h"

value_t x_print(value_t x) {
    value_print(x, stdout);
    return NULL;
}

value_t x_newline(void) {
    printf("\n");
    return NULL;
}
