//construct binary tree from preorder and inorder traversal

#include <iostream>
#include <vector>
#include <algorithm>

struct Node{
    Node* left;
    Node* right;
    int val;
};

Node* newNode(int val){
    Node* temp = new Node();
    temp->left = NULL;
    temp->right = NULL;
    temp->val = val;
    return temp;
}

Node* buildHelper(int pre_start, int in_start, int in_end, std::vector<int>& preorder, std::vector<int>& inorder){
    if(pre_start > preorder.size()-1 || in_start > in_end){
        return NULL;
    }

    Node* root = newNode(preorder[pre_start]);

    int indexFoundFromInorder = std::find(inorder.begin()+in_start, inorder.begin()+in_end, preorder[pre_start]) - inorder.begin();//-inorder.begin() transfer it to int
    
    int dist = indexFoundFromInorder - in_start;
    pre_start++;

    root->left = buildHelper(pre_start, in_start, indexFoundFromInorder-1, preorder, inorder);
    root->right = buildHelper(pre_start+dist, indexFoundFromInorder+1, in_end, preorder, inorder);
    return root;
}

Node* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return buildHelper(0, 0, inorder.size()-1, preorder, inorder);
}