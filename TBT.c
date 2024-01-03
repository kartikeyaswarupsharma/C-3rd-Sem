#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int isLeftThreaded;  // Flag for left threading
    int isRightThreaded; // Flag for right threading
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->isLeftThreaded = 0;  // Initially, not threaded
    newNode->isRightThreaded = 0; // Initially, not threaded
    return newNode;
}

struct Node* leftmost(struct Node* node) {
    while (node != NULL && node->isLeftThreaded) {
        node = node->left;
    }
    return node;
}

struct Node* rightmost(struct Node* node) {
    while (node != NULL && node->isRightThreaded) {
        node = node->right;
    }
    return node;
}

void inOrderTraversal(struct Node* root) {
    struct Node* current = leftmost(root);

    while (current != NULL) {
        printf("%d ", current->data);

        if (current->isRightThreaded) {
            current = current->right;
        } else {
            current = leftmost(current->right);
        }
    }
}

void createThreads(struct Node* root, struct Node** prev) {
    if (root != NULL) {
        createThreads(root->left, prev);

        if (*prev != NULL) {
            // Make the current node's right pointer a thread
            if ((*prev)->right == NULL) {
                (*prev)->right = root;
                (*prev)->isRightThreaded = 1;
            }

            // Make the current node's left pointer a thread
            if (root->left == NULL) {
                root->left = *prev;
                root->isLeftThreaded = 1;
            }
        }

        // Update the previous pointer to the current node
        *prev = root;

        createThreads(root->right, prev);
    }
}

void inOrderThreadedTraversal(struct Node* root) {
    struct Node* prev = NULL;
    createThreads(root, &prev);

    // Reset the prev pointer for the actual traversal
    prev = NULL;
    inOrderTraversal(root);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("In-order threaded traversal: ");
    inOrderThreadedTraversal(root);

    return 0;
}
