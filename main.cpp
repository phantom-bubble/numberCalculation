#include <iostream>
#include <number.h>


int main() {

    std::cout  << "Ehlo, world!" << std::endl;
 
    Number n1("5");
    Number n2("499995");
    Number n3 = n1 + n2;
    std::cout << n3.num << std::endl;
    Number n4("900000000");
    Number n5("555555555");
    Number n6 = n4 - n5;
    std::cout << n6.num << std::endl;
    return 0;
}