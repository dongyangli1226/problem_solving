//Given a pivot x, and a list lst, partition the list into three parts.

//The first part contains all elemenets in lst that are less than x
//The first part contains all elemenets in lst that are equal to x
//The first part contains all elemenets in lst that are larger than x
//Ordering within a part can be arbitrary.
//For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14]

//similar partition question leetcode 86

#include <iostream>
#include <vector>

void partitionList(std::vector<int>& nums, int x){
    /*
    int left=0, right = nums.size()-1;
    int firstIndexGreaterX;

    //move all x to the end of list
    while(left<right){
        if(nums[right] == x){
            right--;
        }
        if(nums[left] != x){
            left++;
        }

        if(left<right && nums[left] == x && nums[right] !=x){
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    //partition subarray before x
    left = 0;
    right = nums[right]==x? right-1:right;

    while(left<right){
        if(nums[left] < x){
            left++;
        }
        if(nums[right] > x){
            right--;
        }

        if(left<right && nums[left] > x && nums[right] < x){
            std::swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    if(nums[left] < x){
        firstIndexGreaterX = left+1;
    }
    else{
        firstIndexGreaterX = left;
    }

    //swap all x
    right = nums.size()-1;
    while(firstIndexGreaterX<right){
        std::swap(nums[firstIndexGreaterX], nums[right]);
        firstIndexGreaterX++;
        right--;
    }
    */

    //more effecient approach
    //only one loop
    int firstEnd=0; //it could be end of first partition or start of second partition(first 10)
    int thirdStart=0;
    bool thirdStartExist = false;
    for(int i=0; i<nums.size(); i++){

        if(nums[i] < x){
            if(nums[firstEnd] != x){
                firstEnd = i;
            }
            if(nums[firstEnd] == x){
                std::swap(nums[firstEnd], nums[i]); //swap smaller element with first x
                if(i == nums.size()-1){// return if it is the last element, otherwise {10,10,2} will fail by output:{10,2,10}
                    return;
                }
                if(nums[firstEnd+1] == x){ //if next one is x, then move firstEnd to the first x
                    firstEnd++;
                }
            }
        }

        if(nums[i] > x && thirdStartExist == false){ //if thirdStart havent been set, in case the first element is thirdStart
            thirdStart = i;
            thirdStartExist = true;
        }

        if(firstEnd > thirdStart){ //only happens when there is no x in front of thirdStart, and a new smaller found
            std::swap(nums[firstEnd], nums[thirdStart]);
            int temp = firstEnd;
            firstEnd = thirdStart;
            thirdStart++;
        }

        if(nums[thirdStart] > x && nums[i] == x){ //make sure thirdStart is not at the initial 0 state
            std::swap(nums[thirdStart], nums[i]);
            if(nums[thirdStart-1] != x){ // mark the first x as the firstEnd (for later swapping smaller element with x)
                firstEnd = thirdStart;
            }
            thirdStart++;
        }
    }

}

int main(){
    //std::vector<int> nums = {9, 14, 10};
    //std::vector<int> nums = {14, 10};
    //std::vector<int> nums = {15, 9, 14, 10, 5, 10, 2, 10, 10, 10, 10};
    //std::vector<int> nums = {15, 9, 14, 2, 5};
    std::vector<int> nums = {10, 10, 15, 2, 10};
    partitionList(nums, 10);

    for(int i=0; i<nums.size(); i++){
        std::cout << nums[i] << std::endl;
    }

    return 0;
}