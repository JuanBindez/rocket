#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "1.0-rc5"
#define AUTHOR "Copyright (C) 2023 Juan Bindez <juanbindez780@gmail.com>"
#define LICENSE "GPLv2 License"

void showHelp() {
    printf("Makeline %s\n\n", VERSION);
    printf("%s\n", AUTHOR);
    printf("%s\n\n", LICENSE);
    printf("Usage: makeline [-h]\n");
    printf("Executes commands from a configuration file.\n\n");
    printf("Options:\n");
    printf("  -h\t\tDisplay this help message.\n");
    printf("  -v\t\tDisplays the program version.\n");
}

void showVersion() {
    printf("Version: %s\n", VERSION);
}


