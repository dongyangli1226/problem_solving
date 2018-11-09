//Verify preorder serialization of a binary tree
//One way to serialize a binary tree is to use pre-order traversal.
//When we encounter a non-null node, we record the node's value.
//If it is a null node, we record using a sentinel value such as #.


//Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
//Output: true

//initialize a tree capacity =1 , go through the array
//a node reduce capacity by 1
//a node which is not NULL(#) increase capacity by 2 (because it will add two leaves to the tree)
//in the end, if capacity is 0, return true

///"9,#,92,#,#"

#include <iostream>
#include <vector>

bool isValidSerialization(std::string preorder) {

    int capacity = 1;
    int n=preorder.size();
    
    if(preorder[n-1] != '#'){//speed up
        return false;
    }

    for(int i=0; i<n; i++){
        
        if(preorder[i] == ','){
            continue;
        }
        else if(preorder[i] == '#'){
            capacity--;
        }
        else{
            if(i<n-1 && preorder[i+1] != ',' && preorder[i+1] != '#'){
                continue;
            }
            capacity--;
            
            if(capacity<0){
                return false;
            }
            capacity += 2;
        }
    }

    return capacity==0;
}