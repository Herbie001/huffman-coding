# Huffman Coding Trees

Huffman coding is a **lossless data compression algorithm** that assigns variable-length binary codes to symbols based on their frequency of occurrence. Frequently occurring symbols receive shorter codes, while rarer symbols receive longer codes, resulting in overall compression.

The algorithm is **greedy** and produces an **optimal prefix-free binary tree**, known as a *Huffman coding tree*.

---

## Core Idea

Given a set of symbols and their frequencies:

1. Each symbol starts as a leaf node.
2. Repeatedly combine the two nodes with the lowest frequency.
3. The combined node becomes a new internal node whose frequency is the sum of its children.
4. Continue until a single root node remains.

The final tree encodes all symbols such that:
- No code is a prefix of another (prefix-free property)
- The weighted path length of the tree is minimized

---

## Tree Construction Algorithm

1. Create a leaf node for each symbol with non-zero frequency.
2. Insert all leaf nodes into a **min-priority queue** ordered by frequency.
3. While more than one node remains:
   - Remove the two nodes with the smallest frequency
   - Create a new internal node with these as children
   - Insert the new node back into the priority queue
4. The remaining node is the root of the Huffman tree.

This project optionally uses a **custom min-heap priority queue** to ensure deterministic ordering and explicit control over tie-breaking.

---

## Implementation Notes

- Internal tree nodes do not represent symbols.
- Leaf nodes store the symbol and its frequency.
- Left edges typically represent `0`, right edges represent `1`.
- A separate **canonical Huffman coding step** may be applied after tree construction to generate deterministic codes.

The Huffman tree itself is primarily used to:
- Compute code lengths
- Visualize symbol relationships
- Validate compression logic

---

## Time Complexity

Let:
- `n` = number of unique symbols

| Step | Complexity |
|-----|------------|
| Building initial nodes | O(n) |
| Heap construction | O(n) |
| Tree merging (n − 1 operations) | O(n log n) |
| Tree traversal | O(n) |

**Overall time complexity:**  
\[
O(n \log n)
\]

---

## Space Complexity

| Component | Space |
|---------|-------|
| Tree nodes | O(n) |
| Priority queue | O(n) |
| Auxiliary structures | O(n) |

**Overall space complexity:**  
\[
O(n)
\]

---

## Why Huffman Coding is Optimal

Huffman coding is optimal for prefix-free codes because:
- The greedy choice of merging the lowest-frequency symbols minimizes total weighted path length
- Any deviation would result in longer average code lengths

This optimality has been formally proven and is why Huffman coding is used in formats such as PNG, JPEG, and DEFLATE.
