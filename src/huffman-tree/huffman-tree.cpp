#include "huffman-tree/huffman-tree.h"
#include <queue>

void deleteTree(Node* node) {
    if(node == nullptr) {
        return;
    }
    deleteTree(node->left_child);
    deleteTree(node->right_child);
    delete node;
}

HuffmanTree::~HuffmanTree() {
    deleteTree(root);
}

void HuffmanTree::generate(const std::vector<int>& freqs) {
    if(freqs.empty()) {
        root = nullptr;
        return;
    }
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> pq;
    for(int i = 0; i < freqs.size(); ++i) {
        int freq = freqs[i];
        if(freq > 0) {
            Node* new_node = new Node(freq, 
                    static_cast<unsigned char>(i));
            pq.push(new_node);
            leaves[i] = new_node;
        }
    }
    while(pq.size() > 1) {
        Node* first_tree = pq.top();
        pq.pop();
        Node* second_tree = pq.top();
        pq.pop();
        int sum = first_tree->count + second_tree->count;
        unsigned char dominant_symbol = std::min(
            first_tree->symbol,second_tree->symbol);
        Node* new_parent = new Node(sum,dominant_symbol);

        if(first_tree->symbol < second_tree->symbol) {
            new_parent->left_child = first_tree;
            new_parent->right_child = second_tree;
        } else {
            new_parent->left_child = second_tree;
            new_parent->right_child = first_tree;
        }
        first_tree->parent = new_parent;
        second_tree->parent = new_parent;
        pq.push(new_parent);
    }
    root = pq.top();
    pq.pop();
}

