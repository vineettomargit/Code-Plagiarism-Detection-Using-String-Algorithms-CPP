#include "SimilarityFacade.hpp"
#include "NGram.hpp"
#include "KMP.hpp"
#include "RabinKarp.hpp"
#include "SuffixArray.hpp"
#include "EditDistance.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>

using namespace algo;

static std::string readFile(const std::string& p) {
    std::ifstream in(p);
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

SimilarityScores SimilarityFacade::compareFiles(
        const std::string& aPath, const std::string& bPath,
        std::size_t ngram) {

    std::string A = readFile(aPath);
    std::string B = readFile(bPath);

    // N-gram Jaccard
    auto fpA = NGram::build(A, ngram);
    auto fpB = NGram::build(B, ngram);
    double jacc = NGram::jaccard(fpA, fpB);

    // Representative exact-substring check (first 80 chars of B)
    std::string probe = B.substr(0, std::min<size_t>(80, B.size()));
    bool kmpHit   = !KMP::search(probe, A).empty();
    bool rabinHit = !RabinKarp::search(probe, A).empty();

    // Suffix-array count of pattern hits
    SuffixArray SA(A);
    std::size_t saHits = SA.substringSearch(probe).size();
    double saScore = saHits ? 1.0 : 0.0;

    // Edit distance (normalized)
    int dist = EditDistance::levenshtein(A, B);
    double editNorm = 1.0 - static_cast<double>(dist) /
                      std::max(A.size(), B.size());

    return { jacc,
             kmpHit ? 1.0 : 0.0,
             rabinHit ? 1.0 : 0.0,
             saScore,
             editNorm };
}
