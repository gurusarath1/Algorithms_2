#include <stdio.h>
#include <stdlib.h>

struct node  {
    int val;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct node* findMin(struct node* node);
struct node* findNext(struct node* node);
void printSorted(struct node* head);

int main() {

    struct node root;

    root.val = 10;
    root.left = (struct node*) malloc(sizeof(struct node));
    root.right = (struct node*) malloc(sizeof(struct node));
    root.parent = NULL;

    root.left->val = 5;
    root.left->left = (struct node*) malloc(sizeof(struct node));
    root.left->right = (struct node*) malloc(sizeof(struct node));
    root.left->parent = &root;



    root.left->left->val = 2;
    root.left->left->left = NULL;
    root.left->left->right = NULL;
    root.left->left->parent = root.left;

    root.left->right->val = 6;
    root.left->right->left = NULL;
    root.left->right->right = NULL;
    root.left->right->parent = root.left;


    root.right->val = 15;
    root.right->left = (struct node*) malloc(sizeof(struct node));
    root.right->right = (struct node*) malloc(sizeof(struct node));
    root.right->parent = &root;


    root.right->left->val = 11;
    root.right->left->left = NULL;
    root.right->left->right = NULL;
    root.right->left->parent = root.right;

    root.right->right->val = 17;
    root.right->right->left = NULL;
    root.right->right->right = NULL;
    root.right->right->parent = root.right;

    // ----------------------------------------------------------------------

    printSorted(&root);

    return 0;
}

struct node* findMin(struct node* node) {

    while(node != NULL) {
        if(node->left != NULL) {
            node = node->left;
        } else {
            return node;
        }
    }

    return node;
}

struct node* findNext(struct node* node) {

    struct node* nextNode;

    if(node->right != NULL) {

        return findMin(node->right);

    }

    struct node* current_node = node->parent;
    while(current_node != NULL) {

        if(current_node->val >= node->val) {
            return current_node;
        } else {
            current_node = current_node->parent;
        }

    }

    return NULL;
}

void printSorted(struct node* head) {

    struct node* next = findMin(head);;

    if(next == NULL) return;

    do {
        printf("%d ", next->val);
        next = findNext(next);

    } while(next != NULL);

}
