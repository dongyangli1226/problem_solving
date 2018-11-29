//majority element
//assume there always exists majority element

#include <vector>
#include <unordered_map>

//hash table
int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> map;
    for(int i=0; i<nums.size(); i++){
        map[nums[i]]++;
        if(map[nums[i]] > nums.size()/2){
            return nums[i];
        }
    }
}



//fast method

int majorityElement(std::vector<int>& nums){
    
    int major = nums[0], count = 1;
        
    for(int i = 1; i<nums.size(); ++i){
        if(count==0){
            major = nums[i];
            ++count;
        }else if(nums[i]==major)
            ++count;
        else
            --count;
    }
    
    return major;
}