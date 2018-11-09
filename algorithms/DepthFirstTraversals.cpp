//Depth first traversal
//inorder (left-root-right)
//preorder (root-left-right)
//postorder (left-right-root)

#include <iostream>

struct Node{
    Node* left;
    Node* right;
    int val;
};

//inorder
// - traverse the left
// - root
// - traverse the right subtree
//if BST(binary search tree), returns non-decreasing order.
//if you want to print BST non-increasing order, then reverse inorder traversal.
void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);

    std::cout<< root->val << std::endl;

    inOrder(root->right);
}

//preorder
// - root
// - traverse the left
// - traverse the right
//usage: copy of a tree, prefix expression (expression tree)
void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    std::cout << root->val << std::endl;

    preOrder(root->left);

    preOrder(root->right);
}

//postorder
// - traverse the left
// - traverse the right
// - root
//usage: delete a tree, postfix expression
void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);

    postOrder(root->right);

    std::cout << root->val << std::endl;
}