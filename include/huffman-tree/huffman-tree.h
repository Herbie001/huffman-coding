#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H
#include "nodes.h"
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
        void encode();
        void decode();
        
};

#endif