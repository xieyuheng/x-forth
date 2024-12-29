#include "index.h"
#include "../lang/index.h"
#include "../primitives/index.h"

static int run(commander_t *commander);

void
run_command(commander_t *runner) {
    command_t *command = command_new("run");
    command->description = "run files";
    command->run = run;
    commander_add(runner, command);
}

void
run_file(const char *path) {
    file_t *file = file_open_or_fail(path, "r");
    const char *code = file_read_string(file);
    fclose(file);

    mod_t *mod = mod_new(path, code);
    import_all(mod);
    vm_t *vm = vm_new(mod);

    execute_vm(vm);

    mod_destroy(&mod);
    vm_destroy(&vm);
}

int
run(commander_t *commander) {
    char **paths = commander_rest_argv(commander);
    while (*paths) {
        char *path = *paths++;
        if (string_ends_with(path, ".fth")) {
            run_file(path);
        } else  {
            fprintf(stderr, "[run] file name must ends with .fth, given file name: %s\n", path);
            exit(1);
        }
    }

    return 0;
}
