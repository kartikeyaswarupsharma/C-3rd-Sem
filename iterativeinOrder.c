#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct StackNode {
    struct TreeNode* treeNode;
    struct StackNode* next;
};


struct Stack {
    struct StackNode* top;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

void push(struct Stack* stack, struct TreeNode* treeNode) {
    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->treeNode = treeNode;
    newNode->next = stack->top;
    stack->top = newNode;
}

struct TreeNode* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    struct StackNode* temp = stack->top;
    stack->top = stack->top->next;
    struct TreeNode* popped = temp->treeNode;
    free(temp);
    return popped;
}

void iterativeInorder(struct TreeNode* root) {
    struct Stack* stack = createStack();
    struct TreeNode* current = root;

    while (current != NULL || !isEmpty(stack)) {

        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->val);

        current = current->right;
    }
}

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

    printf("Iterative Inorder Traversal: ");
    iterativeInorder(root);
    printf("\n");

    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
