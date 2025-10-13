#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "common.h"

#define MAX_CHARS 256
#define MAX_CODE_LENGTH 256

// Node for the Huffman Tree
typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

// Min-heap comparator for Huffman nodes
int minHeapComparator(void* arr, int i, int j) {
    Node* nodes = (Node*)arr;
    if (nodes[i].freq < nodes[j].freq) {
        return 1;
    } else if (nodes[i].freq > nodes[j].freq) {
        return -1;
    }
    return 0;
}

// Global lookup table to store the codes
char codes[MAX_CHARS][MAX_CODE_LENGTH];

// Recursively generates codes by traversing the tree
void generateCodes(Node* root, char code_str[], int top) {
    if (root->left) {
        code_str[top] = '0';
        generateCodes(root->left, code_str, top + 1);
    }
    if (root->right) {
        code_str[top] = '1';
        generateCodes(root->right, code_str, top + 1);
    }
    if (!root->left && !root->right) {
        code_str[top] = '\0';
        if (root->ch >= 0 && root->ch < MAX_CHARS) {
            strcpy(codes[root->ch], code_str);
        }
    }
}

// Main function to run the Huffman process on a string
void runHuffman(const char* input_string) {
    int freq[MAX_CHARS] = {0};
    int len = strlen(input_string);

    // Step 1: Count Frequencies
    for (int i = 0; i < len; i++) {
        if (input_string[i] >= 0 && input_string[i] < MAX_CHARS) {
            freq[input_string[i]]++;
        }
    }

    // Step 2: Build Huffman Tree
    HEAP h;
    initHeap(&h, sizeof(Node), minHeapComparator);
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            Node newNode = {(char)i, freq[i], NULL, NULL};
            insert(&h, &newNode);
        }
    }

    Node *left, *right, top_node;
    while (h.num_used > 1) {
        left = (Node*)malloc(sizeof(Node));
        right = (Node*)malloc(sizeof(Node));
        deleteMax(&h, left);
        deleteMax(&h, right);

        top_node.ch = '\0';
        top_node.freq = left->freq + right->freq;
        top_node.left = left;
        top_node.right = right;
        insert(&h, &top_node);
    }
    Node root;
    deleteMax(&h, &root);

    // Step 3: Encode the string
    printf("Original String: %s\n", input_string);
    char code_str[MAX_CODE_LENGTH];
    generateCodes(&root, code_str, 0);
    
    char encoded_string[len * 8]; // Max possible length (uncompressed)
    encoded_string[0] = '\0';

    for (int i = 0; i < len; i++) {
        strcat(encoded_string, codes[input_string[i]]);
    }
    printf("Encoded String: %s\n", encoded_string);
    
    // Step 4: Decode and Verify
    char decoded_string[len + 1];
    decoded_string[0] = '\0';
    Node* current = &root;

    for (int i = 0; encoded_string[i] != '\0'; i++) {
        if (encoded_string[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == NULL && current->right == NULL) {
            char temp[2];
            temp[0] = current->ch;
            temp[1] = '\0';
            strcat(decoded_string, temp);
            current = &root;
        }
    }

    printf("Decoded String: %s\n", decoded_string);

    // Final verification
    if (strcmp(input_string, decoded_string) == 0) {
        printf("✅ Verification successful! The decoded string is identical to the original.\n");
    } else {
        printf("❌ Verification failed! Strings are different.\n");
    }
}

int main() {
    const char* my_string = "this is a sample string for huffman coding";
    runHuffman(my_string);
    return 0;
}