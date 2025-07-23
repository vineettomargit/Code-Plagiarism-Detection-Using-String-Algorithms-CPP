#include "SimilarityFacade.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: plagcheck fileA fileB\n";
        return 1;
    }
    auto scores = algo::SimilarityFacade::compareFiles(argv[1], argv[2]);
    std::cout << std::fixed << std::setprecision(3)
              << "N-gram Jaccard       : " << scores.ngram         << '\n'
              << "KMP sample match     : " << scores.kmp           << '\n'
              << "Rabin-Karp sample    : " << scores.rabin         << '\n'
              << "Suffix-array sample  : " << scores.suffix        << '\n'
              << "Edit-distance (norm) : " << scores.editNormalized<< '\n';
}