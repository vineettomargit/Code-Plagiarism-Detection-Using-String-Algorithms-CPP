#include "KMP.hpp"
#include <algorithm>  
using namespace algo;

std::vector<int> KMP::buildLps(const std::string& pat) {
    std::vector<int> lps(pat.size());
    for (size_t i = 1, len = 0; i < pat.size();) {
        if (pat[i] == pat[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

std::vector<int> KMP::search(const std::string& pat,
                             const std::string& txt) {
    if (pat.empty()) return {};
    auto lps = buildLps(pat);
    std::vector<int> pos;
    for (size_t i = 0, j = 0; i < txt.size();) {
        if (pat[j] == txt[i]) { ++i; ++j; }
        if (j == pat.size()) {
            pos.push_back(static_cast<int>(i - j));
            j = lps[j - 1];
        } else if (i < txt.size() && pat[j] != txt[i]) {
            j ? j = lps[j - 1] : ++i;
        }
    }
    return pos;
}
