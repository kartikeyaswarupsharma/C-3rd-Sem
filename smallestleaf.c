#include <stdio.h>
#include <stdlib.h>

// Define a basic structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the smallest leaf node in a BST
struct Node* findSmallestLeaf(struct Node* root) {
    // If the tree is empty
    if (root == NULL)
        return NULL;

    // If the current node is a leaf
    if (root->left == NULL && root->right == NULL)
        return root;

    // Recursively find the smallest leaf in the left subtree
    struct Node* leftSmallest = findSmallestLeaf(root->left);

    // Recursively find the smallest leaf in the right subtree
    struct Node* rightSmallest = findSmallestLeaf(root->right);

    // Compare the leaves from the left and right subtrees
    if (leftSmallest == NULL)
        return rightSmallest;
    if (rightSmallest == NULL)
        return leftSmallest;

    return (leftSmallest->data < rightSmallest->data) ? leftSmallest : rightSmallest;
}

int main() {
    // Sample BST creation
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(12);
    root->right->right = createNode(18);

    // Find the smallest leaf node
    struct Node* smallestLeaf = findSmallestLeaf(root);

    // Display the result
    if (smallestLeaf != NULL)
        printf("The smallest leaf node is: %d\n", smallestLeaf->data);
    else
        printf("The tree is empty.\n");

    return 0;
}
