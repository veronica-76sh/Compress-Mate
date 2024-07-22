# CompressMate

![CompressMate Logo](path/to/logo.png)

## Overview

**CompressMate** is a powerful and efficient file compression tool developed in C++. It supports fast and reliable compression and decompression of files using advanced algorithms, including LZ4 and Huffman coding.

## Features

- **High-Speed Compression**: Utilizes the LZ4 algorithm for rapid file compression.
- **Efficient Decompression**: Ensures quick and accurate file decompression.
- **User-Friendly Interface**: Simple command-line interface for ease of use.
- **Robust Performance**: Handles large files and datasets efficiently.

## Installation

To use CompressMate, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/CompressMate.git
    ```
2. Navigate to the project directory:
    ```bash
    cd CompressMate
    ```
3. Build the project using g++ (Ensure you have LZ4 installed):
    ```bash
    g++ -o compress compress.cpp -I/path/to/lz4/include -L/path/to/lz4/lib -llz4
    g++ -o decompress decompress.cpp -I/path/to/lz4/include -L/path/to/lz4/lib -llz4
    ```

## Usage

### Compression

To compress a file, use the following command:
```bash
./compress input.txt output.lz4


Compress a file:
./compress example.txt compressed.lz4

Decompress the file:
./decompress compressed.lz4 decompressed.txt 2994

Project Structure:
CompressMate/
├── include/
│   └── lz4.h
├── src/
│   ├── compress.cpp
│   └── decompress.cpp
├── examples/
│   └── example.txt
├── README.md



Happy Compressing with CompressMate!



