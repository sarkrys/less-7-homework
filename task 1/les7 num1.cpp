#include <iostream>
#include <string>
#include <cctype>

int chekw(std::string word) {
    int letterCount = 0;
    for (char c : word) {
            letterCount++;
    }
    return letterCount;
}
int func(int errnum, int lettercount) {
    for (; lettercount != errnum;) {
        lettercount = 0;
        std::string word;
        std::cout << "Введите слово: ";
        std::cin >> word;
        lettercount = chekw(word);
        if (lettercount != errnum) {
            std::cout << "Количество букв в слове: " << lettercount << std::endl;
        }
        else {
            throw "Вы ввели слово запретной длины! До свидания";
            return 1;
        }
    }
    return 0;
}
int main() {
    setlocale(LC_ALL, "ru");
    std::cout << "Введите запретное число: ";
    int errnum = 0;
    std::cin >> errnum;
    int lettercount = 0;
    try {
        func(errnum, lettercount);
    }
    catch (const char* msg) {
            std::cout << msg << std::endl;
    }
    catch (...) {
        std::cout << "неизвестная ошибка\n";
    }
   
    return 0;
}
