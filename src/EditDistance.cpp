#include "EditDistance.hpp"
#include <vector>
#include <algorithm>

using namespace algo;

int EditDistance::levenshtein(const std::string& a,
                              const std::string& b) {
    size_t n = a.size(), m = b.size();
    std::vector<int> dp(m + 1);
    for (size_t j = 0; j <= m; ++j) dp[j] = j;
    for (size_t i = 1; i <= n; ++i) {
        int prev = dp[0];
        dp[0] = i;
        for (size_t j = 1; j <= m; ++j) {
            int tmp = dp[j];
            if (a[i - 1] == b[j - 1]) dp[j] = prev;
            else dp[j] = 1 + std::min({ prev, dp[j - 1], dp[j] });
            prev = tmp;
        }
    }
    return dp[m];
}
