// find minimum right 
// copy the value in targeted node 
// Delete the duplicate from right subtree.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



struct Node {

    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* GetNewNode(int data) {
    struct Node* newNode = 
        (struct Node*)malloc(sizeof(struct Node));

        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
}

struct Node* FindMin(struct Node* root) {
    while(root->left != NULL) { 
        root = root->left;
    }

    return root;
}

struct Node* Insert(struct Node* root, int data) {
    if (root == NULL)
        return GetNewNode(data);
    if (data <= root->data) {
        root->left = Insert(root->left, data);
    }   
    else 
        root->right = Insert(root->right, data);
    return root;     
}

struct Node* Delete(struct Node* root, int data) {
    if (root == NULL) return root;
    else if (data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);

    else {

        // no child
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
            return root;
        }

        // One right child
        else if (root->left == NULL) {
            struct Node *temp = root;
            root = root->right;
            free(temp);
            return root;

        }

        // One left child
        
        else if (root->right == NULL) {
            struct Node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        // Two children
        else {
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Inorder(struct Node* root) {
    if (root == NULL) 
        return;
    Inorder(root->left);
    
    printf("%d\n", root->data);

    Inorder(root->right);
}
int main() {
    struct Node* root = NULL;

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 8);
    root = Insert(root, 12);
    root = Insert(root, 17);
    root = Insert(root, 25);
    
    printf("Before deletion:\n");
    Inorder(root);

    root = Delete(root, 20);
    printf("\n\nAfter deletion\n");

    Inorder(root);
    printf("\n");


    return 0;

}