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

    auto indexFoundFromInorder = std::find(inorder.begin()+in_start, inorder.begin()+in_end, preorder[pre_start]);
    int indexFoundInt = std::distance(inorder.begin(), indexFoundFromInorder);//transfer it to int
    
    int dist = indexFoundInt - in_start;
    pre_start++;

    root->left = buildHelper(pre_start, in_start, indexFoundInt-1, preorder, inorder);
    root->right = buildHelper(pre_start+dist, indexFoundInt+1, in_end, preorder, inorder);
    return root;
}

Node* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return buildHelper(0, 0, inorder.size()-1, preorder, inorder);
}


//Method2 Using hash table (unordered_map) to store inorder traversal
//In this way, the searching in inorder traversal will only take O(1)
//Time complexity: O(n)




//Method3 Using stack