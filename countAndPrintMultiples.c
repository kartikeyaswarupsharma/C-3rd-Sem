#include <stdio.h>
#include <stdlib.h>

// Node structure for a binary search tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to perform an in-order traversal of the BST and count/print nodes that are multiples of k
void countAndPrintMultiples(struct TreeNode* root, int k) {
    if (root == NULL) {
        return;
    }

    countAndPrintMultiples(root->left, k);

    // Check if the current node's value is a multiple of k
    if (root->data % k == 0) {
        printf("%d is a multiple of %d\n", root->data, k);
    }

    countAndPrintMultiples(root->right, k);
}

// Function to free the memory allocated for the BST
void freeBST(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main() {
    // Create a sample BST
    struct TreeNode* root = NULL;
    int values[] = {30, 15, 50, 10, 20, 40, 60};

    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        root = insert(root, values[i]);
    }

    // Specify the value of k
    int k = 10;

    // Count and print nodes that are multiples of k
    printf("Nodes in the BST that are multiples of %d:\n", k);
    countAndPrintMultiples(root, k);

    // Free allocated memory for the BST
    freeBST(root);

    return 0;
}
