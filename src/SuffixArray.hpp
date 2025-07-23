#pragma once
#include <string>
#include <vector>
#include <cstdint>

namespace algo {

class SuffixArray {
public:
    explicit SuffixArray(const std::string& text);

    // Returns starting indices of pattern occurrences.
    std::vector<int> substringSearch(const std::string& pattern) const;

    const std::vector<int>& sa() const { return suffixArr; }
    const std::vector<int>& lcp() const { return lcpArr; }

private:
    std::string s;
    std::vector<int> suffixArr;
    std::vector<int> lcpArr;

    void buildSuffixArray();
    void buildLcpArray();
};

}  // namespace algo
