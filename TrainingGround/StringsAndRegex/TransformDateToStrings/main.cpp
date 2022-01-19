/*
Write a function that, given a text containing dates in the format dd.mm.yyyy or dd-mmyyyy, 
transforms the text so that it contains dates in the format yyyy-mm-dd.
*/
#include <iostream>
#include <regex>
#include <cassert>

std::string transform_date(std::string_view text) {
    auto rx = std::regex{ R"((\d{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))" };
    std::cout << std::regex_replace(text.data(), rx, R"($5-$3-$1)")<<std::endl;
    return std::regex_replace(text.data(), rx, R"($5-$3-$1)");
}

int main() {
    using namespace std::string_literals;
    assert(transform_date("today is 01.12.2017!"s) == "today is 2017-12-01!"s);
}