//Next permutation
//rearranges numbers into the lexicographically next greater permutation of numbers

//e.g 1234->1243, 321->123, 115->151, 132->213, 1243->1324
//1. find the largest index that nums[i] < nums[i+1]
//2. find the largest index that nums[j] > nums[i]
//3. swap nums[i] and nums[j] and reverse subarray after i

//algorithm from:
//https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int index = -1;
    int n = nums.size();

    for(int i=0; i<n; i++){
        if(nums[i] < nums[i+1]){
            index = i;
        }
    }

    if(index == -1){
        reverse(nums.begin(), nums.end());
    }
    else{
        int largestIndexOfLargerElement = index;
        for(int i=index+1; i<n; i++){
            if(nums[i] > nums[index]){
                largestIndexOfLargerElement = i;
            }
        }

        swap(nums[index], nums[largestIndexOfLargerElement]);

        reverse(nums.begin()+index+1, nums.end());
    }
}

int main(){
    vector<int> nums = {2,1,3};
    nextPermutation(nums);

    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ',';
    }

    cout << endl;
}