/* Write a function that, given a string that represents a URL, parses and extracts the parts of
the URL (protocol, domain, port, path, query, and fragment).
*/
#include <iostream>
#include <regex>
#include <optional>

struct uri_parts {
    std::string                protocol;
    std::string                domain;
    std::optional<int>         port;
    std::optional<std::string> path;
    std::optional<std::string> query;
    std::optional<std::string> fragment;
};

std::optional<uri_parts> parse_uri(std::string uri) {
    std::regex rx(R"(^(\w+):\/\/([\w.-]+)(:(\d+))?([\w\/\.]+)?(\?([\w=&]*)(#?(\w+))?)?$)");
    auto matches = std::smatch{};
    if (std::regex_match(uri, matches, rx)) {
        if (matches[1].matched && matches[2].matched) {
            uri_parts parts;
            parts.protocol = matches[1].str();
            parts.domain = matches[2].str();
            if (matches[4].matched)
                parts.port = std::stoi(matches[4]);
            if (matches[5].matched)
                parts.path = matches[5];
            if (matches[7].matched)
                parts.query = matches[7];
            if (matches[9].matched)
                parts.fragment = matches[9];
            std::cout << matches.str() << std::endl;
            return parts;
        }
    }
    return {};
}

int main() {
    parse_uri("https://bbc.com:80/en/index.html?lite=true#ui");
}