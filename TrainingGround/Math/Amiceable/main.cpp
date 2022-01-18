/*
An abundant number, also known as an excessive number, is a number for which the sum
of its proper divisors is greater than the number itself. The proper divisors of a number are
the positive prime factors of the number, other than the number itself. The amount by
which the sum of proper divisors exceeds the number itself is called abundance. For
instance, the number 12 has the proper divisors 1, 2, 3, 4, and 6. Their sum is 16, which
makes 12 an abundant number. Its abundance is 4 (that is, 16 - 12).
To determine the sum of proper divisors, we try all numbers from 2 to the square root of
the number (all prime factors are less than or equal to this value). If the current number,
let’s call it i, divides the number, then i and num/i are both divisors. However, if they are
equal (for example, if i = 3, and n = 9, then i divides 9, but n/i = 3), we add
only i because proper divisors must only be added once. Otherwise, we add
both i and num/i and continue:
*/
#include <iostream>
#include <cmath>
int sum_proper_divisors(int const number) {
    int result = 1;
    for (int i = 2; i <= std::sqrt(number);i++) {
        if (number%i == 0) {
            result += (i == (number / i )) ? i : (i + number / i);
        }
    }
    return result;
}

void print_amiceable(int const limit) {
    for (int number = 4; number < limit; ++number) {
        auto sum1 = sum_proper_divisors(number);
        if (sum1 < limit) {
            auto sum2 = sum_proper_divisors(sum1);
            if (sum2 == number && number != sum1 && number < sum1) {
                std::cout << number << "," << sum1 << std::endl;
            }
        }
    }
}

int main() {
    int limit = 0;
    std::cout << "Upper Limit: ";
    std::cin >> limit;
    print_amiceable(limit);
} 