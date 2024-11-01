#pragma once
#include <string>

class Number {
public:
	std::string num;//大数用字符串表示，例如12="12"
public:
	//大数的加法
	Number operator+(const Number& other) const;
	Number operator-(const Number& other) const;
	Number(const std::string& num);
};