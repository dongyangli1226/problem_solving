//find minimum in rotated sorted array

#include <vector>

//binary search for the smallest one
int findMin(std::vector<int>& nums){
    int n = nums.size();
    
    int left = 0, right = n-1, mid;

    while(left < right){
        mid = (left+right)/2;

        if(nums[mid] > nums[right]){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }

    return nums[left];
}