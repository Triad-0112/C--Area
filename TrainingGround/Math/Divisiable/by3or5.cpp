/* Write a program that calculates and prints the sum of all the natural numbers divisible by either 3 or 5, 
up to a given limit entered by the user.
*/
#include <iostream>
int main() 
{
    unsigned int limit = 0;
    std::cout << "Upper limit: ";
    std::cin >> limit;
    unsigned long long sum = 0;
    for (unsigned int i = 3; i< limit; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    std::cout << "sum=" << sum << std::endl;
}