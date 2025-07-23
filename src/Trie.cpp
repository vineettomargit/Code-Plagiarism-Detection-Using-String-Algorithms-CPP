#include "Trie.hpp"
#include <string>

using namespace algo;

void Trie::insert(const std::string& w) {
    Node* cur = root.get();
    for (char c : w) cur = (cur->nxt[c] = std::move(
        cur->nxt[c] ? std::move(cur->nxt[c]) : std::make_unique<Node>()
    )).get();
    cur->end = true;
}

bool Trie::contains(const std::string& w) const {
    const Node* cur = root.get();
    for (char c : w) {
        auto it = cur->nxt.find(c);
        if (it == cur->nxt.end()) return false;
        cur = it->second.get();
    }
    return cur->end;
}