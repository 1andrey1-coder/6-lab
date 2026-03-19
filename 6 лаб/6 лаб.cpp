#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";

    // 1. Создание и заполнение исходного файла
    std::ofstream outFile(inputFileName);
    if (!outFile) {
        std::cerr << "Ошибка создания файла!" << std::endl;
        return 1;
    }
    outFile << "Иванов Петр Сергеевич 1975" << std::endl;
    outFile << "Сидоров Николай Андреевич 1981" << std::endl;
    outFile << "Петров Алексей Иванович 1985" << std::endl;
    outFile << "Воробьянинов Ипполит Матвеевич 1978" << std::endl;
    outFile << "Бендер Остап Ибрагимович 1990" << std::endl;
    outFile.close();

    // 2. Чтение и фильтрация данных
    std::ifstream inFile(inputFileName);
    std::ofstream resFile(outputFileName);

    if (!inFile || !resFile) {
        std::cerr << "Ошибка открытия файлов!" << std::endl;
        return 1;
    }

    std::string firstName, middleName, lastName;
    int birthYear;

    // Читаем по структуре: Фамилия Имя Отчество Год
    while (inFile >> firstName >> middleName >> lastName >> birthYear) {
        if (birthYear > 1980) {
            resFile << firstName << " " << middleName << " "
                << lastName << " " << birthYear << std::endl;
        }
    }

    inFile.close();
    resFile.close();

    std::cout << "Файл " << outputFileName << " успешно создан." << std::endl;

    return 0;
}
