#include <iostream>
#include <fstream>
#include <vector>
#include "lz4.h"

void compressFile(const std::string& inputFile, const std::string& outputFile) {
    // Open input and output files
    std::ifstream inFile(inputFile, std::ios::binary);
    std::ofstream outFile(outputFile, std::ios::binary);
    
    if (!inFile) {
        std::cerr << "Error opening input file!" << std::endl;
        return;
    }
    
    if (!outFile) {
        std::cerr << "Error opening output file!" << std::endl;
        return;
    }
    
    // Read input file into buffer
    std::vector<char> inputBuffer((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    size_t inputSize = inputBuffer.size();

    // Prepare buffers for compression
    size_t maxCompressedSize = LZ4_compressBound(inputSize);
    std::vector<char> compressedBuffer(maxCompressedSize);
    
    // Compress data
    int compressedSize = LZ4_compress_default(inputBuffer.data(), compressedBuffer.data(), inputSize, maxCompressedSize);
    if (compressedSize < 0) {
        std::cerr << "Compression failed!" << std::endl;
        return;
    }
    
    // Write compressed data to output file
    outFile.write(compressedBuffer.data(), compressedSize);
    
    std::cout << "Original file size: " << inputSize << " bytes" << std::endl;
    std::cout << "Compressed file size: " << compressedSize << " bytes" << std::endl;
}

int main() {
    compressFile("input.txt", "compressed.lz4");
    std::cout << "Compression completed!" << std::endl;
    return 0;
}
