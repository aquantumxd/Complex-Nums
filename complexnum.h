#ifndef COMPLEX_NUMS_COMPLEXNUM_H
#define COMPLEX_NUMS_COMPLEXNUM_H

#include <string>

class Complex {
private:
    double real;
    double imag;

    static std::string to_str (double num, int precision);

public:
    Complex();;
    Complex(double real, double img);
    Complex(double real, int    img);
    Complex(int    real, double img);
    Complex(int    real, int    img);

    [[nodiscard]] double getRealNum() const;
    [[nodiscard]] double getImaginaryNum() const;

    void setRealNum(double num);
    void setRealNum(int num);

    void setImaginaryNum(double num);
    void setImaginaryNum(int num);

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator*(const double& other) const;
    Complex operator*(const int& other) const;
    Complex operator/(const Complex& other) const;
    Complex operator/(const double& other) const;
    Complex operator/(const int& other) const;

    bool operator==(const Complex& other) const;
    bool operator==(const double& other) const;
    bool operator==(const int& other) const;

    bool operator!=(const Complex& other) const;
    bool operator!=(const double& other) const;
    bool operator!=(const int& other) const;

    void pow(unsigned int power);

    [[nodiscard]] double abs() const;
    [[nodiscard]] double angle() const;

    [[nodiscard]] std::string generalForm() const;
    [[nodiscard]] std::string generalForm(int precision) const;

    [[nodiscard]] std::string polarForm() const;
    [[nodiscard]] std::string polarForm(int precision) const;
};

#endif //COMPLEX_NUMS_COMPLEXNUM_H
