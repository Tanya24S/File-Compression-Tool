#include "HuffmanCoding.h"
#include <iostream>
#include <fstream>

HuffmanCoding::HuffmanCoding() : root(nullptr) {}

HuffmanCoding::~HuffmanCoding() {
    freeTree(root);
}

void HuffmanCoding::freeTree(Node* node) {
    if (!node) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

void HuffmanCoding::buildCodes(Node* node, std::string str) {
    if (!node) return;
    if (!node->left && !node->right) {
        huffmanCodes[node->ch] = str;
    }
    buildCodes(node->left, str + "0");
    buildCodes(node->right, str + "1");
}

void HuffmanCoding::build(const std::string &text) {
    std::unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (auto &pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;

        pq.push(merged);
    }

    root = pq.top();
    buildCodes(root, "");
}

std::string HuffmanCoding::compress(const std::string &text) {
    std::string encodedStr;
    for (char c : text) {
        encodedStr += huffmanCodes[c];
    }
    return encodedStr;
}

std::string HuffmanCoding::decompress(const std::string &binaryStr) {
    std::string decodedStr;
    Node* curr = root;

    for (char bit : binaryStr) {
        curr = (bit == '0') ? curr->left : curr->right;

        if (!curr->left && !curr->right) {
            decodedStr += curr->ch;
            curr = root;
        }
    }

    return decodedStr;
}
