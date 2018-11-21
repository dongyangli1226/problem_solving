//First Missing Positive
//Given an unsorted array, find the smallest missing positive integer

#include <iostream>
#include <vector>

int firstMissingPositive(std::vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        //once an element is swapped to the right place, it will not swap again
        //so each element will eventually swap once
        while(nums[i] < nums.size()+1 && nums[i] > 0 && nums[i] != nums[nums[i]-1]){
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }

    for(int i=0; i<nums.size(); i++){
       if(nums[i] != i+1){
           return i+1;
       }
    }

    return nums.size()+1;
}

int main(){
    //std::vector<int> nums = {1,3,6};
    //std::vector<int> nums = {3,6};
    std::vector<int> nums = {1,-3,-6};

    std::cout << firstMissingPositive(nums) << std::endl;

    return 0;
}