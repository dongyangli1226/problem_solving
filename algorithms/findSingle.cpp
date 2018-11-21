//find the element only appears once in given array
//all other elements appear twice

//algorithm from geeksforgeeks (best)
// number XOR 0 -> number itself
// number XOR number -> 0

#include <iostream>
#include <vector>

int findSingle(std::vector<int>& nums){
    int result = nums[0];
    for(int i=1; i<nums.size(); i++){
        result ^= nums[i];
    }
    return result;
}

int main(){
    std::vector<int> nums = {1, 1, 3, 5, 6, 5, 6};
    std::cout << findSingle(nums) << std::endl;

    return 0;
}