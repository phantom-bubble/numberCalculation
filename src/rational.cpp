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

void Rational::simplify() {
	Number num{ "2" };
	while (num < this->numerator && num < this->denominator) {
		while ((this->numerator % num).num == "0" && (this->denominator % num).num == "0") {
			this->numerator = this->numerator / num;
			this->denominator = this->denominator / num;
		}
		num = num + Number("1");
	}
}

Rational Rational::operator*(const Rational& other) const {
	Rational result{ "0"};
	result.numerator = this->numerator * other.numerator;
	result.denominator = this->denominator * other.denominator;
	result.simplify();
	return result;
}