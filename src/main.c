#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define VERSION "1.0-rc2"
#define AUTHOR "2023 Juan Bindez <juanbindez780@gmail.com>"
#define LICENSE "GPLv2 License"

void showHelp() {
    printf("Usage: makeline [-h]\n");
    printf("Executes commands from a configuration file.\n\n");
    printf("Author: %s\n", AUTHOR);
    printf("License: %s\n", LICENSE);
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
        perror("Erro");
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
    const char *configFileName = "Makeline";

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        showHelp();
        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "-v") == 0) {
        showVersion();
        return 0;
    }

    executeCommands(configFileName);

    return 0;
}
