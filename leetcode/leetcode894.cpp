//All possible full binary trees
//return a list of root nodes which are the roots for possible full binary trees
//all nodes have value 0

//number of nodes in left subtree i, number of nodes in right subtree n-i-1

#include <iostream>
#include <vector>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): val(val), left(NULL), right(NULL){}
};

//recursive method O(2^N) (dp - map)

std::unordered_map<int, std::vector<TreeNode*> > map;

std::vector<TreeNode*> allPossibleFBT(int N){
    std::vector<TreeNode*>& result = map[N];

    if(N <= 0){
        return result;
    }
/*
    if(N%2 == 0){ /// this can be removed since we will save the solution for allPossibleFBT(2), .. ... , (handled by if(map[N].size())
        return result;
    }
*/
    if(N == 1){
        result.push_back(new TreeNode(0));
        return result;
    }

    if(map[N].size()){ // avoid repeat doing N
        return map[N];
    }

    for(int i=1; i<N; i+=2){
        for(TreeNode* &l : allPossibleFBT(i)){
            for(TreeNode* &r : allPossibleFBT(N-i-1)){
                TreeNode* currentNode = new TreeNode(0);
                currentNode->left = l;
                currentNode->right = r;
                result.push_back(currentNode);
            }
        }
    }
    map[N] = result;

    return result;
}