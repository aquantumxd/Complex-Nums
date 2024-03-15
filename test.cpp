#include <cassert>
#include <cmath>
#include <iostream>
#include "complexnum.h"

bool compare(double x, double y, double epsilon = 0.00001) {
    return std::fabs(x - y) < epsilon;
}

void getRealPart() {
    Complex<float> c(1.1f, -2.2f);
    assert(c.getRealNum() == 1.1f);
    std::cout << "Test getRealPart is OK\n";
}

void getImaginaryPart() {
    Complex<float> c(1.1f, -2.2f);
    assert(c.getImaginaryNum() == -2.2f);
    std::cout << "Test getImaginaryPart is OK\n";
}

void setRealPart() {
    Complex<float> c(1.1f, -2.2f);

    c.setRealNum(1);
    assert(c.getRealNum() == 1.0f);

    c.setRealNum(2.2f);
    assert(c.getRealNum() == 2.2f);

    std::cout << "Test setRealPart is OK\n";

}

void setImaginaryPart() {
    Complex<float> c(1.1f, -2.2f);

    c.setImaginaryNum(1);
    assert(c.getImaginaryNum() == 1.0f);

    c.setImaginaryNum(3.3f);
    assert(c.getImaginaryNum() == 3.3f);

    std::cout << "Test setImaginaryPart is OK\n";
}

void sumOperator() {
    Complex<float> c1(1.1f, -2.2f);
    Complex<float> c2(2.2f, -1.1f);

    c1 = c1 + c2;
    assert(compare(c1.getRealNum(), 3.3f) && compare(c1.getImaginaryNum(), -3.3f));

    std::cout << "Test sumOperator is OK\n";
}

void subtractionOperator() {
    Complex<float> c1(1.1f, -2.2f);
    Complex<float> c2(2.2f, -1.1f);

    c1 = c1 - c2;
    assert(compare(c1.getRealNum(), -1.1f) && compare(c1.getImaginaryNum(), -1.1f));

    std::cout << "Test sumOperator is OK\n";
}

void multiplyOperator() {
    Complex<float> c1(2, 3);
    Complex<float> c2(4, 5);

    c1 = c1 * c2;
    assert(compare(c1.getRealNum(), -7.0f) && compare(c1.getImaginaryNum(), 22.0f));

    c2 = c2 * 2;
    assert(compare(c2.getRealNum(), 8.0f) && compare(c2.getImaginaryNum(), 10.0f));

    std::cout << "Test multiplyOperator is OK\n";
}

void divisionOperator() {
    Complex<float> c1(3, -1);
    Complex<float> c2(-5, 2);

    c1 = c1 / c2;
    assert(compare(c1.getRealNum(), (-17.0f / 29.0f)) && compare(c1.getImaginaryNum(), (1.0f / 29.0f)));

    c2 = c2 / 5.0f;
    assert(compare(c2.getRealNum(), -1.0f) && compare(c2.getImaginaryNum(), 0.4f));

    std::cout << "Test divisionOperator is OK\n";
}

void equalityOperators() {
    Complex<float> c1(3, -1);
    Complex<float> c2(3, -1);
    Complex<float> c3(14.8f, 8.228f);

    assert(c1 == c2);
    assert(c1 != c3);

    std::cout << "Test equalityOperators is OK\n";
}

void powMethod() {
    Complex<float> c(1, 1);

    c.pow(8);
    assert(compare(c.getRealNum(), 16.0f) && compare(c.getImaginaryNum(), 0.0f));

    std::cout << "Test powMethod is OK\n";
}

void absMethod() {
    Complex<float> c(3, 4);
    assert(c.abs() == 5.0f);
    std::cout << "Test absMethod is OK\n";
}

void angleMethod() {
    Complex<float> c(25, 25);
    assert(compare(c.angle(), M_PI / 4));
    std::cout << "Test angleMethod is OK\n";
}

void generalFormMethod() {
    Complex<float> c(3.14159f, -2.71828f);

    assert(c.generalForm() == "3.14159 - 2.71828i");
    assert(c.generalForm(2) == "3.14 - 2.72i");

    std::cout << "Test generalForm is OK\n";
}

void polarFormMethod() {
    Complex<float> c(4, -4);

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
