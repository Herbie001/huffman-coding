# Encoding & Decoding Using Huffman Coding Trees

This document describes how Huffman coding trees are used for **encoding** and **decoding** data, along with their time and space complexity.

---

## Encoding

### Overview

Encoding transforms an input stream of symbols into a compressed binary representation using Huffman codes.

### Steps

1. **Frequency Analysis**
   - Read the input file and count the frequency of each symbol.

2. **Tree Construction**
   - Build a Huffman coding tree from the frequency table.

3. **Code Generation**
   - Traverse the tree to determine the binary code for each symbol.
   - Each left edge adds a `0`, each right edge adds a `1`.

4. **Canonical Code Conversion (Optional)**
   - Convert codes to canonical Huffman codes using only code lengths.
   - Ensures deterministic output and smaller headers.

5. **Bitstream Encoding**
   - Replace each symbol in the input with its corresponding Huffman code.
   - Write bits to a binary output file with proper padding.

6. **Metadata Storage**
   - Store symbol-code length mappings and padding information in the file header.

---

### Encoding Time Complexity

Let:
- `n` = number of input symbols
- `k` = number of unique symbols

| Step | Complexity |
|-----|------------|
| Frequency analysis | O(n) |
| Tree construction | O(k log k) |
| Code generation | O(k) |
| Encoding bitstream | O(n) |

**Overall encoding complexity:**  
\[
O(n + k \log k)
\]

---

### Encoding Space Complexity

| Component | Space |
|----------|-------|
| Frequency table | O(k) |
| Huffman tree | O(k) |
| Code table | O(k) |
| Output buffer | O(1) to O(n)\* |

\*Depending on whether streaming or full buffering is used.

---

## Decoding

### Overview

Decoding reconstructs the original data from the compressed binary representation.

### Steps

1. **Read Metadata**
   - Validate file format and version.
   - Read symbol-code length mappings.
   - Determine padding information.

2. **Rebuild Decoding Structure**
   - Reconstruct the Huffman decoding tree from canonical codes.

3. **Bitstream Decoding**
   - Read bits sequentially.
   - Traverse the decoding tree:
     - `0` → left
     - `1` → right
   - Emit symbol when a leaf node is reached.

4. **Output Reconstruction**
   - Write decoded symbols to the output file.

---

### Decoding Time Complexity

Let:
- `n` = number of encoded symbols
- `L` = average code length

| Step | Complexity |
|-----|------------|
| Tree reconstruction | O(k) |
| Bit traversal | O(n · L) |
| Output writing | O(n) |

Since `L` is bounded and small in practice:

**Overall decoding complexity:**  
\[
O(n)
\]

---

### Decoding Space Complexity

| Component | Space |
|----------|-------|
| Decoding tree | O(k) |
| Input buffer | O(1) to O(n) |
| Output buffer | O(1) to O(n) |

---

## Key Properties

- **Lossless**: Decoding perfectly reconstructs the original input.
- **Prefix-Free**: No encoded symbol is a prefix of another.
- **Deterministic (Canonical)**: Same input produces identical compressed output.
- **Streaming-Friendly**: Supports bit-by-bit decoding without full buffering.

---

## Summary

Huffman coding provides efficient, optimal, and practical lossless compression. By separating tree construction, canonical encoding, and decoding logic, this project achieves both clarity and scalability while remaining faithful to industry-standard implementations.
