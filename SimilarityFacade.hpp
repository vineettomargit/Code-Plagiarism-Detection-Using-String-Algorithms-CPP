#pragma once
#include <string>

namespace algo {

struct SimilarityScores {
    double ngram;
    double kmp;
    double rabin;
    double suffix;
    double editNormalized;  // 1 - (dist / maxLen)
};

class SimilarityFacade {
public:
    // read files & compute scores
    static SimilarityScores compareFiles(const std::string& pathA,
                                         const std::string& pathB,
                                         std::size_t ngram = 5);
};

}  // namespace algo
