//sort colors
//put 0 on left, 1 in middle, 2 on the right side of array

#include <vector>

void sortColors(std::vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;

    for(int i=0; i<nums.size(); i++){
        if(nums[mid] == 1){
            mid++;
        }

        else if(nums[mid] == 0){
            std::swap(nums[low], nums[mid]);
            mid++;
            low++;
        }

        else if(nums[mid] == 2){
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

//furthur improve: we dont need mid index.
//just swap 0 with low , swap 2 with high

void sortColors(std::vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    for(int i=0; i<=high; i++){
        
        if(nums[i] == 0){
            std::swap(nums[low], nums[i]);
            low++;
        }

        else if(nums[i] == 2){
            std::swap(nums[i], nums[high]);
            high--;
            i--; //in case it is still 2 after swap
        }
    }
}