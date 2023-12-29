#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
} node;

node* insertNode(node* root, int data) {
    if (root == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            // Handle memory allocation failure
            return NULL;
        }
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
        return newNode;
    }

    if (data < root->data) {
        if (root->left == NULL) {
            root->left = (node*)malloc(sizeof(node));
            if (root->left == NULL) {
                // Handle memory allocation failure
                return NULL;
            }
            root->left->data = data;
            root->left->left = NULL;
            root->left->right = NULL;
            root->left->parent = root;
        } else {
            root->left = insertNode(root->left, data);
        }
    } else {
        if (root->right == NULL) {
            root->right = (node*)malloc(sizeof(node));
            if (root->right == NULL) {
                // Handle memory allocation failure
                return NULL;
            }
            root->right->data = data;
            root->right->left = NULL;
            root->right->right = NULL;
            root->right->parent = root;
        } else {
            root->right = insertNode(root->right, data);
        }
    }
    return root;
}


void logInorder(node* root) {
    if (root->left != NULL) {
        logInorder(root->left);
    }
    printf("%d ", root->data);
    if (root->right != NULL) {
        logInorder(root->right);
    }
}

void logPreorder(node* root) {
    if (root == NULL) {
        return;  // Return immediately if root is null
    }
    printf("%d ", root->data);  // Print the root's data
    logPreorder(root->left);     // Traverse the left subtree
    logPreorder(root->right);    // Traverse the right subtree
}

void logPostorder(node* root) {
    if (root->left != NULL) {
        logPostorder(root->left);
    }
    if (root->right != NULL) {
        logPostorder(root->right);
    }
    printf("%d ", root->data);
}

int max(int a, int b){
    if(a<=b){
        return b;
    }else{
        return a;
    }
}

int treeHeight(node * root){
    if(root == NULL) // Do not exist
        return 0;
    int height = max(treeHeight(root->left), treeHeight(root->right));
    return 1+height;
}

void showTree(node* root) {
    
    
}

int main() {
    node* root = NULL;
    int data[] = {50, 30, 70, 20, 40, 60, 80};  // Adjusted order for a more balanced tree

    for (int i = 0; i < 7; i++) {
        root = insertNode(root, data[i]);
    }
    // print in order
    printf("inorder : ");
    logInorder(root);
    printf("\n");

    printf("preorder : ");
    logPreorder(root);
    printf("\n");

    printf("postorder : ");
    logPostorder(root);
    printf("\n");

    printf("tree : ");
    // showTree(root);
    printf("height : %d\n", treeHeight(root));

    return 0;
}