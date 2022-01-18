/* Write a program that will, given two or more positive integers, calculate and print the least
common multiple of them all.
*/
#include <iostream>
#include <numeric>
unsigned int recurgcd(unsigned int const a, unsigned int b)
{
    return b == 0 ? a : recurgcd(b, a%b);
}

int lcm(int const a, int const b)
{
    int h = recurgcd(a,b);
    return h ? (a * (b / h )) : 0;
}

int main()
{
    std::cout << lcm(10,15) << std::endl;
    std::cout << lcm(10,93) << std::endl;
}