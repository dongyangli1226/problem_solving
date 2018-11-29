////find minimum in rotated sorted array II
// there are duplicates

#include <vector>

//binary search for the smallest one
int findMin(std::vector<int>& nums){
    int n = nums.size();

    int left = 0, right = n-1, mid;

    while(left < right){
        mid = (left + right)/2;

        if(nums[mid] > nums[right]){
            left = mid + 1;
        }
        else if(nums[mid] < nums[right]){
            right = mid;
        }
        else{ 
            // when nums[mid] == nums[right], we are not sure about which half contains the smallest number.
            // so just reduce right by 1

            right--;
        }
    }

    return nums[left];
}