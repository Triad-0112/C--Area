#include <iostream>
#include <numeric>
#include <algorithm>
bool validate_isbn_10(std::string_view isbn) {
    auto valid = false;
    if (isbn.size() == 10 && std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10) {
        auto w = 10;
        auto sum = std::accumulate(std::begin(isbn),std::end(isbn),0,[&w] (int const total, char const c) {
            return total + w-- * ( c - '0');
        });
        valid = !(sum % 11);
    }
    return valid;
}
int main() {
    std::cout << validate_isbn_10("0-7167-0344-0") << std::endl;
}