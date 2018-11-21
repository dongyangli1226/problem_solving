//trapping rain water
//given non-negative integers representing an elevation map where the width of each bar is 1
//compute how much water it is able to trap after raining

#include <iostream>
#include <vector>


//Approach 1
//use two arrays to store each bar's left highest and right highest heights
//O(n) time , O(n) Space
int trap(std::vector<int>& height){
    if(height.size() == 0){
        return 0;
    }
    
    std::vector<int> left(height.size());
    std::vector<int> right(height.size());


    left[0] = height[0];
    for(int i=1; i<height.size(); i++){
        left[i] = std::max(left[i-1], height[i]);
    }

    right[height.size()-1] = height[height.size()-1];
    for(int i=height.size()-2; i>0; i--){
        right[i] = std::max(right[i+1], height[i]);
    }

    int totalWater = 0;
    for(int i=1; i<height.size(); i++){
        totalWater += std::min(left[i], right[i]) - height[i];
    }

    return totalWater;
}

//Approach 2
//
//O(n) time, O(1) Space

int trap2(std::vector<int>& height){
    int low = 0;
    int high = height.size()-1;
    int leftMax = 0;
    int rightMax = 0;
    int result = 0;

    while(low <= high){
        if(height[low] < height[high]){
            if(height[low] > leftMax){
                leftMax = height[low];
            }
            else{
                result += leftMax - height[low];
            }
            low++;
        }
        else{
            if(height[high] > rightMax){
                rightMax = height[high];
            }
            else{
                result += rightMax - height[high];
            }
            high--;
        }
    }

    return result;
}