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

void iterativePreorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct Stack* stack = createStack();
    push(stack, root);

    while (!isEmpty(stack)) {
        struct TreeNode* current = pop(stack);
        printf("%d ", current->val);

        if (current->right != NULL) {
            push(stack, current->right);
        }
        if (current->left != NULL) {
            push(stack, current->left);
        }
    }
}

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    iterativePreorder(root);
    printf("\n");

    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
