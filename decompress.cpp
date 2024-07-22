#include <iostream>
#include <fstream>
#include <vector>
#include "lz4.h"

void decompressFile(const std::string& inputFile, const std::string& outputFile, size_t originalSize) {
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Error opening input file!" << std::endl;
        return;
    }

    if (!outFile.is_open()) {
        std::cerr << "Error opening output file!" << std::endl;
        return;
    }

    // Read the compressed data into a buffer
    std::vector<char> compressedBuffer((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    size_t compressedSize = compressedBuffer.size();
    
    if (compressedSize == 0) {
        std::cerr << "Compressed file is empty or could not be read!" << std::endl;
        return;
    }

    // Prepare buffer for decompression
    std::vector<char> decompressedBuffer(originalSize);

    // Decompress the data
    int decompressedSize = LZ4_decompress_safe(compressedBuffer.data(), decompressedBuffer.data(), compressedSize, originalSize);

    if (decompressedSize < 0) {
        std::cerr << "Decompression failed!" << std::endl;
        return;
    }

    // Write the decompressed data to the output file
    outFile.write(decompressedBuffer.data(), decompressedSize);
    outFile.close();
}

int main() {
    size_t originalSize = 2994; // Replace with the actual size of input.txt
    decompressFile("compressed.lz4", "decompressed.txt", originalSize);
    std::cout << "Decompression completed!" << std::endl;
    return 0;
}
