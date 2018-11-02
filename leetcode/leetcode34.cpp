//Find first and last position of element in sorted array
//two binary search:
//search the first position and last position

//If A[mid] < target, i = mid+1
//If A[mid] > target, j = mid-1
//If A[mid] = target, j= mid
//the first position: when equals to target then first should be on the left

//If A[mid] > target, j = mid-1
//If A[mid] < target, i = mid+1
//If A[mid] = target, i= mid
//seconde position: when equals to target then seconde should be on the right
#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> res(2, -1);

    if(n==0){
        return res;
    }
    
    int i=0, j=n-1, mid;
    //the first loop to find the first position
    while (i<j){
        mid = (i+j)/2;
        if(nums[mid] < target){
            i = mid + 1;
        }
        else{ //when nums[mid] >= target
            j = mid;
        }
    }

    if(nums[i] != target){
        return res;
    }
    else{
        res[0] = i;
    }

    //no need to initialize i to 0
    j = n-1;
    while(i<j){
        mid = (i+j)/2 + 1;
        if(nums[mid] > target){
            j = mid -1;
        }
        else{ // when nums[mid] <= target
            i = mid;
        }
    }

    res[1] = j;
    return res;
}

int main(){
    vector<int> nums = {1,2,3,3,5,7,9};
    vector<int> res = searchRange(nums, 3);
    cout << res[0] << "," << res[1] << endl;
}