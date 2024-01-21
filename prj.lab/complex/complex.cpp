#include<complex/complex.hpp>

//Complex::Complex(const Complex& rhs) : real(rhs.real), imaginary(rhs.imaginary) {}
Complex::Complex(const double re, const double img): real(re), imaginary(img) {}
Complex::Complex(const double re): real(re) {}


Complex& Complex::operator-() noexcept{
	real = -real;
	imaginary = -imaginary;
	return *this;
}

Complex& Complex::operator=(const Complex& rhs) noexcept {
	if (this != &rhs) {
		real = rhs.real;
		imaginary = rhs.imaginary;
	}
	return *this;
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
	real += rhs.real;
	imaginary += rhs.imaginary;
	return *this;
}
Complex& Complex::operator+=(const double rhs) noexcept {
	Complex a(rhs);
	return (*this+= a);
}
Complex& Complex::operator-=(const Complex& rhs) noexcept {
	real -= rhs.real;
	imaginary -= rhs.imaginary;
	return *this;
}
Complex& Complex::operator-=(const double rhs) noexcept {
	Complex a(rhs);
	return (*this -= a);
}
Complex& Complex::operator*=(const Complex& rhs) noexcept {
	double re = real;
	double img = imaginary;
	real = (re * rhs.real) - (img * rhs.imaginary);
	imaginary = (re * rhs.imaginary) + (img * rhs.real);
	return *this;
}
Complex& Complex::operator*=(const double rhs) noexcept {
	Complex a(rhs);
	return (*this *= a);
}
Complex& Complex::operator/=(const Complex& rhs) {
	double del = rhs.real * rhs.real + rhs.imaginary * rhs.imaginary;
	if (del == 0) {
		throw std::exception();

	}
	Complex tmp1(real, imaginary);
	Complex tmp2(rhs.real, -rhs.imaginary);
	tmp1 *= tmp2;
	real = tmp1.real / del;
	imaginary = tmp1.imaginary / del;
	return *this;
}
Complex& Complex::operator/=(const double rhs) {
	Complex a(rhs);
	return (*this /= a);
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
	Complex res(lhs.real + rhs.real, lhs.imaginary + rhs.imaginary);
	return res;
}
Complex operator+(const Complex& lhs, const double rhs) noexcept {
	Complex a(rhs);
	Complex res(lhs.real + a.real, lhs.imaginary + a.imaginary);
	return res;
}
Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
	Complex res(lhs.real - rhs.real, lhs.imaginary - rhs.imaginary);
	return res;
}
Complex operator-(const Complex& lhs, const double rhs) noexcept {
	Complex a(rhs);
	Complex res(lhs.real - a.real, lhs.imaginary - a.imaginary);
	return res;
}
Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
	Complex res(lhs);
	res *= rhs;
	return res;
}
Complex operator*(const Complex& lhs, const double rhs) noexcept {
	Complex res(lhs);
	res *= rhs;
	return res;
}
Complex operator/(const Complex& lhs, const Complex& rhs) {
	Complex res(lhs);
	res /= rhs;
	return res;
}
Complex operator/(const Complex& lhs, const double rhs) {
	Complex res(lhs);
	res /= rhs;
	return res;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
	char leftBrace(0);
	double re(0.0);
	char comma(0);
	double im(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> re >> comma >> im >> rightBrace;
	if (not(istrm.fail()))
	{
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace))
		{
			real = re;
			imaginary = im;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
	ostrm << leftBrace << real << separator << imaginary << rightBrace;
	return ostrm;
}