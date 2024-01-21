#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

struct Complex {

	double real{ 0 };
	double imaginary{ 0.0 };
	double eps = 2 * std::numeric_limits<double>::epsilon();

	explicit Complex() = default;
	explicit Complex(const double re, const double img);
	explicit Complex(const double re);
	Complex(const Complex& rhs) = default;
	~Complex() = default;

	static const char leftBrace = '{';
	static const char separator = ',';
	static const char rightBrace = '}';

	Complex& operator=(const Complex& rhs) noexcept;

	Complex& operator-() noexcept;

	bool operator==(const Complex rhs) const noexcept { return abs(real - rhs.real) <= eps && abs(imaginary - rhs.imaginary) <= eps; }
	bool operator!=(const Complex rhs) const noexcept { return not(*this == rhs); }

	Complex& operator+=(const Complex& rhs) noexcept;
	Complex& operator+=(const double rhs) noexcept;
	Complex& operator-=(const Complex& rhs) noexcept;
	Complex& operator-=(const double rhs) noexcept;
	Complex& operator*=(const Complex& rhs) noexcept;
	Complex& operator*=(const double rhs) noexcept;
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs);

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);
};

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;
Complex operator/(const Complex& lhs, const Complex& rhs);


inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs){
	return rhs.writeTo(ostrm);
}
inline std::istream & operator>>(std::istream & istrm, Complex & rhs){
	return rhs.readFrom(istrm);
}

#endif //!COMPLEX_HPP

