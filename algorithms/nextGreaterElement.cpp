//given an array, output next greater element for each item in array
// if no next greater element, print -1 for that element

/* algorithm from geeksforgeeks

1) Push the first element to stack.
2) Pick rest of the elements one by one and follow following steps in loop.
….a) Mark the current element as next.
….b) If stack is not empty, then pop an element from stack and compare it with next.
….c) If next is greater than the popped element, then next is the next greater element for the popped element.
….d) Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.

O(n)
*/
#include <iostream>
#include <vector>
#include <stack>

void printNextGreater(std::vector<int>& nums){ // not print the same order as nums
    std::stack<int> s;
    s.push(nums[0]);
    int next;

    for(int i=1; i<nums.size(); i++){
        next = nums[i];

        if(s.empty()){
           s.push(next);
           continue; 
        }

        while(!s.empty() && next > s.top()){
            std::cout << s.top() << ',' << next << std::endl;
            s.pop();
        }

        s.push(nums[i]);
    }

    while(!s.empty()){
        std::cout << s.top() << ',' << -1 << std::endl;
        s.pop();
    }
}

//if we want to print in the same order as nums:
//create a map and store each next greater
//in the end, iterate  nums[i] --->  map[nums[i]]

int main(){
    std::vector<int> nums = {5,4,3,2,1};
    printNextGreater(nums);
    return 0;
}