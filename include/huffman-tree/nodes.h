#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H

struct Node {
    public:
        int count = 0;
        unsigned char symbol = 0;
        Node* parent = nullptr;
        Node* left_child = nullptr;
        Node* right_child = nullptr;
        
        Node(int count, unsigned char symbol);
};

struct NodeComparator {
    bool operator()(const Node* left, const Node* right) const {
        if(left->count != right->count) {
            return left->count > right->count;
        } else {
            return left->symbol > right->symbol;
        }
    }
};

#endif