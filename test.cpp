#include <cassert>
#include <cmath>
#include <iostream>
#include "complexnum.h"

bool compare_double(double x, double y, double epsilon = 0.00001) {
    return std::fabs(x - y) < epsilon;
}

void getRealPart() {
    Complex c(1.1, -2.2);
    assert(c.getRealNum() == 1.1);
    std::cout << "Test getRealPart is OK\n";
}

void getImaginaryPart() {
    Complex c(1.1, -2.2);
    assert(c.getImaginaryNum() == -2.2);
    std::cout << "Test getImaginaryPart is OK\n";
}

void setRealPart() {
    Complex c(1.1, -2.2);

    c.setRealNum(1);
    assert(c.getRealNum() == 1.0);

    c.setRealNum(2.2);
    assert(c.getRealNum() == 2.2);

    std::cout << "Test setRealPart is OK\n";

}

void setImaginaryPart() {
    Complex c(1.1, -2.2);

    c.setImaginaryNum(1);
    assert(c.getImaginaryNum() == 1.0);

    c.setImaginaryNum(3.3);
    assert(c.getImaginaryNum() == 3.3);

    std::cout << "Test setImaginaryPart is OK\n";
}

void sumOperator() {
    Complex c1(1.1, -2.2);
    Complex c2(2.2, -1.1);

    c1 = c1 + c2;
    assert(compare_double(c1.getRealNum(), 3.3) && compare_double(c1.getImaginaryNum(), -3.3));

    std::cout << "Test sumOperator is OK\n";
}

void subtractionOperator() {
    Complex c1(1.1, -2.2);
    Complex c2(2.2, -1.1);

    c1 = c1 - c2;
    assert(compare_double(c1.getRealNum(), -1.1) && compare_double(c1.getImaginaryNum(), -1.1));

    std::cout << "Test sumOperator is OK\n";
}

void multiplyOperator() {
    Complex c1(2, 3);
    Complex c2(4, 5);

    c1 = c1 * c2;
    assert(compare_double(c1.getRealNum(), -7) && compare_double(c1.getImaginaryNum(), 22));

    c2 = c2 * 2;
    assert(compare_double(c2.getRealNum(), 8) && compare_double(c2.getImaginaryNum(), 10));

    std::cout << "Test multiplyOperator is OK\n";
}

void divisionOperator() {
    Complex c1(3, -1);
    Complex c2(-5, 2);

    c1 = c1 / c2;
    assert(compare_double(c1.getRealNum(), (-17.0 / 29.0)) && compare_double(c1.getImaginaryNum(), (1.0 / 29.0)));

    c2 = c2 / 5.0;
    assert(compare_double(c2.getRealNum(), -1.0) && compare_double(c2.getImaginaryNum(), 0.4));

    std::cout << "Test divisionOperator is OK\n";
}

void equalityOperators() {
    Complex c1(3, -1);
    Complex c2(3, -1);
    Complex c3(14.8, 8.228);

    assert(c1 == c2);
    assert(c1 != c3);

    std::cout << "Test equalityOperators is OK\n";
}

void powMethod() {
    Complex c(1, 1);

    c.pow(8);
    assert(compare_double(c.getRealNum(), 16.0) && compare_double(c.getImaginaryNum(), 0.0));

    std::cout << "Test powMethod is OK\n";
}

void absMethod() {
    Complex c(3, 4);
    assert(c.abs() == 5.0);
    std::cout << "Test absMethod is OK\n";
}

void angleMethod() {
    Complex c(25, 25);
    assert(c.angle() == M_PI / 4);
    std::cout << "Test angleMethod is OK\n";
}

void generalFormMethod() {
    Complex c(3.14159, -2.71828);

    assert(c.generalForm() == "3.14159 - 2.71828i");
    assert(c.generalForm(2) == "3.14 - 2.72i");

    std::cout << "Test generalForm is OK\n";
}

void polarFormMethod() {
    Complex c(4, -4);

    assert(c.polarForm() == "(5.65685, 315.00000)");
    assert(c.polarForm(2) == "(5.66, 315.00)");
    std::cout << "Test polarFormMethod is OK\n";
}


int main() {

    getRealPart();
    getImaginaryPart();
    setRealPart();
    setImaginaryPart();
    sumOperator();
    subtractionOperator();
    multiplyOperator();
    divisionOperator();
    equalityOperators();
    powMethod();
    absMethod();
    angleMethod();
    generalFormMethod();
    polarFormMethod();

    std::cout << "\nTest passed successfully!\n";

    return 0;
}