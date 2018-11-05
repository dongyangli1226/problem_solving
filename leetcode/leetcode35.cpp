//Search Insert Position

#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();

    //brute force
    /*
    for(int i=0; i<n; i++){
        if(nums[i] == target){
            return i;
        }
        if(nums[i] > target){
            return i;
        }
    }
    return n;
    */

   //binary search
   int l = 0, r = n - 1, mid;
   while(l<=r){
       mid = (l+r)/2;
       if(nums[mid] == target){
           return mid;
       }
       if(nums[mid] < target){
           l = mid+1;
       }
       else{
           r = mid-1;
       }
   }

   //l > r
   return l;



   
}