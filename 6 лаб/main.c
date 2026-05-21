#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    FILE *fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Ошибка открытия входного файла\n");
        return 1;
    }

    FILE *fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Ошибка создания выходного файла\n");
        fclose(fin);
        return 1;
    }

    char surname[50];
    char name[50];
    char patronymic[50];
    int year;

    while (fscanf(fin, "%49s %49s %49s %d", surname, name, patronymic, &year) == 4) {
        if (year > 1980) {
            fprintf(fout, "%s %s %s %d\n", surname, name, patronymic, year);
        }
    }

    fclose(fin);
    fclose(fclose(fout) ? fout : fout);

    printf("Обработка файла завершена успешно\n");
    return 0;
}
