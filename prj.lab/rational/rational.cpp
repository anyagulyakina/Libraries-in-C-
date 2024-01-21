#include<rational/rational.hpp>


Rational::Rational(const std::int64_t num, const std::int64_t den)
	: ch(num), zn(den) {
	if (0 == zn) {
		throw std::invalid_argument("Zero denumenator in Rational ctor");
	}
	//fix();
}
Rational::Rational(const std::int64_t num)
	: ch(num), zn(1) {
	//fix();
}

Rational& Rational::operator=(const Rational& rhs) {
	ch = rhs.ch;
	zn = rhs.zn;
	fix();
	return *this;
}

bool Rational::operator==(const Rational& rhs) const noexcept {
	Rational r1 = *this;
	Rational r2 = rhs;
	r1.fix();
	r2.fix();
	return r1.ch == r2.ch && r1.zn == r2.zn;
}
bool Rational::operator!=(const Rational& rhs) const noexcept {
	Rational r1 = *this;
	Rational r2 = rhs;
	r1.fix();
	r2.fix();
	return r1.ch != r2.ch || r1.zn != r2.zn;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
	ch *= rhs.ch;
	zn *= rhs.zn;
	fix();
	return *this;
}
Rational& Rational::operator*=(const int& rhs) noexcept {
	Rational a(rhs);
	ch *= a.ch;
	zn *= a.zn;
	fix();
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
	ch *= rhs.zn;
	zn *= rhs.ch;
	fix();
	return *this;
}
Rational& Rational::operator/=(const int& rhs) {
	Rational a(rhs);
	ch *= a.zn;
	zn *= a.ch;
	fix();
	return *this;
}
Rational& Rational::operator+=(const Rational& rhs) noexcept {
	ch = ch * rhs.zn + rhs.ch * zn;
	zn *= rhs.zn;
	fix();
	return *this;
}
Rational& Rational::operator+=(const int& rhs) noexcept {
	Rational a(rhs);
	ch = ch * a.zn + a.ch * zn;
	zn *= a.zn;
	fix();
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs) noexcept {
	ch = ch * rhs.zn - rhs.ch * zn;
	zn *= rhs.zn;
	fix();
	return *this;
}
Rational& Rational::operator-=(const int& rhs) noexcept {
	Rational a(rhs);
	ch = ch * a.zn - a.ch * zn;
	zn *= a.zn;
	fix();
	return *this;
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
	Rational res(lhs);
	res *= rhs;
	return res.fix();
}
Rational operator*(const Rational& lhs, const int& rhs) noexcept {
	Rational res(lhs);
	res *= rhs;
	return res.fix();
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational res(lhs);
	res /= rhs;
	return res.fix();
}
Rational operator/(const Rational& lhs, const int& rhs) {
	Rational res(lhs);
	res /= rhs;
	return res.fix();
}
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
	Rational res(lhs);
	res += rhs;
	return res.fix();
}
Rational operator+(const Rational& lhs, const int& rhs) noexcept {
	Rational res(lhs);
	res += rhs;
	return res.fix();
}
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
	Rational res(lhs);
	res -= rhs;
	return res.fix();
}
Rational operator-(const Rational& lhs, const int& rhs) noexcept {
	Rational res(lhs);
	res -= rhs;
	return res.fix();
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const noexcept {
	ostrm << ch << separator << zn;
	return ostrm;
}
std::istream& Rational::readFrom(std::istream& istrm) noexcept {
	
	std::int64_t c(0);
	char separator(0);
	std::int64_t z(1);
	istrm >> c >> separator >> z;
	if (not(istrm.fail())) {
		if (Rational::separator == separator && z>0) {
			ch = c;
			zn = z;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

Rational& Rational::fix() {
	int less = 0;
	int j = 0;
	if (abs(ch) < abs(zn)) {
		less = abs(ch);
	}
	else {
		less = abs(zn);
	}
	for (int j = less; j > 1; j--) {
		//std::cout << j << std::endl;
		if ((ch % j) == 0 && (zn % j) == 0) {
			ch /= j;
			zn /= j;
		}
	}
	return *this;
}