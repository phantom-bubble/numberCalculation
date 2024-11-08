#include <rational.h>

Rational::Rational(const std::string& number) {
	if (number.find('.') == std::string::npos && number.find('^') == std::string::npos) {
		this->numerator = { number };
		return;
	}
	if (number.find('.') != std::string::npos) {
		int number_of_zero = number.size() - number.find('.') - 1;
		for (int i = 0; i < number_of_zero; ++i) {
			this->denominator.num += '0';
		}
		this->numerator.num = "";
		for (auto& it : number) {
			if (it == '.')
				continue;
			this->numerator.num += it;
		}
	}
	simplify();
}

std::string Rational::to_ratio_string() const {
	return numerator.num + "/" + denominator.num;
}

Number gcd(const Number& n1, const Number& n2) {
	Number a = n1;
	Number b = n2;
	while (b.num != "0") {
		Number temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

void Rational::simplify() {
	Number g = gcd(numerator, denominator);
	while(g.num != "1") {
		this->numerator = this->numerator / g;
		this->denominator = this->denominator / g;
		g = gcd(numerator, denominator);
	}
	// Number num{ "2" };
	// while (num <= this->numerator && num <= this->denominator) {
	// 	while ((this->numerator % num).num == "0" && (this->denominator % num).num == "0") {
	// 		this->numerator = this->numerator / num;
	// 		this->denominator = this->denominator / num;
	// 	}
	// 	num = num + Number("1");
	// }
}

Rational Rational::operator+(const Rational& other) const {
	Rational result{ "0" };
	result.numerator = this->numerator * other.denominator + this->denominator * other.numerator;
	result.denominator = this->denominator * other.denominator;
	result.simplify();
	return result;
}

Rational Rational::operator-(const Rational& other) const {
	Rational result{ "0" };
	result.numerator = this->numerator * other.denominator - this->denominator * other.numerator;
	result.denominator = this->denominator * other.denominator;
	result.simplify();
	return result;
}

Rational Rational::operator*(const Rational& other) const {
	Rational result{ "0"};
	result.numerator = this->numerator * other.numerator;
	result.denominator = this->denominator * other.denominator;
	result.simplify();
	return result;
}

Rational Rational::operator/(const Rational& other) const {
	Rational result{ "0" };
	result.numerator = this->numerator * other.denominator;
	result.denominator = this->denominator * other.numerator;
	result.simplify();
	return result;
}
