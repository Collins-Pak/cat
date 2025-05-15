#include <stdio.h>
#include <stdlib.h>

// Define binary tree node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count number of nodes in a tree
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to print tree (in-order traversal)
void printTree(struct Node* root) {
    if (root == NULL) return;
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}

// Function to compare three trees and print the one with the highest node count
void compareBinaryTree(struct Node* A, struct Node* B, struct Node* C) {
    int countA = countNodes(A);
    int countB = countNodes(B);
    int countC = countNodes(C);

    printf("Node count: Tree A = %d, Tree B = %d, Tree C = %d\n", countA, countB, countC);

    if (countA >= countB && countA >= countC) {
        printf("Tree A has the highest number of nodes:\n");
        printTree(A);
    } else if (countB >= countA && countB >= countC) {
        printf("Tree B has the highest number of nodes:\n");
        printTree(B);
    } else {
        printf("Tree C has the highest number of nodes:\n");
        printTree(C);
    }
    printf("\n");
}

// Main function to test
int main() {
    // Creating Tree A
    struct Node* A = createNode(10);
    A->left = createNode(5);
    A->right = createNode(15);

    // Creating Tree B
    struct Node* B = createNode(20);
    B->left = createNode(10);
    B->right = createNode(30);
    B->left->left = createNode(5);

    // Creating Tree C
    struct Node* C = createNode(1);
    C->left = createNode(2);
    C->right = createNode(3);
    C->left->left = createNode(4);
    C->left->right = createNode(5);
    C->right->left = createNode(6);

    // Compare the trees
    compareBinaryTree(A, B, C);

    return 0;
}
