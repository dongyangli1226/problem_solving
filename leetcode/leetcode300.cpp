//longest increasing subsequence
//[10,9,2,5,3,7,101,18], output:4 (2,3,7,101)

#include <vector>
#include <algorithm>

//DP O(n^2)
int lengthOfLIS(std::vector<int>& nums){
    if(nums.size() == 0){
        return 0;
    }

    std::vector<int> dp(nums.size(), 1);

    for(int i=1; i<nums.size(); i++){
        for(int j=0; j<i; j++){
            if(nums[i] > nums[j]){
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }

    return *(std::max_element(dp.begin(), dp.end()));
}

//O(nlogn) solution
