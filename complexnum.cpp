#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "complexnum.h"


Complex::Complex() :                        real(0.0), imag(0.0) {}
Complex::Complex(double real, double img) : real(real), imag(img) {}
Complex::Complex(double real, int img) :    real(real), imag((double) img) {}
Complex::Complex(int real, double img) :    real((double) real), imag(img) {}
Complex::Complex(int real, int img) :       real((double) real), imag((double) img) {}

double Complex::getRealNum() const { return real; }
double Complex::getImaginaryNum() const { return imag; }

void Complex::setRealNum(double num)        { real = num; }
void Complex::setRealNum(int num)           { real = (double) num; }
void Complex::setImaginaryNum(double num)   { imag = num; }
void Complex::setImaginaryNum(int num)      { imag = (double) num; }

Complex Complex::operator+(const Complex &other) const {
    return {real + other.real, imag + other.imag};
}

Complex Complex::operator-(const Complex &other) const {
    return {real - other.real, imag - other.imag};
}

Complex Complex::operator*(const Complex &other) const {
    return {real * other.real - imag * other.imag,
            real * other.imag + imag * other.real};
}

Complex Complex::operator*(const double &other) const {
    return {real * other, imag * other};
}

Complex Complex::operator*(const int &other) const {
    return {real * other, imag * other};
}

Complex Complex::operator/(const Complex &other) const {
    double denominator = other.real * other.real + other.imag * other.imag;
    return {(real * other.real + imag * other.imag) / denominator,
            (real * other.imag - imag * other.real) / denominator};
}

Complex Complex::operator/(const double &other) const {
    return {real / (double) other, imag / (double) other};
}

Complex Complex::operator/(const int &other) const {
    return {real / (double) other, imag / (double) other};
}

bool Complex::operator==(const Complex &other) const {
    return real == other.real && imag == other.imag;
}

bool Complex::operator==(const double &other) const {
    return this->abs() == other;
}

bool Complex::operator==(const int &other) const {
    return this->abs() == other;
}

bool Complex::operator!=(const Complex &other) const {
    return !(*this == other);
}

bool Complex::operator!=(const double &other) const {
    return !(*this == other);
}

bool Complex::operator!=(const int &other) const {
    return !(*this == other);
}


void Complex::pow(unsigned int power) {
    double abs = std::pow(this->abs(), power);
    double angle = this->angle() * power;

    real = abs * cos(angle);
    imag = abs * sin(angle);
}

double Complex::abs() const { return sqrt(real * real + imag * imag); }

double Complex::angle() const {
    double angle = std::atan2(imag, real);
    if (std::signbit(angle))
        return 2 * M_PI + angle;
    return angle;
}

std::string Complex::generalForm() const {
    if (std::signbit(imag))
        return to_str(real, 5) + " - " + to_str(fabs(imag), 5) + "i";
    return to_str(real, 5) + " + " + to_str(imag, 5) + "i";
}

std::string Complex::generalForm(int precision) const {
    if (std::signbit(imag))
        return to_str(real, precision) + " - " + to_str(fabs(imag), precision) + "i";
    return to_str(real, precision) + " + " + to_str(imag, precision) + "i";
}

std::string Complex::polarForm() const {
    std::string abs = to_str(this->abs(), 5);
    std::string angle = to_str(this->angle() * 180 / M_PI, 5);
    return "(" + abs + ", " + angle + ")";
}

std::string Complex::polarForm(int precision) const {
    std::string abs = to_str(this->abs(), precision);
    std::string angle = to_str(this->angle() * 180 / M_PI, precision);
    return "(" + abs + ", " + angle + ")";
}

std::string Complex::to_str(double num, int precision) {
    std::ostringstream snum;
    snum << std::fixed << std::setprecision(precision) << std::noshowpoint << num;
    return snum.str();
}
