#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node * createnode(int data){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int height(struct node * root){
    if(root==NULL){
        return 0;
    }else{
        int leftHeigth = height(root->left);
        int rightHeigth = height(root->right);

        return (leftHeigth > rightHeigth) ? (leftHeigth +1) : (rightHeigth +1);
    }

}
int main(){
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
    struct node *p5 = createnode(7);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p3->left = p5;
    
    printf("The heigth of thr binary search tree is : %d",height(p));

    return 0;
}