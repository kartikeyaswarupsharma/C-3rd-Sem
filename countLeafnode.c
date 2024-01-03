#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to count leaf nodes in a binary tree.
int countLeafNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        // Node is a leaf.
        return 1;
    } else {
        // Recursively count leaf nodes in the left and right subtrees.
        return countLeafNodes(root->left) + countLeafNodes(root->right);
    }
}

// Helper function to create a new tree node.
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    // Example usage:
    // Construct a binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes in the binary tree: %d\n", leafCount);

    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
