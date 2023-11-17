#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_LENGTH 1000
#define VERSION "1.0-rc3"
#define AUTHOR "2023 Juan Bindez <juanbindez780@gmail.com>"
#define LICENSE "GPLv2 License"

void showHelp() {
    printf("Makeline Version: %s\n\n", VERSION);
    printf("Usage: makeline [-h]\n");
    printf("Executes commands from a configuration file.\n\n");
    printf("Author: %s\n", AUTHOR);
    printf("License: %s\n\n", LICENSE);
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

void processFilesWithExtension(const char *extension) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(".")) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG &&
                (strcmp(ent->d_name, "Makeline") == 0 || strstr(ent->d_name, extension) != NULL)) {
                executeCommands(ent->d_name);
            }
        }
        closedir(dir);
    } else {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    const char *configFileExtension = ".Makeline";

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        showHelp();
        return 0;
    }

    if (argc == 2 && strcmp(argv[1], "-v") == 0) {
        showVersion();
        return 0;
    }

    processFilesWithExtension(configFileExtension);

    return 0;
}
