#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define VERSION "1.0-rc4"
#define AUTHOR "Copyright (C) 2023 Juan Bindez <juanbindez780@gmail.com>"
#define LICENSE "GPLv2 License"

void showHelp() {
    printf("Makeline %s\n\n", VERSION);
    printf("Usage: makeline [-h]\n");
    printf("Executes commands from a configuration file.\n\n");
    printf("%s\n", AUTHOR);
    printf("%s\n\n", LICENSE);
    printf("Options:\n");
    printf("  -h\t\tDisplay this help message.\n");
    printf("  -v\t\tDisplays the program version.\n");
}

void showVersion() {
    printf("Version: %s\n", VERSION);
}

void executeCommands(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    char command[MAX_LENGTH];
    while (fgets(command, sizeof(command), file) != NULL) {
        char *newline = strchr(command, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        system(command);
    }

    fclose(file);
}

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
