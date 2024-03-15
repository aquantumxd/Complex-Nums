#ifndef COMPLEXNUM_H
#define COMPLEXNUM_H

#include <cmath>
#include <sstream>
#include <iomanip>
#include <string>

template <typename T>
class Complex {
public:
  // Constructors
  Complex();
  Complex(T real, T imag);

  // Getters
  T getRealNum() const;
  T getImaginaryNum() const;

  // Setters (using T for consistency)
  void setRealNum(T num);
  void setImaginaryNum(T num);

  // Arithmetic operators
  Complex<T> operator+(const Complex<T>& other) const;
  Complex<T> operator-(const Complex<T>& other) const;
  Complex<T> operator*(const Complex<T>& other) const;
  Complex<T> operator*(const T& other) const;
  Complex<T> operator/(const Complex<T>& other) const;
  Complex<T> operator/(const T& other) const;

  // Comparison operators
  bool operator==(const Complex<T>& other) const;
  bool operator==(const T& other) const;
  bool operator!=(const Complex<T>& other) const;
  bool operator!=(const T& other) const;

  // Complex number specific functions
  void pow(unsigned int power);
  T abs() const;
  T angle() const;

  // Formatting functions
  std::string generalForm() const;
  std::string generalForm(int precision) const;
  std::string polarForm() const;
  std::string polarForm(int precision) const;

private:
  T real;
  T imag;

  // Helper function for string formatting
  std::string to_str(T num, int precision) const;
};

#include "complexnum.cpp"
#endif // COMPLEXNUM_H
