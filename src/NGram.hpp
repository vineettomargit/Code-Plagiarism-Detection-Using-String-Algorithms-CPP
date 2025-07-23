#pragma once
#include <string>
#include <unordered_set>

namespace algo {

class NGram {
public:
    using Fingerprint = std::unordered_set<uint64_t>;

    static Fingerprint build(const std::string& text,
                             std::size_t n = 5);
    static double jaccard(const Fingerprint& a,
                          const Fingerprint& b);
};

}  // namespace algo
