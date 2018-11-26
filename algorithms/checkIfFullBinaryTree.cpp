// a full binary tree: each node has no child or two children
// similar leetcode 894

#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): val(val), left(NULL), right(NULL){}
};

bool isFullBinaryTree(TreeNode* root){
    if(root == NULL){
        return true;
    }

    if(!root->left && !root->right){
        return true;
    }

    if(root->left && root->right){
        return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
    }

    return false;
}

int main(){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    //root->right = new TreeNode(3);

    std::cout << isFullBinaryTree(root) << std::endl;
    return 0;
}