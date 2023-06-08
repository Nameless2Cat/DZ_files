//вариант 24(9)
//задание 29 Реализовать чтение ID3v1 MP3-файла. Будьте внимательны, не все MP3-файлы
//содержат заполненный ID3 - тег.
#include <iostream>
#include <fstream>
#include <cstring>

// Структура для хранения информации о жанре
struct ID3v1Genre {
    char genre[30];
};

int main() {
    // Открываем MP3-файл для чтения в двоичном режиме
    std::ifstream file("example.mp3", std::ios::binary);

    // Перемещаем указатель на конец файла и сдвигаем его на -128 байт
    file.seekg(-128, std::ios::end);

    // Читаем последние 128 байт в буфер
    char buffer[128];
    file.read(buffer, 128);

    // Проверяем наличие тега ID3v1
    if (std::strncmp(buffer, "TAG", 3) == 0) {
        // Читаем информацию о жанре
        ID3v1Genre genre;
        std::strncpy(genre.genre, buffer + 125, 30);

        // Выводим информацию о жанре
        std::cout << "Жанр: " << genre.genre << std::endl;
    }
    else {
        std::cout << "Тег ID3v1 не найден." << std::endl;
    }

    // Закрываем файл
    file.close();

    return 0;
}
//задание 3 I
//Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
//считывать из файла in.txt.Результат записывать в текстовый файл out.txt.Формат
//записи данных :
/*
#include <iostream>
#include <fstream>
#include <cmath>

double factorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calculateFunction(double x, int N) {
    double y = 1.0;
    double term = 1.0;
    for (int i = 1; i <= N; ++i) {
        term *= -x * x / (2 * i);
        y += term / factorial(2 * i);
    }
    return y;
}

int main() {
    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");

    double x0, x1, step;
    int N;

    if (inputFile.is_open()) {
        inputFile >> x0 >> x1 >> step >> N;
        inputFile.close();
    } else {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }

    if (step <= 0) {
        std::cout << "Step must be positive." << std::endl;
        return 1;
    }

    if (N <= 0) {
        std::cout << "N must be a positive integer." << std::endl;
        return 1;
    }

    for (double x = x0; x <= x1; x += step) {
        double y = calculateFunction(x, N);
        outputFile << x << ", " << y << std::endl;
    }

    outputFile.close();

    std::cout << "Calculation completed. Results saved in out.txt." << std::endl;

    return 0;
}

*/

// задача 4
/*Разработать программу для считывания данных о студентах из файла в следующем
формате: 1 строка Фамилия, 2 строка Средняя оценка, 3 строка Курс. Остальные
строки повторяют тройками эти данные для других студентов. Организовать
считывание данных из файла в массив структур. Организовать переменные для
хранения информации.*/
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string surname;
    float averageGrade;
    int course;
};

int main() {
    std::ifstream inputFile("students.txt"); 

    if (!inputFile) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    std::vector<Student> students;

    std::string line;
    while (std::getline(inputFile, line)) {
        Student student;
        student.surname = line;

        std::getline(inputFile, line);
        student.averageGrade = std::stof(line);

        std::getline(inputFile, line);
        student.course = std::stoi(line);

        students.push_back(student);
    }

    inputFile.close();

    // Вывод данных о студентах
    for (const auto& student : students) {
        std::cout << "Фамилия: " << student.surname << std::endl;
        std::cout << "Средняя оценка: " << student.averageGrade << std::endl;
        std::cout << "Курс: " << student.course << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

*/