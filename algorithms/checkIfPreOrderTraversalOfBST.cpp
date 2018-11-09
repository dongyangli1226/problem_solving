//check if given array can represent a preorder traversal of a BST
//efficient way : use stack 

//(similar to 'Next (or closest) Greater Element problem')

/*algorithm from Geeksforgeeks
1) Create an empty stack.
2) Initialize root as INT_MIN.
3) Do following for every element pre[i]
     a) If pre[i] is smaller than current root, return false.
     b) Keep removing elements from stack while pre[i] is greater
        then stack top. Make the last removed item as new root (to
        be compared next).
        At this point, pre[i] is greater than the removed root
        (That is why if we see a smaller element in step a), we 
        return false)
     c) push pre[i] to stack (All elements in stack are in decreasing
        order)
        */
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

struct Node{
    Node* left;
    Node* right;
    int val;
};

Node* newNode(int val){
    Node* node = new Node();
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    return node;
}

bool checkPreOrderTraversalOfBST(std::vector<int>& nums){
    std::stack<int> s;

    int current_root = INT_MIN;

    for(int i=0; i<nums.size(); i++){
        if(nums[i] < current_root){
            return false;
        }

        while(!s.empty() && nums[i] > s.top()){
            current_root = s.top();
            s.pop();
        }

        s.push(nums[i]);

    }

    return true;
}

int main(){

    std::vector<int> pre = {2,4,2,5};
    if(checkPreOrderTraversalOfBST(pre)){
        std::cout << "true" << std::endl;
    }
    else{
        std::cout << "false" << std::endl;
    }

    return 0;
}