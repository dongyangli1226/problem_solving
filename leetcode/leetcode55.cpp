//Jump Game
//find out if we can reach the last index

#include <vector>

bool canJump(std::vector<int>& nums){
    int lastPosition = nums.size()-1;
    for(int i = nums.size()-1; i>=0; i--){
        if(nums[i] + i >= lastPosition){
            lastPosition = i;
        }
    }
    return lastPosition == 0;
}