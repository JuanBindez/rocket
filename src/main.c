#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/exe_commands.h"
#include "include/help.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        showHelp();
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            showHelp();
            return 0;
        } else if (strcmp(argv[i], "-v") == 0) {
            showVersion();
            return 0;
        } else {
            char *extension = strrchr(argv[i], '.');
            if (extension != NULL && strcmp(extension, ".Makeline") == 0) {
                executeCommands(argv[i]);
            } else if (strcmp(argv[i], "Makeline") == 0) {
                executeCommands(argv[i]);
            }
        }
    }

    return 0;
}
