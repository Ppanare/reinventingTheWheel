#include <stdio.h>

// Функция для подсчета уровня вложенности
int countIndentLevel(char *line) {
    int level = 0;
    while (*line == ' ' || *line == '\t') {
        level++;
        line++;
    }
    return level;
}

int main() {
    FILE *file = fopen("input.json", "r"); // Открываем файл для чтения
    if (file == NULL) {
        perror("Ошибка при открытии файла");
        return 1;
    }

    int integerCount = 0;
    int stringCount = 0;
    int currentLevel = 0;
    char line[4096]; // Буфер для хранения строки

    while (fgets(line, sizeof(line), file) != NULL) {
        int level = countIndentLevel(line);

        if (level == currentLevel) {
            // Соответствует текущему уровню, обработаем строку
            if (sscanf(line, "\"%*[^\":]\": %d", &integerCount) == 1) {
                printf("Integer: %d (Level: %d)\n", integerCount, currentLevel);
            } else if (strstr(line, "\"string\"") != NULL) {
                stringCount++;
            }
        } else if (level > currentLevel) {
            // Уровень увеличился
            currentLevel = level;
        }
    }

    printf("Количество строк: %d\n", stringCount);

    fclose(file); // Закрываем файл
    return 0;
}