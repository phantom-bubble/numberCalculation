#include <chrono>
#include <iostream>
#include <rational.h>

int main() {

    std::cout  << "Ehlo, word!" << std::endl;
    Rational r1("91");
    Rational r2("7");
    Rational r3 = r1 / r2;
    std::cout << r3.numerator.num <<"/"<<r3.denominator.num << std::endl;
    return 0;
}
