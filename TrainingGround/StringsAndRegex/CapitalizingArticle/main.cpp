#include <iostream>
#include <cassert>
#include <sstream>

template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
using tstringstream = std::basic_stringstream<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
tstring<Elem> capitalize(tstring<Elem> const & text) {
    tstringstream<Elem> result;
    bool newWord = true;
    for (auto const ch : text) {
        newWord = newWord || std::ispunct(ch) || std::isspace(ch);
        if (std::isalpha(ch)) {
            if (newWord) {
                result << static_cast<Elem>(std::toupper(ch));
                newWord = false;
            } else {
                result << static_cast<Elem>(std::tolower(ch));
            }
        }
        else result << ch;
    }
    for (char i : result.str()) {
        std::cout << i << "";
    }
    std::cout << std::endl;
    return result.str();
}

int main() {
    using namespace std::string_literals;
    assert("The C++ Challenger"s == capitalize("the c++ challenger"s));
    assert("This Is An Example, Should Work!"s == capitalize("THIS IS an ExamplE, should wORK!"s));
    capitalize("HEY BROOO This TitLE is Ignorant!! fix me"s);
    capitalize("C++ iS AWesOME FiX and RepEat, SleEp and RE-Initiate"s);
}