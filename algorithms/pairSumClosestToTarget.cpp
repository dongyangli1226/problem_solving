//sorted array, find a pair whose sum is closest to target x

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

std::pair<int, int> closestPair(std::vector<int> arr, int target){
    int result_left, result_right;
    int left = 0, right = arr.size()-1, diff = INT_MAX;

    while(left < right){
        if(abs(arr[left] + arr[right] - target) < diff){
            result_left = left;
            result_right = right;
            diff = abs(arr[left] + arr[right] - target);
        }

        if(arr[left] + arr[right] > target){
            right--;
        }
        else{
            left++;
        }
    }

    std::pair<int, int> result_pair = std::make_pair(arr[result_left], arr[result_right]);
    return result_pair;
}

int main(){
    std::vector<int> arr = {10, 22, 28, 29, 30, 40};
    int target = 54;

    std::pair<int,int> p = closestPair(arr, target);
    std::cout << p.first << " " << p.second << std::endl;
}