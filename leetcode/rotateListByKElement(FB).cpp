//array rotation

//similar to leetcode189, rotate by k steps

//Write a function that rotates a list by k elements.
//For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2].
//Try solving this without creating a copy of the list.
//How many swap or move operations do you need?



#include <iostream>
#include <vector>

using namespace std;
 
//method1 reverse first k and revers size-k, then reverse the whole array
// 12345 k=2 -> 21543 -> 34512
void reverse(vector<int>& nums, int start, int end){
    int temp = start;
    for(int i=start; i<end; i++){
        nums[i] = nums[i+1];
    }
}

void rotateListByK(vector<int>& nums, int n){

}
