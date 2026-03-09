# File I/O

The file I/O module is responsible for all reading and writing operations in the Huffman compression program. It handles:

- Binary-safe reading of the input file
- Bit-level writing of the compressed output (since Huffman codes are variable-length and not byte-aligned)
- Serialization of the Huffman tree (or frequency information) into a header
- Deserialization of the header during decompression to reconstruct the tree
- Round-trip correctness: compress → decompress should reproduce the original file exactly

This module provides two core abstractions:

- `BitWriter` — writes individual bits or sequences of bits to an output stream, buffering them into bytes
- `BitReader` — reads bits from an input stream, allowing bit-by-bit traversal during decompression

These classes are used by the high-level `compress_file()` and `decompress_file()` functions.

## BitWriter

**Purpose**  
`BitWriter` buffers individual bits and flushes them to a `std::ofstream` as full bytes. It is used during compression to write:

- The Huffman tree header (serialized structure)
- The encoded bitstream (variable-length prefix codes)

### Key Methods

- `write_bit(bool bit)`  
  Writes a single bit (0 or 1) to the internal buffer. When 8 bits are accumulated, they are written as a byte.

- `write_byte(uint8_t byte)`  
  Writes all 8 bits of a byte (most significant bit first).

- `write_bits(const std::string& bits)`  
  Convenience method: writes a string of '0' and '1' characters as bits (e.g. `"010110"`).

- `flush()`  
  Writes any remaining partial byte (left-padded with zeros) and clears the buffer.  
  Called automatically in the destructor.

### Usage Notes
- Always call `flush()` (or let the destructor handle it) before closing the output stream to avoid losing the last few bits.
- The output file is always opened in binary mode (`std::ios::binary`).

## BitReader

**Purpose**  
`BitReader` reads bits from a `std::ifstream` during decompression. It is used to:

- Read and reconstruct the Huffman tree from the header
- Traverse the tree bit-by-bit to decode symbols

### Key Methods

- `read_bit(bool& bit)` → `bool`  
  Reads the next single bit and stores it in `bit`. Returns `false` on EOF or error.

- `read_byte(uint8_t& byte)` → `bool`  
  Reads exactly 8 bits and reconstructs them into a byte (MSB first). Returns `false` on failure.

- Internal `refill()` mechanism automatically loads the next byte when the current buffer is exhausted.

### Usage Notes
- Always check the return value — `false` indicates end-of-file or read error.
- The input file must be opened in binary mode.

## Header Format (Tree Serialization)

The current implementation uses **pre-order tree serialization** (compact and standard for Huffman coding):

Serialization rule (recursive):

- Internal node → write bit `0`
- Leaf node     → write bit `1` followed by 8 bits (the original byte/symbol)

Deserialization mirrors this structure recursively.

**Advantages** compared to frequency table:

- Smaller header size (especially when many symbols appear)
- No need to store 64-bit counts
- Exact reconstruction of the tree (including structure)

**Trade-off**:

- Slightly more complex code
- Tree must be correctly balanced during construction

## High-Level Functions

### `void compress_file(const std::string& input_path, const std::string& output_path, const Node* root, const std::vector<std::string>& codes)`

1. Opens input file (binary)
2. Opens output file (binary)
3. Writes serialized Huffman tree as header
4. Reads each byte from input → looks up its code → writes bits
5. Flushes remaining bits

### `void decompress_file(const std::string& input_path, const std::string& output_path)`

1. Opens compressed file (binary)
2. Reads and reconstructs Huffman tree from header
3. Traverses the tree bit-by-bit:
   - 0 → left child
   - 1 → right child
   - When a leaf is reached → write the symbol and reset to root
4. Writes decompressed bytes to output file

## Important Considerations

- All file operations use **binary mode** to prevent newline transformations (`\n` → `\r\n` on Windows).
- The current implementation does **not** yet store:
  - Original file size
  - Number of padding bits in the last byte
  - File name / metadata
  → This means decompression stops exactly at EOF, which may include padding zeros if the last code didn't fill a byte.  
  Future improvement: add a footer or header field with original size or padding count.
- Memory management: the deserialized tree must be deleted after use to prevent leaks.

## Related Files

- `file_io.h` — declarations and class definitions
- `file_io.cpp` — implementation
- `huffman_tree.h` — `Node` structure (needed for serialization)
