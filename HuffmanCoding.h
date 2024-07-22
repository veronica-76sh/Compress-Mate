#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// A Huffman tree node
struct MinHeapNode {
    char data; // One of the input characters
    unsigned freq; // Frequency of the character
    MinHeapNode *left, *right; // Left and right child

    MinHeapNode(char data, unsigned freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// For comparison of two heap nodes (needed in min heap)
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
};

// Function to print Huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str, unordered_map<char, string>& huffmanCode);

// Function to build the Huffman tree and store it in the map
void buildHuffmanTree(string text, unordered_map<char, string>& huffmanCode);

// Function to compress the text using the Huffman codes
string compress(string text, unordered_map<char, string>& huffmanCode);

// Function to decompress the text using the Huffman tree
string decompress(string compressedText, unordered_map<char, string>& huffmanCode);

#endif // HUFFMAN_CODING_H
