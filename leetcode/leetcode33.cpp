//Search in Rotated Sorted Array (binary search)
//must O(log n)
//return index of target, return -1 if not found

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target){
    int n = nums.size();
    if(nums.empty()){
        return -1;
    }
    //find smallest number
    int left=0, right=n-1, mid;

    while(left < right){
        mid = (left + right)/2;
        if(nums[mid]>nums[right]){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }

/*
    //first approach after finding smallest number
    //perform binary search accounting for rotated positions
    //left = right = number of positions rotated
    int rotate = left;
    int realMid;
    left = 0;
    right = n-1;
    while(left <= right){
        mid = (left + right)/2;
        realMid = (mid+rotate)%n;
        if(nums[realMid] == target){
            return realMid;
        }
        if(nums[realMid] < target){
            left = mid + 1;
        }
        if(nums[realMid] > target){
            right = mid - 1;
        }
    }
    */

    //second approach after finding the smallest number 
    //improve the first method, by only doing binary search for the correct interval
    if(target <= nums[n-1]){
        right = n-1;
    }
    else{
        left = 0;
    }
    while(left <= right){
        mid = (left + right)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid] < target){
            left = mid + 1;
        }
        if(nums[mid] > target){
            right = mid - 1;
        }
    }
    
    return -1;
}

int main(){
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << search(nums, 0) << endl;

    return 0;
}