#include "RabinKarp.hpp"

using namespace algo;

std::vector<int> RabinKarp::search(const std::string& pat,
                                   const std::string& txt,
                                   uint64_t base,
                                   uint64_t mod) {
    size_t m = pat.size(), n = txt.size();
    if (!m || m > n) return {};

    uint64_t h = 1, pHash = 0, tHash = 0;
    for (size_t i = 0; i < m - 1; ++i) h = (h * base) % mod;

    for (size_t i = 0; i < m; ++i) {
        pHash = (pHash * base + pat[i]) % mod;
        tHash = (tHash * base + txt[i]) % mod;
    }

    std::vector<int> pos;
    for (size_t i = 0; i <= n - m; ++i) {
        if (pHash == tHash && txt.compare(i, m, pat) == 0)
            pos.push_back(static_cast<int>(i));

        if (i < n - m) {
            tHash = (base * (tHash + mod - txt[i] * h % mod) + txt[i + m]) % mod;
        }
    }
    return pos;
}