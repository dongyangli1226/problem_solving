//Given a pivot x, and a list lst, partition the list into three parts.

//The first part contains all elemenets in lst that are less than x
//The first part contains all elemenets in lst that are equal to x
//The first part contains all elemenets in lst that are larger than x
//Ordering within a part can be arbitrary.
//For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14]

//similar partition question leetcode 86, 75

#include <iostream>
#include <vector>

void partitionList(std::vector<int>& nums, int x){
    /*
    int left=0, right = nums.size()-1;
    int firstIndexGreaterX;

    //move all x to the end of list
    while(left<right){
        if(nums[right] == x){
            right--;
        }
        if(nums[left] != x){
            left++;
        }

        if(left<right && nums[left] == x && nums[right] !=x){
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    //partition subarray before x
    left = 0;
    right = nums[right]==x? right-1:right;

    while(left<right){
        if(nums[left] < x){
            left++;
        }
        if(nums[right] > x){
            right--;
        }

        if(left<right && nums[left] > x && nums[right] < x){
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    if(nums[left] < x){
        firstIndexGreaterX = left+1;
    }
    else{
        firstIndexGreaterX = left;
    }

    //swap all x
    right = nums.size()-1;
    while(firstIndexGreaterX<right){
        std::swap(nums[firstIndexGreaterX], nums[right]);
        firstIndexGreaterX++;
        right--;
    }
    */

    //more effecient approach
    //only one loop
    int low = 0, high = nums.size()-1;

    for(int i=0; i<=high; i++){
        if(nums[i] < x){
            std::swap(nums[i], nums[low]);
            low++;
        }
        else if(nums[i] > x){
            std::swap(nums[i], nums[high]);
            high--;
            i--; // in case it is still greater than x after swap
        }
    }

}

int main(){
    //std::vector<int> nums = {9, 14, 10};
    //std::vector<int> nums = {14, 10};
    //std::vector<int> nums = {15, 9, 14, 10, 5, 10, 2, 10, 10, 10, 10};
    //std::vector<int> nums = {15, 9, 14, 2, 5};
    std::vector<int> nums = {10, 10, 15, 2, 10};
    partitionList(nums, 10);

    for(int i=0; i<nums.size(); i++){
        std::cout << nums[i] << std::endl;
    }

    return 0;
}