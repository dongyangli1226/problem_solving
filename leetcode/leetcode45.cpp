//jump Game II
//given an non-negative integer array, you are initially positioned at the first index of array
//each element in the array represents your maximum jup length at that position
//find the minimum number of jumps to the last index

#include <iostream>
#include <vector>

//BFS structure
//example : 2,3,1,1,4
//level 1 : 2
//level 2 : 3, 1 (where we can jump to from level 1)
//level 3 : 1, 4 (where we can jump to from level 2)
//thus minimum number of jumps is 2

int jump(std::vector<int>& nums){
    if(nums.size() == 0 || nums.size() == 1){
        return 0;
    }

    int levelCount = 0;
    int currentMax = 0;
    int nextMax = 0;
    int i=0;
    
    while(currentMax - i + 1 > 0){ //number of nodes at the level, if it goes to zero, then we can't reach the last index
        levelCount++;
        for(; i<=currentMax; i++){
            nextMax = std::max(nextMax, nums[i]+i);
            if(nextMax > nums.size()-1){
                return levelCount;
            }
        }
        currentMax = nextMax;
    }

    return 0;
}

//Approach 2

int jump(std::vector<int>& nums){
    int n = nums.size();
    if(n == 0 || n == 1){
        return 0;
    }

    int currentMax = nums[0];
    int nextMax = nums[0];
    int jumpCount = 1;

    for(int i=1; i<std::min(n, nextMax); i++){ //the min will handle the case in which we can't reach to the last index

        nextMax = std::max(nextMax, nums[i]+i);
        
        if(i == n-1){
            return jumpCount;
        }

        if(i == currentMax){
            currentMax = nextMax;
            jumpCount++;
        }
    }

    return 0;
}