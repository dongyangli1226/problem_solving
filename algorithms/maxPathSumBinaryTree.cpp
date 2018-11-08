//Find the maximum path sum.
//The path may start and end at any node in the tree.
//leetcode 124. similar leetcode 543, 687

#include <iostream>
#include <climits>

struct Node{
    Node* left;
    Node* right;
    int value;
};

Node* newNode(int value){
    Node* n = new Node();
    n->left = NULL;
    n->right = NULL;
    n->value = value;
    return n;
}

//bottom up
int findMaxPath(Node* root, int& res){
    if (root == NULL){
        return 0;
    }

    //only four paths:
    //1. node only
    //2. left - node
    //3. node - right
    //4. left - node -right

    int leftPath = std::max(0, findMaxPath(root->left, res));
    int rightPath = std::max(0, findMaxPath(root->right, res));

    int sum = leftPath + rightPath + root->value;

    res = std::max(sum, res);

    return std::max(leftPath, rightPath) + root->value; //bottom up, left sub - root - right sub, can only choose one path


}

int findMaxPath(Node* root){
    int res=INT_MIN;
    findMaxPath(root, res);
    return res;
}

int main(){
    Node *root = newNode(10); 
    root->left        = newNode(2); 
    root->right       = newNode(10); 
    root->left->left  = newNode(20); 
    root->left->right = newNode(1); 
    root->right->right = newNode(-25); 
    root->right->right->left   = newNode(3); 
    root->right->right->right  = newNode(4); 
    std::cout << "Max path sum is " << findMaxPath(root) << std::endl;; 
    return 0; 
}

