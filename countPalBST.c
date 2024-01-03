#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
bool isPalindrome(int num) {
    int original = num;
    int reversed = 0;

    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed;
}


void countPalindromes(struct TreeNode* root, int* count) {
    if (root == NULL) {
        return;
    }
    countPalindromes(root->left, count);
    if (isPalindrome(root->val)) {
        (*count)++;
    }
    countPalindromes(root->right, count);
}
int countPalindromeNumbers(struct TreeNode* root) {
    int count = 0;
    countPalindromes(root, &count);
    return count;
}


struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    // Example usage:
    // Construct a BST
    //        121
    //       /   \
    //      22    131
    //     / \     / \
    //    11  33  121  44
    struct TreeNode* root = createNode(121);
    root->left = createNode(22);
    root->right = createNode(131);
    root->left->left = createNode(11);
    root->left->right = createNode(33);
    root->right->left = createNode(121);
    root->right->right = createNode(44);

    int palindromeCount = countPalindromeNumbers(root);
    printf("Number of palindrome numbers in the BST: %d\n", palindromeCount);

    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root);

    return 0;
}
