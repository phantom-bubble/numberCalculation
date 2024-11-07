#include <chrono>
#include <iostream>
#include <rational.h>

int main() {

    std::cout  << "Ehlo, world!" << std::endl;
 
    Number n1("-00101");
    Number n2("005");
    auto now = std::chrono::steady_clock::now();
    Number n3("0");
    for(int i = 0; i < 1000000; i++)
        n3 = n1 * n2;
        std::cout << (std::chrono::steady_clock::now() - now).count() / 1000000000. << "s\n";
    std::cout << n3.num << std::endl;
    Number n4("0");
    Number n5("50000000");
    Number n6 = n4 / n5;
    std::cout << n6.num << std::endl;
    return 0;
}
