#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>


class Rational {
public:
	explicit Rational() = default;
	explicit Rational(const std::int64_t ch, const std::int64_t zn);
	explicit Rational(const std::int64_t ch);
	~Rational() = default;
	Rational& operator=(const Rational& rhs);

	static const char separator = '/';
	std::int64_t c() const noexcept { return ch; }
	std::int64_t z() const noexcept { return zn; }

	bool operator==(const Rational& rhs) const noexcept;
	bool operator!=(const Rational& rhs) const noexcept;

	bool operator>(const Rational& rhs) const noexcept { return ch*rhs.zn > rhs.ch*zn; }
	bool operator>=(const Rational& rhs) const noexcept { return ch * rhs.zn >= rhs.ch * zn; }
	bool operator<(const Rational& rhs) const noexcept { return ch * rhs.zn < rhs.ch * zn; }
	bool operator<=(const Rational& rhs) const noexcept { return ch * rhs.zn <= rhs.ch * zn; }

	Rational& operator+=(const Rational& rhs) noexcept;
	Rational& operator-=(const Rational& rhs) noexcept;
	Rational& operator*=(const Rational& rhs) noexcept;
	Rational& operator/=(const Rational& rhs);
	Rational& operator+=(const int& rhs) noexcept;
	Rational& operator-=(const int& rhs) noexcept;
	Rational& operator*=(const int& rhs) noexcept;
	Rational& operator/=(const int& rhs);
	
	std::ostream& writeTo(std::ostream& ostrm) const noexcept;
	std::istream& readFrom(std::istream& istrm) noexcept;

	Rational& fix();

private:
	std::int64_t ch = 0;
	std::int64_t zn = 1;
};

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;

Rational operator*(const Rational& lhs, const int& rhs) noexcept;
Rational operator/(const Rational& lhs, const int& rhs);
Rational operator+(const Rational& lhs, const int& rhs) noexcept;
Rational operator-(const Rational& lhs, const int& rhs) noexcept;

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
	return rhs.readFrom(istrm);
}

#endif //!RATIONAL_HPP