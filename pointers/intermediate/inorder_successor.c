/*
Given a BST find its inorder successor 
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* GetNewNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


struct Node* Insert(struct Node* root,int data) {
    if (root == NULL) {
        return GetNewNode(data);
    }
    if (data <= root->data) {
        root->left = Insert(root->left, data);

    }
    else 
        root->right = Insert(root->right, data);
    return root;    
}


struct Node*  Find(struct Node* root,int data) {
    if (root == NULL) {
        return NULL;
    }    
    if (root->data == data) {
        return root;
    }

    else if (data < root->data) {
        return Find(root->left, data);
    }
    else 
        return Find(root->right, data);
}

struct Node* FindMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;        
}

struct Node* GetSuccessor(struct Node* root, int data) {
    // search the node 
    struct Node* current = Find(root, data);
    if (current == NULL) return NULL;
    // case1 Node has right subtree
    if (current->right != NULL) {
        return FindMin(current->right);
    }
    else {
        struct Node* successor = NULL;
        struct Node* ancestor = root;
        while (ancestor != current) {
            if(current->data < ancestor->data) {
                successor = ancestor;
                ancestor= ancestor->left;
            }
            else 
                ancestor = ancestor->right;
        }
        return successor;
    }
  
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

    struct Node* successor = GetSuccessor(root, 12);
    if (successor != NULL)
        printf("Inorder successor of 12 is %d\n",
               successor->data);
    else 
        printf("No successor found\n");
        

    return 0;


}