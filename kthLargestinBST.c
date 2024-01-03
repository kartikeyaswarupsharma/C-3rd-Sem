#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find the kth largest element in a BST using constant extra space.
int kthLargest(struct TreeNode* root, int k) {
    int count = 0;
    int result = -1;

    while (root != NULL) {
        if (root->right == NULL) {
            // If there is no right subtree, process the current node.
            if (++count == k) {
                result = root->val;
                break;
            }
            root = root->left;
        } else {
            // Find the predecessor in the inorder traversal.
            struct TreeNode* predecessor = root->right;
            while (predecessor->left != NULL && predecessor->left != root) {
                predecessor = predecessor->left;
            }

            if (predecessor->left == NULL) {
                // Set the link from predecessor to root.
                predecessor->left = root;
                root = root->right;
            } else {
                // Revert the changes made to the tree and process the current node.
                predecessor->left = NULL;
                if (++count == k) {
                    result = root->val;
                    break;
                }
                root = root->left;
            }
        }
    }

    return result;
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
    // Construct a BST
    //        10
    //       /  \
    //      5   15
    //     / \    \
    //    3   7    20
    struct TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->right = createNode(20);

    int k = 3;
    int result = kthLargest(root, k);
    printf("The %dth largest element is: %d\n", k, result);

    // Don't forget to free the allocated memory
    // (This is a simplified example; in a real application, you may want to implement a proper memory deallocation function.)
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right->right);
    free(root->right);
    free(root);

    return 0;
}
