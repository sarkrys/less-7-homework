#include <iostream>
#include <string>
#include <stdexcept>

class figure {
protected:
    int a, b, c, d, A, B, C, D;

public:
    figure(int side1, int side2, int side3, int side4, int angle1, int angle2, int angle3, int angle4)
        : a(side1), b(side2), c(side3), d(side4), A(angle1), B(angle2), C(angle3), D(angle4) {
        if (a <= 0 || b <= 0 || c <= 0 || d < 0 || A <= 0 || B <= 0 || C <= 0 || D < 0) {
            throw std::invalid_argument("Некорректные параметры для создания фигуры.\n");
        }
    }

    virtual bool checkValidity() {
        return false;
    }

    virtual int getSideCount() {
        return 0;
    }

    virtual std::string getFigureType() {
        return "Фигура";
    }

    void printFigureInfo() {
        std::cout << getFigureType() << " (стороны " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << ", " << B << ", " << C << ", " << D << ") создан\n" << std::endl;
        if (!checkValidity()) {
            std::cerr << "Ошибка создания фигуры. Фигура некорректна.\n" << std::endl;
        }
    }

    virtual ~figure() {}
};

class triangle : public figure {
public:
    triangle(int side1, int side2, int side3, int angle1, int angle2, int angle3)
        : figure(side1, side2, side3, 0, angle1, angle2, angle3, 0) {}

    bool checkValidity() override {
        return (a + b > c && a + c > b && b + c > a && A + B + C == 180 && getSideCount() == 3);
    }

    int getSideCount() override {
        return 3;
    }

    std::string getFigureType() override {
        return "Треугольник";
    }
};
class righttriangle : public triangle {
public:
    righttriangle(int side1, int side2, int angle1, int angle2)
        : triangle(side1, side2, 0, angle1, angle2, 90) {}

    bool checkValidity() override {
        return (A == 90 && B == 90 && C == 90);
    }

    int getSideCount() override {
        return 3;
    }

    std::string getFigureType() override {
        return " прямоугольный Треугольник";
    }
};
class equilateraltriangle : public triangle {
public:
    equilateraltriangle(int side)
        : triangle(side, side, side, 60, 60, 60) {}

    bool checkValidity() override {
        return (a == b && b == c);
    }

    int getSideCount() override {
        return 3;
    }

    std::string getFigureType() override {
        return " равносторонний Треугольник";
    }
};
class ravnobedtriangle : public triangle {
public:
    ravnobedtriangle(int side1, int side2, int side3, int angle1, int angle2, int angle3)
        : triangle(side1, side2, side3, angle1, angle2, angle3) {}

    bool checkValidity() override {
        return (a == c && A == C && getSideCount() == 3);
    }

    int getSideCount() override {
        return 3;
    }

    std::string getFigureType() override {
        return " равнобедренный Треугольник";
    }
};
class rectangle : public figure {
public:
    rectangle(int side1, int side2) : figure(side1, side2, side1, side2, 90, 90, 90, 90) {}

    bool checkValidity() override {
        return (a == c && b == d) && (A == B && B == C && C == D && A == 90);
    }

    int getSideCount() override {
        return 4;
    }

    std::string getFigureType() override {
        return " прямоугольник";
    }
};
class square : public rectangle {
public:
    square(int side) : rectangle(side, side) {}
    bool checkValidity() override {
        return (a == b && b == c && c == d && A == B && B == C && C == D && A == 90);
    }

    int getSideCount() override {
        return 4;
    }

    std::string getFigureType() override {
        return " квадрат";
    }
};
class parallerogram : public figure {
public:
    parallerogram(int side1, int side2, int angle)
        : figure(side1, side2, side1, side2, angle, 180 - angle, angle, 180 - angle) {}
    bool checkValidity() override {
        return(a == c && b == d) && (A == B && B == C && C == D);
    }

    int getSideCount() override {
        return 4;
    }

    std::string getFigureType() override {
        return " паралерограмм";
    }
};
class rombus : public square {
public:
    rombus(int side) : square(side) {}
    bool checkValidity() override {
        return(a == b && b == c && c == d) && (A == C && B == D && A == 60);
    }

    int getSideCount() override {
        return 4;
    }

    std::string getFigureType() override {
        return " паралерограмм";
    }
};
int main() {
    setlocale(LC_ALL, "ru");

    try {
        figure* f1 = new triangle(1, 2, 5, 60, 60, 60);
        f1->printFigureInfo();
        delete f1;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        figure* f2 = new righttriangle(2, 3, 70, 50);
        f2->printFigureInfo();
        delete f2;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        figure* f3 = new equilateraltriangle(3);
        f3->printFigureInfo();
        delete f3;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        figure* f4 = new ravnobedtriangle(3, 1, 4, 30, 40, 70);
        f4->printFigureInfo();
        delete f4;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        figure* f5 = new rectangle(3, 1);
        f5->printFigureInfo();
        delete f5;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        figure* f6 = new square(1);
        f6->printFigureInfo();
        delete f6;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        figure* f7 = new parallerogram(3, 1, 80);
        f7->printFigureInfo();
        delete f7;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    try {
        figure* f8 = new rombus(3);
        f8->printFigureInfo();
        delete f8;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}
