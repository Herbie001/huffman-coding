# Huffman Coding CLI Tool

> A CLI tool for file compression and decompression using Huffman coding trees. Modernizing an old school project by including modular architecture, scalable design, visualization support and benchmarking.

## Table of Contents

- [Overview](#overview)  
- [Features](#features)  
- [Installation](#installation)  
- [Usage](#usage)  
- [Architecture](#architecture)  
- [File Structure](#file-structure)  
- [Development](#development)  
- [Testing](#testing)  

---


## Overview

This project implements a Huffman coding-based compression in C++. This tool is designed to handle `.txt` and `.bin` files. The tool demonstrates:

- Ensuring lossess data compression to preserve essential information
- Canonical Huffman coding for deterministic encoding
- Optional visualization of Huffman trees (ASCII & Graphviz)
- Modular CLI interface analogous to a Linux command interface
- Currently supports .txt and .bin files.
- Future support planned for PDFs and images.

---

## Features

- Compress text or binary files using Huffman coding
- Decompress previously compressed files
- Generate ASCII and Graphviz `.dot` visualizations of Huffman trees
- Custom priority queue implementation to illustrate heap mechanics
- Cross-platform command-line interface
- Multithreading included for compression or decompression if the user desires to include multiple files.

---


## Installation

1. Git clone git@github.com:Herbie001/huffman-coding.git
2. Change directory 
```bash
cd huffman-coding
```
3. Build 
```bash
cmake -S . -B build
``` 
4. CMake
```bash
cmake --build build
```
5. After the compression or decompression process has been completed, you can check in the `uploads/` directory to find the file. Finally, you can refer to `benchmarking/` to see how well the compression algorithm held up against well-renowned software.


---

## Requirements

- C++17 or later  

---

// TODO: Make stronger also include demonstration 
## Usage 

This program is used to compress .txt files and .bin files. Working on adding support to compress more complex files like PDFs and images. 

---


## Architecture

[Link to Huffman Coding Hierachy](cli-hierarchy.txt)


---


## File Structure

- `benchmarking/`  
  Benchmark against well-renowned software and view the compression statistics.
    

- `docs/`  
  Project documentation, design notes, and algorithm references.

- `include/`  
  Public header files defining huffman coding, compression and decompression algorithms along with core logic.

- `src/`  
  Source files implementing huffman encoding, decoding and core application logic.

- `tests/`  
  Unit and integration tests for algorithms and utilities to ensure proper functionality.

- `uploads/`  
  Directory responsible for housing example files, compressed files, and decompressed files. 

- `.gitignore`  
  Git ignore rules for build artifacts and temporary files.

- `cli-hierarchy.txt`  
  Description of the command-line interface structure and available commands.

- `CMakeLists.txt`  
  CMake build configuration for compiling the project.

- `README.md`  
  Project overview, usage instructions, and documentation.

---

## Development

- Initially was supporting just single file compression and decompression, but I thought that might be boring especially if the user has more than one file.
- Wanted to include benchmarking to demostrate and compare it to well-renowned compression algorithms.
- For the command-line interface the goal was to have a very fluid and seamless interaction between the user

---

## Testing

Utilizing CMakeList coupled with the ability to fetch Google Test for the unit tests I've written to ensure code is running correctly.

Run the following bash commands:
```bash
cmake -S . -B build
```
```bash
cmake --build build
```

Then to see the results of the test
```bash
ctest --test-dir build
```

---