#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

// Node for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

class HuffmanCoding {
private:
    Node* root;
    std::unordered_map<char, std::string> huffmanCodes;

    void buildCodes(Node* node, std::string str);
    void freeTree(Node* node);

public:
    HuffmanCoding();
    ~HuffmanCoding();

    void build(const std::string &text);
    std::string compress(const std::string &text);
    std::string decompress(const std::string &binaryStr);
};

#endif
