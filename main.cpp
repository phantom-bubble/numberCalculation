#include <chrono>
#include <iostream>
#include <rational.h>

int main() {

    std::cout  << "Ehlo, word!" << std::endl;
    Rational r1("2");
    Rational r3 = (r1 - Rational{"1"}) / Rational{"1"} - (r1 - Rational{"1"}) * (r1 - Rational{"1"}) / Rational{"2"} + (r1 - Rational{"1"}) * (r1 - Rational{"1"}) * (r1 - Rational{"1"}) / Rational{"6"};
    std::cout << r3.to_ratio_string() << std::endl;
    return 0;
}
