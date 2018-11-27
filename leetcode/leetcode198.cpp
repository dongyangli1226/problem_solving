//house robber
/*

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

//bottom up
//two choice: rob current one and previous previous one or rob previous one
// i, i-2 or i-1
#include <vector>

int rob(std::vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }

    int pre1=0;
    int pre2=0;

    for(int i=0; i<nums.size(); i++){
        int temp = pre1;
        pre1 = std::max(nums[i]+pre2, pre1);
        pre2 = temp;
    }

    return pre1;
}

//my solution
int rob(std::vector<int>& nums){
    if(nums.size() == 0){
        return 0;
    }

    if(nums.size() == 1){
        return nums[0];
    }

    int dp[nums.size()];
    dp[0] = nums[0];
    dp[1] = std::max(dp[0], nums[1]);

    for(int i=2; i<nums.size(); i++){
        dp[i] = std::max(dp[i-2] + nums[i], dp[i-1]);
    }

    return dp[nums.size()-1];
}