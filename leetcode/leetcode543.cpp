//Diameter of binary tree

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int diameterOfBinaryTree(TreeNode* root, int& res){
    if(root == NULL){
        return 0;
    }
    
    int leftPath = diameterOfBinaryTree(root->left, res);
    int rightPath = diameterOfBinaryTree(root->right, res);

    res = std::max(leftPath+rightPath, res);
    return std::max(leftPath, rightPath) + 1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int res=0;
    diameterOfBinaryTree(root, res);
    return res;
}