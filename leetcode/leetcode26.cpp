//remove duplicate from sorted array, return length of result array
//space O(1), do not create another array or map
//similar to moveAllZeroTEndOfArray

#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums){
    int dup_start = 0;

    if (nums.size() == 0){
        return 0;
    }

    for(int i=1; i<nums.size(); i++){
        if(nums[i] != nums[dup_start]){
            dup_start++;
            nums[dup_start] = nums[i];
        }
    }

    return dup_start+1;
}

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    cout << removeDuplicates(nums) << endl;
}