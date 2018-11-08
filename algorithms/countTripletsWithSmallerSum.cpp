//Given an array and a sum value, find count of triplets that have sum smaller than given sum.
//similar to leetcode 3 Sum question, leetcode 15

#include <iostream>
#include <vector>
#include <algorithm>

int findTripletsWithSmallerSum(std::vector<int>& nums, int sum){
    sort(nums.begin(), nums.end());
    int count = 0;
    int current_sum;

    for(int i=0; i<nums.size(); i++){
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        int left = i+1;
        int right = nums.size()-1;

        while(left < right){
            current_sum = nums[i] + nums[left] + nums[right];

            if(current_sum >= sum){
                right--;
            }
            else{
                count += (right - left);
                left++;
            }
        }

    }
    return count;
}

int main(){
    std::vector<int> nums;
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(7);
    //nums.push_back(-4);

    int res = findTripletsWithSmallerSum(nums, 12);

    std::cout << res << std::endl;

}