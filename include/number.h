#pragma once
#include <string>

class Number {
public:
	std::string num;//�������ַ�����ʾ������12="12"
public:
	bool operator<(const Number& other) const;
	bool operator>=(const Number& other) const;
	//�����ļӷ����������˷�
	Number operator+(const Number& other) const;
	Number operator-(const Number& other) const;
	Number operator*(const Number& other) const;
	Number operator/(const Number& other) const;
	Number(const std::string& num);
};