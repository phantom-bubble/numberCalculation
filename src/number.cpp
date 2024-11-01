#include "number.h"
#include <iostream>
#include <string>
#include <algorithm>

//大数类
Number::Number(const std::string& numstr) {
	num = numstr;
}

Number Number::operator+(const Number& other) const {
		std::string tmpstr = "";
		int Ncount = 0;
		int index = 0;
		for (index = 0; index < std::max(num.size(), other.num.size()); index++){
//			std::cout << "index:" << index << std::endl;
			char tmpnum = '0';
			char tmpother = '0';
			char tmpaddtion = '0';
			if (int(num.size()) - 1 - index >= 0) {
				tmpnum=num[num.size() - 1 - index];
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

//std::string Numberversal(const std::string& inputstring){
//	std::string tmpstr = "";
//	int index = 0;
//	for (index = 0; index < inputstring.size(); index++) {
//		tmpstr= tmpstr+char('0'+':'-inputstring[index]);
//	}
//	return tmpstr;
//}

Number Number::operator-(const Number& other) const {
	std::string tmpstr = "";
	int Ncount = 0;
	int index = 0;

	if (num.size() < other.num.size()) {
		return Number("-"+(other-Number(num)).num);
	}
	if (num.size() == other.num.size()) {
		for (index = 0; index < num.size(); index++) {
			if(num[index] < other.num[index])
				return Number("-" + (other - Number(num)).num);
			if (num[index] > other.num[index])
				break;
		}
	}
	
	for (index = 0; index < std::max(num.size(), other.num.size()); index++){
//		std::cout << "index:" << index << std::endl;
		char tmpnum = '0';
		char tmpother = '0';
		char tmpsubtraction = '0';
		if (int(num.size()) - 1 - index >= 0) {
			tmpnum=num[num.size() - 1 - index];
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
		if (tmpstr[i] == '0') {
			tmpstr.erase(0, 1);
			i--;
		}
		else {
			break;
		}
	}
	//if (Ncount != 0) {
	//	tmpstr = Numberversal(tmpstr);
	//	tmpstr = char('-') + tmpstr;
	//}
	return Number(tmpstr);
}

