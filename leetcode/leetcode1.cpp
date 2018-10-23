#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> map;
    vector<int> result;

    for(int i=0; i<nums.size(); i++){
        int n = target - nums[i];

        if(map.find(n) != map.end()){
            result.push_back(map[n]);
            result.push_back(i);
        }

        map[nums[i]] = i;
    }
    return result;
}

int main(){

    cout << "testing" << endl;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(9);

    int target = 6;

    vector<int> res = twoSum(nums, target);
    cout << "result: " << res[0] << ", " << res[1] << endl;

}