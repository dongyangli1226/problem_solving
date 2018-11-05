//Maximum Subarray

//Kadane's algorithm

#include <vector>

int maxSubarray(std::vector<int>& nums){
    int ans=nums[0],i,sum=0;
    for(i=0;i<nums.size();i++){
        sum+=nums[i];
        ans=std::max(sum,ans);
        if(sum < 0){
            sum = 0;
        }
    }
    return ans;
}