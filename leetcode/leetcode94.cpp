//binary tree inorder traversal

#include <iostream>
#include <vector>

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
};

void inOrder(TreeNode* root, std::vector<int>& res){
    if(root == NULL) return;
    
    inOrder(root->left,res);
    
    res.push_back(root->val);
    
    inOrder(root->right, res);
}

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> res;
    inOrder(root, res);
    return res;
}