#include <iostream>
#include <number.h>


int main() {

    std::cout  << "Ehlo, world!" << std::endl;
 
    Number n1("0000");
    Number n2("005");
 //   for(int i = 0; i < 1000000; i++)
        Number n3 = n1 - n2;
    std::cout << n3.num << std::endl;
    Number n4("0");
    Number n5("50000000");
    Number n6 = n4 / n5;
    std::cout << n6.num << std::endl;
    return 0;
}