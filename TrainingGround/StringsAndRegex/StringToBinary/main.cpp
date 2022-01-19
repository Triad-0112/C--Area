#include <iostream>
#include <vector>
#include <cassert>
#include <iterator>

unsigned char hexchar_to_int(char const ch) {
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
        throw std::invalid_argument("Invalid hexadecimal character");
}

std::vector<unsigned char> hexchar_to_bytes(std::string_view str) {
    std::vector<unsigned char> result;
    for (size_t i = 0; i < str.size(); i += 2) {
        result.push_back((hexchar_to_int(str[i])<<4) | hexchar_to_int(str[i+1]));
    }
    for (int i : result) {
        std::cout << i << " ";
    }
    return result;
}
void print(std::vector<unsigned char> const &input) {
    std::copy(input.begin(),input.end(),std::ostream_iterator<unsigned char>(std::cout, " "));
}
int main() {
    std::vector<unsigned char> expected{ 0xBA, 0xAD, 0xF0, 0x0D, 0x42 };
    assert(hexchar_to_bytes("BAADF00D42")==expected);
    assert(hexchar_to_bytes("BaaDf00d42")==expected);
    hexchar_to_bytes("BaaDf00d42");
}