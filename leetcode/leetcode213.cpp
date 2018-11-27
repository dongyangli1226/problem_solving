//House robber II
//since house 1 and house n-1 are adjacent now
//split this into two house robber problem
//1 to n-2
//2 to n-1
#include <vector>

int robSolution(std::vector<int>& nums, int left, int right){
    int dp[nums.size()];
    dp[left] = nums[left];
    dp[left+1] = std::max(dp[left], nums[left+1]);

    for(int i=left+2; i<=right; i++){
        dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
    }

    return dp[right];
}

int rob(std::vector<int>& nums){
    if(nums.size() == 0){
        return 0;
    }

    if(nums.size() == 1){
        return nums[0];
    }
    
    if(nums.size() == 2){
        return std::max(nums[0], nums[1]);
    }

    return std::max(robSolution(nums, 0, nums.size()-2), robSolution(nums, 1, nums.size()-1));
}