#include <stdio.h>

int main() {
    // 1. Создаем первый файл и записываем в него исходные данные
    FILE *f_out = fopen("input.txt", "w");
    if (f_out == NULL) {
        return 1;
    }
    fprintf(f_out, "Иванов Петр Сергеевич 1975\n");
    fprintf(f_out, "Сидоров Николай Андреевич 1981\n");
    fprintf(f_out, "Воробьянинов Ипполит Матвеевич 1978\n");
    fclose(f_out);

    // 2. Открываем файл с данными для чтения и новый файл для записи результата
    FILE *f_in = fopen("input.txt", "r");
    FILE *f_res = fopen("output.txt", "w");

    if (f_in == NULL || f_res == NULL) {
        return 1;
    }

    char surname[50];
    char name[50];
    char patronymic[50];
    int year;

    // 3. Читаем файл построчно, пока не дойдем до конца (EOF)
    while (fscanf(f_in, "%s %s %s %d", surname, name, patronymic, &n) != EOF) {
        // Проверяем условие: родился позднее 1980 года
        if (year > 1980) {
            fprintf(f_res, "%s %s %s %d\n", surname, name, patronymic, year);
        }
    }

    // 4. Обязательно закрываем оба файла
    fclose(f_in);
    fclose(f_res);

    return 0;
}
