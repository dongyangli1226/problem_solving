//https://www.geeksforgeeks.org/longest-consecutive-sequence-binary-tree/
//Given a Binary Tree find the length of the longest path which comprises of nodes with consecutive values in increasing order.
//Every node is considered as a path of length 1.

#include <iostream>

struct Node{
    Node * left;
    Node * right;
    int value;
};

void maxSequence(Node* root, int expected, int current_length, int& result){
    if(root == NULL){
        return;
    }
    
    if(expected == root->value){
        current_length++;
    }
    else{
        current_length = 1;
    }

    result = std::max(result, current_length);

    maxSequence(root->left, root->value+1, current_length, result);
    maxSequence(root->right, root->value+1, current_length, result);
}

int maxSequence(Node* root){
    if(root == NULL){
        return 0;
    }
    int result = 0;
    maxSequence(root, root->value, 0, result);

    return result;
}

int main(){
    Node* root = new Node();
    root->value = 4;
    root->left = new Node();
    root->right = new Node();
    root->left->value = 5;
    root->right->value = 6;
    //root->left->left = new Node();
    //root->left->left->value = 6;
    //root->left->left->left = new Node();
    //root->left->left->left->value = 7;

    root->right->right = new Node();
    root->right->right->value = 7;
    root->right->right->right = new Node();
    root->right->right->right->value = 8;

    std::cout << maxSequence(root) << std::endl;
}