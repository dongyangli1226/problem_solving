//construct binary tree from given inorder and postorder traversal

#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder, std::unordered_map<int,int>& in_map, int post_start, int in_start, int in_end){
    if(post_start < 0 || in_start > in_end){
        return NULL;
    }

    TreeNode* root = new TreeNode(postorder[post_start]);

    int indexFoundInorder = in_map[postorder[post_start]];
    post_start--;

    root->left = buildTree(inorder, postorder, in_map, post_start-(in_end-indexFoundInorder), in_start, indexFoundInorder-1);
    root->right = buildTree(inorder, postorder, in_map, post_start, indexFoundInorder+1, in_end);

    return root;
}

TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder){
    int n = inorder.size();
    std::unordered_map<int, int> in_map;
    for(int i=0; i<n; i++){
        in_map[inorder[i]] = i;
    }

    return buildTree(inorder, postorder, in_map, n-1, 0, n-1);
    
}