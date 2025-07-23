#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace algo {

class RabinKarp {
public:
    static std::vector<int> search(const std::string& pattern,
                                   const std::string& text,
                                   uint64_t base = 257,
                                   uint64_t mod  = 1'000'000'007ULL);
};

}  // namespace algo
