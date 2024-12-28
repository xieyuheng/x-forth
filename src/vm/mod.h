#pragma once

// A mod is a compilation unit,
// like the dictionary of forth.

struct mod_t {
    const char *src;
    const char *code;
    hash_t *def_hash;
};
