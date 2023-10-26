#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_json(const char *json, int level);

int main() {
    FILE *file;
    char filename[] = "input.json"; 

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *json_buffer = (char *)malloc(file_size + 1);
    if (json_buffer == NULL) {
        printf("Ошибка выделения памяти для буфера.\n");
        fclose(file);
        return 1;
    }

    fread(json_buffer, 1, file_size, file);
    json_buffer[file_size] = '\0';

    fclose(file);

    print_json(json_buffer, 0);

    free(json_buffer);

    return 0;
}

void print_json(const char *json, int level) {
    int inside_string = 0;

    while (*json) {
        if (*json == '{' || *json == '[') {
            level++;
            printf("Level %d\n", level);
        } else if (*json == '}' || *json == ']') {
            level--;
        } else if (*json == '"') {
            inside_string = !inside_string;
        } else if (!inside_string && (*json >= '0' && *json <= '9')) {
            printf("Integer: %c (Level %d)\n", *json, level);
        }

        json++;
    }
}