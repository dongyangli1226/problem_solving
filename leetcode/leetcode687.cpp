//find longest univalue path
//path nodes have same value

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int longestUnivaluePath(TreeNode* root, int& res){
    if(root == NULL){
        return 0;
    }
    
    int left = longestUnivaluePath(root->left, res);
    int right = longestUnivaluePath(root->right, res);
    
    int leftPath=0, rightPath=0;
    if(root->left && root->left->val == root->val){
        leftPath = left+1;
    }
    if(root->right && root->right->val == root->val){
        rightPath = right + 1;
    }
    
    res = std::max(res, leftPath+rightPath);
    return std::max(leftPath, rightPath);
}

int longestUnivaluePath(TreeNode* root) {
    int res=0;
    longestUnivaluePath(root, res);
    return res;
}
