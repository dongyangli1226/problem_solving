//construct binary tree from preorder and postorder traversal

#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(NULL), right(NULL){}
};

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& postorder, std::unordered_map<int, int>& post_map, int pre_start, int pre_end, int post_start, int post_end){
    if(pre_start>pre_end || post_start > post_end){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[pre_start]);
    if(pre_start == pre_end){
        return root;
    }

    int indexFoundPostorder = post_map[preorder[pre_start+1]];
    int len = indexFoundPostorder - post_start + 1;

    root->left = buildTree(preorder, postorder, post_map, pre_start+1, pre_start+len, post_start, indexFoundPostorder);
    root->right = buildTree(preorder, postorder, post_map, pre_start+len+1, pre_end, indexFoundPostorder+1, post_end-1);

    return root;
}

TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder){
    std::unordered_map<int, int> post_map;
    int n = postorder.size();

    for(int i=0; i<n; i++){
        post_map[postorder[i]] = i;
    }

    return buildTree(preorder, postorder, post_map, 0, n-1, 0, n-1);
}