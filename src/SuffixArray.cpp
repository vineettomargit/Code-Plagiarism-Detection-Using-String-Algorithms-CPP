#include "SuffixArray.hpp"
#include <algorithm>

using namespace algo;

SuffixArray::SuffixArray(const std::string& text) : s(text) {
    buildSuffixArray();
    buildLcpArray();
}

void SuffixArray::buildSuffixArray() {
    int n = static_cast<int>(s.size());
    suffixArr.resize(n);
    std::vector<int> rank(n), tmp(n);
    for (int i = 0; i < n; ++i) {
        suffixArr[i] = i;
        rank[i] = s[i];
    }
    for (int k = 1;; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = i + k < n ? rank[i + k] : -1;
            int rj = j + k < n ? rank[j + k] : -1;
            return ri < rj;
        };
        std::sort(suffixArr.begin(), suffixArr.end(), cmp);
        tmp[suffixArr[0]] = 0;
        for (int i = 1; i < n; ++i)
            tmp[suffixArr[i]] = tmp[suffixArr[i - 1]] + cmp(suffixArr[i - 1],
                                                             suffixArr[i]);
        rank.swap(tmp);
        if (rank[suffixArr[n - 1]] == n - 1) break;
    }
}

void SuffixArray::buildLcpArray() {
    int n = static_cast<int>(s.size());
    lcpArr.assign(n, 0);
    std::vector<int> inv(n);
    for (int i = 0; i < n; ++i) inv[suffixArr[i]] = i;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (inv[i] == 0) continue;
        int j = suffixArr[inv[i] - 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
        lcpArr[inv[i]] = k;
        if (k) --k;
    }
}

std::vector<int> SuffixArray::substringSearch(
        const std::string& pat) const {
    int n = s.size(), m = pat.size();
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (s.compare(suffixArr[mid], m, pat) < 0) left = mid + 1;
        else right = mid;
    }
    int l = left;
    right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (s.compare(suffixArr[mid], m, pat) <= 0) left = mid + 1;
        else right = mid;
    }
    int r = left;
    std::vector<int> res;
    for (int i = l; i < r; ++i) res.push_back(suffixArr[i]);
    return res;
}
