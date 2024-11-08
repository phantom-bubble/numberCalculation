#include <chrono>
#include <iostream>
#include <rational.h>

int main() {

    std::cout  << "Ehlo, word!" << std::endl;
    Rational r1("2");
    Rational r2 = r1 - Rational{"1"};
    Rational r3 = r2 / Rational{"1"} - r2 * r2 / Rational{"2"} + r2 * r2 * r2 / Rational{"6"} - r2 * r2 * r2 * r2 / Rational{"24"} + r2 * r2 * r2 * r2 * r2 / Rational{"120"};
    std::cout << r3.to_ratio_string() << std::endl;
    return 0;
}
