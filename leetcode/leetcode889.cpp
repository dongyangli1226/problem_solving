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

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& postorder, std::unordered_map<int, int>& post_map, int pre_start){
    if(pre_start > preorder.size()-1){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[pre_start]);
    int indexFoundPostorder = post_map[preorder[pre_start]];

}

TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& postorder){
    std::unordered_map<int, int> post_map;
    for(int i=0; i<postorder.size(); i++){
        post_map[postorder[i]] = i;
    }

    return buildTree(preorder, postorder, post_map, 0);
}