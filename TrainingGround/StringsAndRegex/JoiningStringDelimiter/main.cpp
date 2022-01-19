/*
Write a function that, given a list of strings and a delimiter, creates a new string by
concatenating all the input strings separated with the specified delimiter. The delimiter
must not appear after the last string, and when no input string is provided, the function
must return an empty string.
Example: input { "this","is","an","example" } and delimiter ' ' (space), output:
"this is an example".
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <iterator>
#include <sstream>
#include <string>

template <typename Iter>
std::string join_strings(Iter begin, Iter end, char const * const separator) {
    std::ostringstream os;
    std::copy(begin, end-1, std::ostream_iterator<std::string>(os,separator));
    os << * (end-1);
    return os.str();
}

template <typename C>
std::string join_strings(C const & c, char const * const separator) {
    if (c.size() == 0) return std::string{};
    for (char i : join_strings(std::begin(c),std::end(c),separator)) {
        std::cout << i << "";
    }
    std::cout << "\n";
    return join_strings(std::begin(c),std::end(c),separator);
}

int main() {
    using namespace std::string_literals;
    std::vector<std::string> v1{ "this", "is", "an", "example" };
    std::vector<std::string> v2{ "example" };
    std::vector<std::string> v3{  };
    assert(join_strings(v1, " ")== "this is an example"s);
    assert(join_strings(v2, " ")== "example"s);
    assert(join_strings(v3, " ")== ""s);
}