#include "complexnum.h"

template <typename T>
Complex<T>::Complex() : real(0.0), imag(0.0) {}

template <typename T>
Complex<T>::Complex(T real, T imag) : real(real), imag(imag) {}

template <typename T>
T Complex<T>::getRealNum() const { return real; }

template <typename T>
T Complex<T>::getImaginaryNum() const { return imag; }

template <typename T>
void Complex<T>::setRealNum(T num) { real = num; }

template <typename T>
void Complex<T>::setImaginaryNum(T num) { imag = num; }

template <typename T>
Complex<T> Complex<T>::operator+(const Complex<T>& other) const {
  return {real + other.real, imag + other.imag};
}

template <typename T>
Complex<T> Complex<T>::operator-(const Complex<T>& other) const {
  return {real - other.real, imag - other.imag};
}

template <typename T>
Complex<T> Complex<T>::operator*(const Complex<T>& other) const {
  return {real * other.real - imag * other.imag,
          real * other.imag + imag * other.real};
}

template <typename T>
Complex<T> Complex<T>::operator*(const T& other) const {
  return {real * other, imag * other};
}

template <typename T>
Complex<T> Complex<T>::operator/(const Complex<T>& other) const {
  T denominator = other.real * other.real + other.imag * other.imag;
  return {(real * other.real + imag * other.imag) / denominator,
          (real * other.imag - imag * other.real) / denominator};
}

template <typename T>
Complex<T> Complex<T>::operator/(const T& other) const {
  return {real / other, imag / other};
}

template <typename T>
bool Complex<T>::operator==(const Complex<T>& other) const {
  return real == other.real && imag == other.imag;
}

template <typename T>
bool Complex<T>::operator==(const T& other) const {
  return this->abs() == other;
}

template <typename T>
bool Complex<T>::operator!=(const Complex<T>& other) const {
  return !(*this == other);
}

template <typename T>
bool Complex<T>::operator!=(const T& other) const {
  return !(*this == other);
}

template <typename T>
void Complex<T>::pow(unsigned int power) {
  double abs = std::pow(this->abs(), power);
  double angle = this->angle() * power;

  real = abs * cos(angle);
  imag = abs * sin(angle);
}

template <typename T>
T Complex<T>::abs() const { return sqrt(real * real + imag * imag); }

template <typename T>
T Complex<T>::angle() const {
  double angle = std::atan2(imag, real);
  if (std::signbit(angle))
    return 2 * M_PI + angle;
  return angle;
}

template <typename T>
std::string Complex<T>::generalForm() const {
  if (std::signbit(imag))
    return to_str(real, 5) + " - " + to_str(fabs(imag), 5) + "i";
  return to_str(real, 5) + " + " + to_str(imag, 5) + "i";
}

template <typename T>
std::string Complex<T>::generalForm(int precision) const {
  if (std::signbit(imag))
    return to_str(real, precision) + " - " + to_str(fabs(imag), precision) + "i";
  return to_str(real, precision) + " + " + to_str(imag, precision) + "i";
}

template<typename T>
std::string Complex<T>::polarForm() const {
    std::string abs = to_str(this->abs(), 5);
    std::string angle = to_str(this->angle() * 180 / M_PI, 5);
    return "(" + abs + ", " + angle + ")";
}

template<typename T>
std::string Complex<T>::polarForm(int precision) const {
    std::string abs = to_str(this->abs(), precision);
    std::string angle = to_str(this->angle() * 180 / M_PI, precision);
    return "(" + abs + ", " + angle + ")";
}

template<typename T>
std::string Complex<T>::to_str(T num, int precision) const {
    std::ostringstream snum;
    snum << std::fixed << std::setprecision(precision) << std::noshowpoint << num;
    return snum.str();
}
