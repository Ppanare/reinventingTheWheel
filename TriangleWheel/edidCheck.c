#include <stdio.h>

// Функция для чтения EDID данных из файла
void readEDIDData(const char *filename, unsigned char edidData[128]) {
    FILE *file = fopen(filename, "rb");
    if (file) {
        fread(edidData, sizeof(unsigned char), 128, file);
        fclose(file);
    }
}

// Функция для определения разрешения матрицы из EDID данных
void getNativeResolution(const unsigned char edidData[128], int *width, int *height) {

	//TODO реализовать функию парсинга EDID
	
}

int main() {
    unsigned char edidData[128];
    readEDIDData("edid.dat", edidData);

    int matrixWidth, matrixHeight;
    getNativeResolution(edidData, &matrixWidth, &matrixHeight);

    // TODO Просмотр поддерживаемых видеорежимов и вывод "Native" для режимов с разрешением, равным разрешению матрицы
    printf("Поддерживаемые видеорежимы:\n");
    // Реализовать эту часть, чтобы пройтись по списку видеорежимов и сравнить разрешения

    return 0;
}