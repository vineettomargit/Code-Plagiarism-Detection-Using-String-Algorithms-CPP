#pragma once
#include <string>

namespace algo {

class EditDistance {
public:
    static int levenshtein(const std::string& a,
                           const std::string& b);
};

}  // namespace algo
