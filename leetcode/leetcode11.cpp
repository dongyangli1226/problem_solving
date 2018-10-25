//container with most water

//from widest container
// narrow inside to find higher container (because less wide)
// skip not higher ones
// compare higher ones with the widest

#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int max_container = 0;
    int left = 0, right = height.size() - 1;

    while (left < right){
        int new_height = min(height[left], height[right]);
        
        /*
        int new_container = new_height * (right - left);

        if(new_container > max_container){
            max_container = new_container;
        }

        */

        //faster:
        max_container = max(max_container, new_height*(right-left));

        //skip lower container
        while(height[left] <= new_height && left<right){
            left++;
        }

        while(height[right] <= new_height && left<right){
            right--;
        }
    }

    return max_container;
}