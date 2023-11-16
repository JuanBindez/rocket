#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void executeGitCommands(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de configuração");
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

int main() {
    const char *configFileName = "Makegit";

    executeGitCommands(configFileName);

    return 0;
}
