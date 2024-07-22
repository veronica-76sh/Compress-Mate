#include "HuffmanCoding.h"

void printCodes(struct MinHeapNode* root, string str, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (root->data != '$')
        huffmanCode[root->data] = str;

    printCodes(root->left, str + "0", huffmanCode);
    printCodes(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(string text, unordered_map<char, string>& huffmanCode) {
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (auto pair : freq)
        minHeap.push(new MinHeapNode(pair.first, pair.second));

    while (minHeap.size() != 1) {
        MinHeapNode* left = minHeap.top(); minHeap.pop();
        MinHeapNode* right = minHeap.top(); minHeap.pop();

        MinHeapNode* top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }

    printCodes(minHeap.top(), "", huffmanCode);
}

string compress(string text, unordered_map<char, string>& huffmanCode) {
    string compressedText;
    for (char ch : text)
        compressedText += huffmanCode[ch];
    return compressedText;
}

string decompress(string compressedText, unordered_map<char, string>& huffmanCode) {
    unordered_map<string, char> reverseHuffmanCode;
    for (auto pair : huffmanCode)
        reverseHuffmanCode[pair.second] = pair.first;

    string currentCode;
    string decompressedText;
    for (char bit : compressedText) {
        currentCode += bit;
        if (reverseHuffmanCode.find(currentCode) != reverseHuffmanCode.end()) {
            decompressedText += reverseHuffmanCode[currentCode];
            currentCode = "";
        }
    }
    return decompressedText;
}

