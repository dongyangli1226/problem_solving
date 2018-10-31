// 3 Sum

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {

    sort(nums.begin(), nums.end());
 
    vector<vector<int>> result;
    vector<int> two(3);
    int sum;

    for(int i=0; i<nums.size(); i++){
        if(i>=1 && nums[i] == nums[i-1]){
            continue;
        }
        int left = i+1;
        int right = nums.size()-1;
        while(left < right){
            sum = nums[i] + nums[left] + nums[right];
            if(sum < 0){
                left++;
            }
            else if(sum > 0){
                right--;
            }
            else{
                two[0] = (nums[i]);
                two[1] = (nums[left]);
                two[2] = (nums[right]);
                result.push_back(two);

                while (left<right && nums[left]==nums[left+1]){
                    left++;
                }
                while (left<right && nums[right]==nums[right-1]){
                    right--;
                }
                left++;
                right--;
            }

        }
    }

    return result;
}

int main(){
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);

    vector<vector<int>> res = threeSum(nums);
    for(int i=0; i<res.size(); i++){
        cout << res[i][0] << ',' << res[i][1] << ',' << res[i][2] << endl;
    }
}