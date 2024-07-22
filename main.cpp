#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "HuffmanCoding.h"

using namespace std;

void printFileSize(const string& filePath, const string& description) {
    ifstream file(filePath, ios::binary | ios::ate);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }
    streampos size = file.tellg();
    cout << description << ": " << size << " bytes" << endl;
}

void compressFile(const string& inputFilePath, const string& outputFilePath) {
    ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf(); // Read the entire file into the buffer
    string text = buffer.str(); // Convert the buffer into a string
    inputFile.close();

    unordered_map<char, string> huffmanCode;
    buildHuffmanTree(text, huffmanCode);

    string compressedText = compress(text, huffmanCode);

    ofstream outputFile(outputFilePath, ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file" << endl;
        return;
    }

    outputFile << compressedText;
    outputFile.close();
}

void decompressFile(const string& inputFilePath, const string& outputFilePath) {
    ifstream inputFile(inputFilePath, ios::binary);
    if (!inputFile.is_open()) {
        cerr << "Error opening input file" << endl;
        return;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf(); // Read the entire file into the buffer
    string compressedText = buffer.str(); // Convert the buffer into a string
    inputFile.close();

    unordered_map<char, string> huffmanCode;
    buildHuffmanTree(compressedText, huffmanCode);

    string decompressedText = decompress(compressedText, huffmanCode);

    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file" << endl;
        return;
    }

    outputFile << decompressedText;
    outputFile.close();
}

int main() {
    string inputFilePath = "input.txt";
    string compressedFilePath = "compressed.txt";
    string decompressedFilePath = "decompressed.txt";

    // Print original file size
    printFileSize(inputFilePath, "Original file size");

    // Compress the file
    compressFile(inputFilePath, compressedFilePath);
    cout << "Compression completed!" << endl;

    // Print compressed file size
    printFileSize(compressedFilePath, "Compressed file size");

    // Decompress the file
    decompressFile(compressedFilePath, decompressedFilePath);
    cout << "Decompression completed!" << endl;

    // Print decompressed file size
    printFileSize(decompressedFilePath, "Decompressed file size");

    return 0;
}
