//Find subarray with given sum (Nonnegative Numbers)
//Given an unsorted array of nonnegative integers, 
//find a continous subarray which adds to a given number.

#include <iostream>
#include <vector>

using namespace std;

vector<int> subArraySum(vector<int>& nums, int sum){
    
    vector<int> result;
    int current_sum = nums[0], start = 0;
    int end;
    bool exist = false;

    if(nums.size()==0) return result;

    if(current_sum == sum){
        result.push_back(nums[0]);
        return result;
    }

    for(int i=1; i<nums.size(); i++){
        
        current_sum = current_sum + nums[i];

        //cout << current_sum << endl;
        while(current_sum > sum && start < i){
            current_sum = current_sum - nums[start];
            start++;
        }

        if(current_sum == sum){
            end = i;
            exist = true;
            break;
        }

    }

    if(exist == true){
        for(int i=start; i<=end; i++){
            result.push_back(nums[i]);
        }
    }

    return result;
}

int main(){

    vector<int> nums, res;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(16);
    nums.push_back(7);
    res = subArraySum(nums, 33);

    for(int i=0; i<res.size(); i++){
        cout << res[i] << endl;
    }

}