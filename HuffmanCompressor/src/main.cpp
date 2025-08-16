#include "HuffmanCoding.h"
#include <iostream>
#include <fstream>
#include <sstream>

std::string readFile(const std::string &filename) {
    std::ifstream in(filename, std::ios::in);
    std::stringstream buffer;
    buffer << in.rdbuf();
    return buffer.str();
}

void writeFile(const std::string &filename, const std::string &data) {
    std::ofstream out(filename, std::ios::out);
    out << data;
}

int main() {
    std::string inputFile = "../data/sample.txt";
    std::string compressedFile = "../data/compressed.bin";
    std::string decompressedFile = "../data/decompressed.txt";

    std::string text = readFile(inputFile);
    std::cout << "Original text:\n" << text << "\n\n";

    HuffmanCoding hc;
    hc.build(text);

    std::string compressed = hc.compress(text);
    writeFile(compressedFile, compressed);
    std::cout << "Compressed size: " << compressed.size() << " bits\n";

    std::string decompressed = hc.decompress(compressed);
    writeFile(decompressedFile, decompressed);
    std::cout << "Decompressed text:\n" << decompressed << "\n";

    return 0;
}
