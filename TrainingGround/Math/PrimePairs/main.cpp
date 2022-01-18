#include <iostream>
bool is_prime(int const num)
{
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    else
    {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i+2) == 0) {
                return false;
            }
        }
        return true;
    }
}

int sexyPair(int const limit) {
    std::cout << "Sexy Pairs: "<<std::endl;
    int count = 1;
    for(int i = 2; i <= limit; i++) {
        if (is_prime(i) && is_prime(i+6)) {
            std::cout << count << ".  " << i << "," << i+6 << std::endl;
            count++;
        }
    }
    std::cout << std::endl;
    return 0;
}

int twinPair(int const limit) {
    std::cout << "Twin Pairs: "<<std::endl;
    int count = 1;
    for(int i = 2; i <= limit; i++) {
        if (is_prime(i) && is_prime(i+2)) {
            std::cout << count << ".  " << i << "," << i+2 << std::endl;
            count++;
        }
    }
    std::cout << std::endl;
    return 0;
}

int cousinPair(int const limit) {
    std::cout << "Cousin Pairs: "<<std::endl;
    int count = 1;
    for(int i = 2; i <= limit; i++) {
        if (is_prime(i) && is_prime(i+4)) {
            std::cout << count << ".  " << i << "," << i+4 << std::endl;
            count++;
        }
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    int limit;
    std::cout << "Upper Limit: ";
    std::cin >> limit;
    twinPair(limit);
    cousinPair(limit);
    sexyPair(limit);
    return 0;
}