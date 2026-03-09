#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include "nodes.h"
#include "io/file-handler.h"
#include <string>
#include <queue>
#include <vector>
#include <fstream>
#include <algorithm>

class HuffmanTree {

    private:
        Node* root;
        std::vector<Node* > leaves{256, nullptr};
    
    public:
        HuffmanTree() = default;
        ~HuffmanTree();
        void generate(const std::vector<int>& freqs);
        void initializeEncoding();
        void compression(int value, Writer& outfile);
        // facilitator function that brings it all together
        void initialize(
            std::vector<int>& freqs);
        void encode(
            std::vector<int>& freqs, 
            std::ifstream& input_file, 
            std::ofstream& output_file, 
            Node* root);
        void decompression();
        void decode(
            std::ofstream& input_file, 
            std::ofstream& output_file);
};

#endif