#include "number.h"
#include <iostream>
#include <string>
#include <algorithm>

//大数类
Number::Number(const std::string& numstr) {
	num = numstr;
}

bool IsNumberNegative(const Number& num) {
	if (num.num[0] == '-') {
		return true;
	}
	else {
		return false;
	}
}

Number Number::operator+(const Number& other) const {
	if (IsNumberNegative(num) && !IsNumberNegative(other)) {
		std::string tmpnum = num;
		tmpnum.erase(0, 1);
		return Number(other - Number(tmpnum)).num;
	}
	if (!IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum = other.num;
		tmpnum.erase(0, 1);
		return Number(Number(num) - tmpnum);
	}
	if (IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum1 = num;
		std::string tmpnum2 = other.num;
		tmpnum1.erase(0, 1);
		tmpnum2.erase(0, 1);
		return Number('-' + (Number(tmpnum1) + Number(tmpnum2)).num);
	}
	if (num.size() > 1 && num[0] == '0') {
		std::string tmpnum1 = num;
		tmpnum1.erase(0, 1);
		return Number(tmpnum1) + other;
	}
	if (other.num.size() > 1 && other.num[0] == '0') {
		std::string tmpnum2 = other.num;
		tmpnum2.erase(0, 1);
		return *this + Number(tmpnum2);
	}

	std::string tmpstr = "";
	int Ncount = 0;
	int index = 0;
	for (index = 0; index < std::max(num.size(), other.num.size()); index++) {
		char tmpnum = '0';
		char tmpother = '0';
		char tmpaddtion = '0';
		if (int(num.size()) - 1 - index >= 0) {
			tmpnum = num[num.size() - 1 - index];
		}
		if (int(other.num.size()) - 1 - index >= 0) {
			tmpother = other.num[other.num.size() - 1 - index];
		}
		if (char(tmpnum + tmpother - '0') > '9') {
			tmpaddtion = tmpnum + tmpother - '0' - 10 + Ncount;
			Ncount = 1;
		}
		else {
			if (char(tmpnum + tmpother - '0' + Ncount) > '9') {
				tmpaddtion = tmpnum + tmpother - '0' + Ncount - 10;
				Ncount = 1;//连续进位
			}
			else {
				tmpaddtion = tmpnum + tmpother - '0' + Ncount;
				Ncount = 0;
			}
		}
		tmpstr = tmpaddtion + tmpstr;
	}
	if (Ncount != 0) {
		tmpstr = char('0' + Ncount) + tmpstr;
	}
	return Number(tmpstr);
}

Number Number::operator-(const Number& other) const {
	if (IsNumberNegative(num) && !IsNumberNegative(other)) {
		std::string tmpnum = num;
		tmpnum.erase(0, 1);
		return Number('-' + (Number(other + Number(tmpnum)).num));
	}
	if (!IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum = other.num;
		tmpnum.erase(0, 1);
		return Number(Number(num) + Number(tmpnum));
	}
	if (IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum1 = num;
		tmpnum1.erase(0, 1);
		std::string tmpnum2 = other.num;
		tmpnum2.erase(0, 1);
		return Number(Number(tmpnum2) - Number(tmpnum1));
	}
	if (num.size() > 1 && num[0] == '0') {
		std::string tmpnum1 = num;
		tmpnum1.erase(0, 1);
		return Number(tmpnum1) - other;
	}
	if (other.num.size() > 1 && other.num[0] == '0') {
		std::string tmpnum2 = other.num;
		tmpnum2.erase(0, 1);
		return *this - Number(tmpnum2);
	}
	std::string tmpstr = "";
	int Ncount = 0;
	int index = 0;

	if (num.size() < other.num.size()) {
		return Number("-" + (other - Number(num)).num);
	}
	if (num.size() == other.num.size()) {
		for (index = 0; index < num.size(); index++) {
			if (num[index] < other.num[index])
				return Number("-" + (other - Number(num)).num);
			if (num[index] > other.num[index])
				break;
		}
	}

	for (index = 0; index < std::max(num.size(), other.num.size()); index++) {
		char tmpnum = '0';
		char tmpother = '0';
		char tmpsubtraction = '0';
		if (int(num.size()) - 1 - index >= 0) {
			tmpnum = num[num.size() - 1 - index];
		}
		if (int(other.num.size()) - 1 - index >= 0) {
			tmpother = other.num[other.num.size() - 1 - index];
		}
		if (char(tmpnum - tmpother + '0' + Ncount) < '0') {
			tmpsubtraction = tmpnum - tmpother + '0' + Ncount + 10;
			Ncount = -1;
		}
		else {
			if (char(tmpnum - tmpother + '0' + Ncount) >= '0') {
				tmpsubtraction = tmpnum - tmpother + '0' + Ncount;
				Ncount = 0;
			}
		}
		tmpstr = tmpsubtraction + tmpstr;
	}
	for (int i = 0; i < tmpstr.size(); i++) {
		if (tmpstr[i] == '0' && tmpstr.size() != 1) {
			tmpstr.erase(0, 1);
			i--;
		}
		else {
			break;
		}
	}
	return Number(tmpstr);
}

static Number partialMultiply(const Number& other, const char& digit) {
	Number result = other;
	int int_digit = digit - '0';
	for (auto& it : result.num) {
		it = unsigned char((it - '0') * int_digit + '0');
	}
	int carry = 0;
	for (auto it = result.num.rbegin(); it != result.num.rend(); it++) {
		if (unsigned char(*it + carry) > '9') {
			int one_num = (unsigned char(*it + carry) - '0');
			carry = one_num / 10;
			*it = one_num % 10 + '0';
		}
		else {
			*it += carry;
			carry = 0;
		}
	}
	if (carry > 0) {
		result.num = char('0' + carry) + result.num;
	}
	return result;
}

Number Number::operator*(const Number& other) const {
	if (IsNumberNegative(num) && !IsNumberNegative(other)) {
		std::string tmpnum = num;
		tmpnum.erase(0, 1);
		return '-' + (other * Number(tmpnum)).num;
	}
	if (!IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum = other.num;
		tmpnum.erase(0, 1);
		return '-' + (Number(num) * tmpnum).num;
	}
	if (IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum1 = num;
		std::string tmpnum2 = other.num;
		tmpnum1.erase(0, 1);
		tmpnum2.erase(0, 1);
		return Number(tmpnum1) * Number(tmpnum2);
	}
	if (num.size() > 1 && num[0] == '0') {
		std::string tmpnum1 = num;
		tmpnum1.erase(0, 1);
		return Number(tmpnum1) * other;
	}
	if (other.num.size() > 1 && other.num[0] == '0') {
		std::string tmpnum2 = other.num;
		tmpnum2.erase(0, 1);
		return *this * Number(tmpnum2);
	}
	Number result = { "0" };
	for (auto it : other.num) {
		result = result + partialMultiply(num, it);
		result.num += "0";
	}
	result.num.erase(result.num.end() - 1);
	return result;
}

//数的比较大小
bool Number::operator<(const Number& other) const {
	if (IsNumberNegative(num) && !IsNumberNegative(other)) {
		return true;
	}
	if (!IsNumberNegative(num) && IsNumberNegative(other)) {
		return false;
	}
	if (IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum1 = num;
		tmpnum1.erase(0, 1);
		std::string tmpnum2 = other.num;
		tmpnum2.erase(0, 1);
		return Number(tmpnum2) < Number(tmpnum1);
	}
	if (num.size() < other.num.size()) {
		return true;
	}
	if (num.size() > other.num.size()) {
		return false;
	}
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < other.num[i]) {
			return true;
		}
		if (num[i] > other.num[i]) {
			return false;
		}
	}
	return false;//相等
}

bool Number::operator>=(const Number& other) const {
	return !((*this) < other);
}

//数的除法
Number Number::operator/(const Number& other) const {
	if (IsNumberNegative(num) && !IsNumberNegative(other)) {
		std::string tmpnum = num;
		tmpnum.erase(0, 1);
		return '-' + (Number(tmpnum) / other).num;
	}
	if (!IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum = other.num;
		tmpnum.erase(0, 1);
		return '-' + (Number(num) / tmpnum).num;
	}
	if (IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum1 = num;
		std::string tmpnum2 = other.num;
		tmpnum1.erase(0, 1);
		tmpnum2.erase(0, 1);
		return Number(tmpnum1) / Number(tmpnum2);
	}
	if (IsNumberNegative(num) && !IsNumberNegative(other)) {
		std::string tmpnum = num;
		tmpnum.erase(0, 1);
		return Number(other - Number(tmpnum)).num;
	}
	if (!IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum = other.num;
		tmpnum.erase(0, 1);
		return Number(Number(num) - tmpnum);
	}
	if (IsNumberNegative(num) && IsNumberNegative(other)) {
		std::string tmpnum1 = num;
		std::string tmpnum2 = other.num;
		tmpnum1.erase(0, 1);
		tmpnum2.erase(0, 1);
		return Number('-' + (Number(tmpnum1) + Number(tmpnum2)).num);
	}
	if (num.size() > 1 && num[0] == '0') {
		std::string tmpnum1 = num;
		tmpnum1.erase(0, 1);
		return Number(tmpnum1) / other;
	}
	if (other.num.size() > 1 && other.num[0] == '0') {
		std::string tmpnum2 = other.num;
		tmpnum2.erase(0, 1);
		return *this / Number(tmpnum2);
	}
	std::string tmpstr = other.num;
	Number outputCountstr = { "" };
	Number tmpCountstr01 = { "" };//被除数用于计算的部分
	for (int i = 0; i < num.size(); i++) {
		tmpCountstr01.num = tmpCountstr01.num + num[i];
		if (tmpCountstr01 - Number(tmpstr) < Number("0")) {
			if (!outputCountstr.num.empty())
				outputCountstr.num = outputCountstr.num + '0';
			continue;
		}
		else {
			int j = 0;
			do {
				tmpCountstr01 = tmpCountstr01 - Number(tmpstr);
				++j;
			} while (!IsNumberNegative(tmpCountstr01));
			outputCountstr.num = outputCountstr.num + char('0' + j - 1);
			tmpCountstr01 = tmpCountstr01 + Number(tmpstr);
		}
	}
	while (outputCountstr.num.size() >= 2 && outputCountstr.num[0] == '0') {
		outputCountstr.num.erase(0, 1);
	}
	if (outputCountstr.num.empty())
		outputCountstr.num = "0";
	return outputCountstr;
}

