//maximum product subarray

#include <vector>

int maxProduct(std::vector<int>& nums) {
    std::vector<int> dp_max(nums.size());
    std::vector<int> dp_min(nums.size());

    dp_max[0] = nums[0]; //store max positive 
    dp_min[0] = nums[0]; //store min negative, since min negative * next negative would become big positive num

    int res = nums[0];

    for(int i=1; i<nums.size(); i++){
        dp_max[i] = std::max(std::max(nums[i], dp_max[i-1]*nums[i]), dp_min[i-1]*nums[i]);
        dp_min[i] = std::min(std::min(nums[i], dp_max[i-1]*nums[i]), dp_min[i-1]*nums[i]);

        res = std::max(res, dp_max[i]);
    }

    return res;

}