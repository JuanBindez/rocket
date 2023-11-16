#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Função para executar comandos do Git a partir do arquivo de configuração
void executeGitCommands(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de configuração");
        exit(EXIT_FAILURE);
    }

    char command[MAX_LENGTH];
    while (fgets(command, sizeof(command), file) != NULL) {
        // Remover a quebra de linha no final do comando
        char *newline = strchr(command, '\n');
        if (newline != NULL) {
            *newline = '\0';
        }

        // Executar o comando Git
        system(command);
    }

    fclose(file);
}

int main() {
    // Nome do arquivo de configuração
    const char *configFileName = "Makegit";

    // Executar os comandos do Git a partir do arquivo de configuração
    executeGitCommands(configFileName);

    return 0;
}
