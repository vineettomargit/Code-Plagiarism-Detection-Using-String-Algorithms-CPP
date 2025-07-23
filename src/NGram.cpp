#include "NGram.hpp"
#include <functional>

using namespace algo;

NGram::Fingerprint NGram::build(const std::string& txt, std::size_t n) {
    Fingerprint fp;
    if (txt.size() < n) return fp;
    std::hash<std::string_view> hasher;
    for (size_t i = 0; i + n <= txt.size(); ++i)
        fp.insert(hasher(std::string_view{txt}.substr(i, n)));
    return fp;
}

double NGram::jaccard(const Fingerprint& a, const Fingerprint& b) {
    if (a.empty() && b.empty()) return 1.0;
    size_t inter = 0;
    for (auto& h : a) if (b.count(h)) ++inter;
    size_t uni = a.size() + b.size() - inter;
    return static_cast<double>(inter) / uni;
}
