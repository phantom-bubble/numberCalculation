#pragma once
#include <number.h>

class Rational {
public:
	Rational(const std::string& number);
	Rational operator+(const Rational& other) const;
	Rational operator-(const Rational& other) const;
	Rational operator*(const Rational& other) const;
	Rational operator/(const Rational& other) const;
	void simplify();
public:
	Number numerator{ "0" };
	Number denominator{ "1" };
};