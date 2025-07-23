#pragma once
#include <unordered_map>
#include <memory>

namespace algo {

class Trie {
    struct Node {
        bool end = false;
        std::unordered_map<char, std::unique_ptr<Node>> nxt;
    };
    std::unique_ptr<Node> root = std::make_unique<Node>();

public:
    void insert(const std::string& word);
    bool contains(const std::string& word) const;
};

}  // namespace algo
