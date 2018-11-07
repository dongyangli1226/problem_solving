//find minimum depth of binary tree

#include <iostream>
#include <queue>

struct Node{
    Node* left;
    Node* right;
    int value;
};

Node *newNode(int data){
    Node* n = new Node();
    n->left = NULL;
    n->right = NULL;
    n->value = data;
    return n;
}

//traversal the whole tree
int minDepth(Node* root){

    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 1;
    }

    if(!root->left){
        return minDepth(root->right) + 1;
    }

    if(!root->right){
        return minDepth(root->left) + 1;
    }

    return std::min(minDepth(root->left), minDepth(root->right)) + 1;
}

//better solution: level order traversal , or breadth first traversal

/*GeeksforGeeks
printLevelorder(tree)
1) Create an empty queue q
2) temp_node = root  //start from root
3) Loop while temp_node is not NULL // queue is not empty
    a) print temp_node->data.
    b) Enqueue temp_node’s children (first left then right children) to q
    c) Dequeue a node from q and assign it’s value to temp_node

*/

struct queueItem{
    Node* node;
    int depth;
};

int minDepthLevelOrderTraversal(Node* root){
    if(root == NULL){
        return 0;
    }

    queueItem qItem = {root, 1};
    std::queue<queueItem> q;
    q.push(qItem);

    int depth;
    Node* node;

    while(!q.empty()){
        qItem = q.front();
        depth = qItem.depth;
        node = qItem.node;
        q.pop();

        if(node->left == NULL && node->right == NULL){
            return depth;
        }

        if(node->left != NULL){
            qItem.node = node->left;
            qItem.depth = depth+1;
            q.push(qItem);
        }

        if(node->right != NULL){
            qItem.node = node->right;
            qItem.depth = depth+1;
            q.push(qItem);
        }
    }

    return 0;

}

int main(){
    Node *root        = newNode(1); 
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(5); 
    std::cout << minDepth(root) << std::endl; 
    std::cout << minDepthLevelOrderTraversal(root) << std::endl;
    return 0;
}