/* Write a program that, given two positive integers, will calculate and print the greatest
common divisor of the two.
*/
#include <iostream>
unsigned int recurgcd(unsigned int const a, unsigned int b)
{
    return b == 0 ? a : recurgcd(b, a%b);
}

unsigned int unrecurgdc(unsigned int a, unsigned int b)
{
    while (b != 0) {
        unsigned int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    unsigned int a = 10;
    unsigned int b = 999;
    a = recurgcd(a,0);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a = recurgcd(b, a % b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    a = unrecurgdc(b,a);
    b = unrecurgdc(a,b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}