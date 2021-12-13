#include "InputCheck.h"

int getIntValue(int lowLimit, int upLimit)
{
    while (true) {
        int a;
        std::cin >> a;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Неверный ввод. Пожалуйста попробуйте снова...\n";
        }
        else if (a < lowLimit || a > upLimit) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Ведённый номер отсутствует в списке. Пожалуйста попробуйте снова..." << endl;
        }
        else {
            std::cin.ignore(32767, '\n'); // удаление лишних символов
            return a;
        }
    }
}

int getIntValue(int lowLimit, int upLimit, int mySeconds)
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

    while (true) {
        int a;

        std::cin >> a;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Неверный ввод. Пожалуйста,попробуйте снова...\n";
        }
        else if (a < lowLimit || a > upLimit) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Ведённый номер отсутствует в списке. Пожалуйста попробуйте снова..." << endl;
        }
        else {
            std::cin.ignore(32767, '\n'); // удаление лишних символов
            if (std::chrono::steady_clock::now() - start > std::chrono::seconds(mySeconds)) {
                cout << endl << "Слишком поздно!" << endl;
                return INT_MIN;
            }
            else
                return a;
        }

    }
}

string getStringValue()
{
    string line;
    while (true) {
        getline(cin, line);
        if (std::cin.fail()) {              //если предыдущий не удалось найти
            std::cin.clear();               //затем мы возвращаем cin в "нормальный" режим работы
            std::cin.ignore(32767, '\n');   //и удалите значения предыдущего ввода из входного буфера
            std::cout << "Неверный ввод. Пожалуйста попробуйте снова...\n";
        }
        else if (isInvalidInput(line))      //Нелатинский символ или не введенное число
            cout << "Введите только латинские буквы или цифры...\n";
        else {
            return line;
        }
    }
}

bool isInvalidInput(string line) {
    for (const auto& ch : line)
        if (((int)ch < 0) || ((int)ch < 97 && (int)ch > 122) || ((int)ch < 65 && (int)ch > 90) || ((int)ch < 48 && (int)ch > 57)) {
            return true;
        }
    return false;
}

double getDoubleValue(double lowLimit, double upLimit) {
    while (true) {
        double a;
        std::cin >> a;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Неверный ввод.  Пожалуйста попробуйте снова...\n";
        }
        else if (a < lowLimit || a > upLimit) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Введенный номер отсутствует в списке. Пожалуйста попробуйте снова" << endl;
        }
        else {
            std::cin.ignore(32767, '\n'); // удаление лишних символов
            return a;
        }
    }
}
