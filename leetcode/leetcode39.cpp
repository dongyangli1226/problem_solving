//combination sum
//DFS

#include <vector>
#include <algorithm>

std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    
    std::sort(candidates.begin(), candidates.end()); //reduce loop count
    std::vector<int> combination;
    std::vector<std::vector<int>> result;
    calculateCombination(candidates, target, result, combination, 0);
    return result;
}

// param int begin is used to avoid duplicate
void calculateCombination(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& result, std::vector<int>& combination, int start)
{
    if(target == 0){
        result.push_back(combination);
        return;
    }

    for(int i=start; i<candidates.size() && target >= candidates[i]; i++){
        combination.push_back(candidates[i]);
        calculateCombination(candidates, target-candidates[i], result, combination, i);
        //clear combination
        combination.pop_back();
    }

}
