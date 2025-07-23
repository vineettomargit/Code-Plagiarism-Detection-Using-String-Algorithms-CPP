#pragma once
#include <string>
#include <vector>

namespace algo {

class KMP {
public:
    static std::vector<int> search(const std::string& pattern,
                                   const std::string& text);

private:
    static std::vector<int> buildLps(const std::string& pattern);
};

}  // namespace algo
